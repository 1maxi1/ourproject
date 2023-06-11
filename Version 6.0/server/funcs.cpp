#include "funcs.h"
#include <QDebug>

funcs::funcs()
{
}

QChar funcs::inverseUppercase(QChar c)
{
    QChar res = c;
    if(c == 'x') res = 'X';
    else if(c == 'y') res = 'Y';
    else if(c == 'z') res = 'Z';
    else if(c == 'X') res = 'x';
    else if(c == 'Y') res = 'y';
    else if(c == 'Z') res = 'z';
    return res;
}

QList<bool> funcs::getBoolTable(QList<int> list)   // возвращяет тройки значений: 011 101 110 ...
{
    QList<bool> boolList;

    for(int i = 0; i < list.length(); i++)
    {
        int curValue = list.at(i);

        if(curValue > 7)
        {
            qDebug() << "Wrong input data";
            boolList.clear();
            return boolList;
        }

        boolList += (curValue & (0b100));
        boolList += (curValue & (0b010));
        boolList += (curValue & (0b001));
    }
    return boolList;
}

QList<bool> funcs::getBoolFunc(QList<int> list)    // возвращает булеву функцию: 01101101 (всегда 8 значений)
{
    QList<bool> boolFunc;

    for(int i = 0; i <= 7; i++)
    {
        boolFunc << (list.indexOf(i) >= 0);
    }
    return boolFunc;
}

QString funcs::getSdnf(QList<int> list)
{
    QList<bool> boolTable = getBoolTable(list);
    QString sdnf;

    for(int i = 0; i < boolTable.length(); i += 3)
    {
        for(int k = 0; k < 3; k++)
        {
            switch (k)
            {
                case 0: sdnf += boolTable[i + k] ? "x" : "X"; break;
                case 1: sdnf += boolTable[i + k] ? "y" : "Y"; break;
                case 2: sdnf += boolTable[i + k] ? "z" : "Z"; break;
            }
        }
        if(i < boolTable.length() - 3) sdnf += " v ";
    }

    return sdnf;
}

QString funcs::getSknf(QList<int> list)
{
    QString sknf;

    for(int i = 0; i <= 7; i++)
    {
        if(list.contains(i)) continue;
        int curValue = i;

        QString sdnfChunk;
        sdnfChunk += "(";
        sdnfChunk += ((curValue & (0b100)) ? "x" : "X");
        sdnfChunk += "v";
        sdnfChunk += ((curValue & (0b010)) ? "y" : "Y");
        sdnfChunk += "v";
        sdnfChunk += ((curValue & (0b001)) ? "z" : "Z");
        sdnfChunk += ")";
        sknf += sdnfChunk;

        if(i < list.length() - 1) sknf += "";
    }

    return sknf;
}

QString funcs::getDvoistvFunc(QList<int> list)
{
    QString sknf = getSknf(list);

    QString tempStr;

    for(int i = 0; i < sknf.length(); i++)
    {
        tempStr += inverseUppercase(sknf.at(i));
    }

    tempStr = tempStr.replace(")(", ")v(");

    bool flagInner = false;
    QString result;

    for(int i = 0; i < tempStr.length(); i++)
    {
        if(tempStr.at(i) == '(') {
            flagInner = true;
            continue;
        }

        QChar newC = inverseUppercase(tempStr.at(i));
        if(newC == 'v') continue;

        if(tempStr.at(i) == ')') {
            flagInner = true;
            if(i < tempStr.length() - 1) result += " v ";
            continue;
        }

        result += newC;
    }

    return result;
}

bool funcs::isSamodvoistv(QList<int> list)
{
    QString dvoistvFunc = getDvoistvFunc(list);
    QString sdnf = getSdnf(list);

    if(dvoistvFunc == sdnf) return true;

    QList<QString> listDvoistv = dvoistvFunc.split(" v ");
    QList<QString> listSdnf = sdnf.split(" v ");

    if(listSdnf.length() != listDvoistv.length()) return false;

    int count = 0;

    for(int i = 0; i < listDvoistv.length(); i++)
    {
        if(listSdnf.indexOf(listDvoistv.at(i)) >= 0) count++;
    }

    if(count == listDvoistv.length()) return true;
    return false;
}

int funcs::boolToDec(QList<bool> boolList)  // преобразует массив нулей и единиц в число
{
    int res = 0;
    int m = 1;

    for(int i = boolList.length() - 1; i >= 0; i--)
    {
        if(boolList[i]) res = res | m;
        m<<=1;
    }

    return res;
}

bool funcs::isMonoton(QList<int> list)
{
    QList<bool> boolFunc = getBoolFunc(list);

    // половинки

    if(boolToDec(boolFunc.mid(0, 4)) > boolToDec(boolFunc.mid(4, 4))) return false;

    // четвекртинки

    if(boolToDec(boolFunc.mid(0, 2)) > boolToDec(boolFunc.mid(2, 2))) return false;
    if(boolToDec(boolFunc.mid(4, 2)) > boolToDec(boolFunc.mid(6, 2))) return false;

    // осьмушки

    if(boolToDec(boolFunc.mid(0, 1)) > boolToDec(boolFunc.mid(1, 1))) return false;
    if(boolToDec(boolFunc.mid(2, 1)) > boolToDec(boolFunc.mid(3, 1))) return false;
    if(boolToDec(boolFunc.mid(4, 1)) > boolToDec(boolFunc.mid(5, 1))) return false;
    if(boolToDec(boolFunc.mid(6, 1)) > boolToDec(boolFunc.mid(7, 1))) return false;

    return true;
}

QList<QList<bool>> funcs::getTreugolnik(QList<bool> boolFunc)
{
    QList<QList<bool>> listResult;
    QList<bool> tempList = boolFunc;

    listResult << boolFunc;

    while(true)
    {
        QList<bool> tempList2;

        for(int i = 0; i < tempList.length() - 1; i++)
        {
            // Дизъюнкция строго-разделительная, сложение по модулю два

            if(tempList[i] && tempList[i + 1]) tempList2 << false;
            else if(!tempList[i] && !tempList[i + 1]) tempList2 << false;
            else if(tempList[i] || tempList[i + 1]) tempList2 << true;
        }

        listResult << tempList2;
        tempList = tempList2;
        if(tempList.length() == 1) break;
    }


    return listResult;
}

bool funcs::isLiney(QList<int> list)   // Проверка на линейность
{
    bool resultIsLiney = true;

    qDebug() << "=============== провекрка на линейность ===============";

    QList<bool> boolFunc = getBoolFunc(list);

    QList<QList<bool>> tre = getTreugolnik(boolFunc);   // "Треугольник Жегалкина"

    QString offset = "";
    QString bokTreugolnika;

    qDebug() << "Треугольник Жегалкина";

    for(int i = 0; i < tre.length(); i++)
    {
        bokTreugolnika += (tre[i][0] ? "1" : "0");

        QString str;
        for(int k = 0; k < tre.at(i).length(); k++)
        {
            str += (tre.at(i).at(k) ? "1 " : "0 ");
        }

        offset += " ";
        qDebug() << offset + str;
    }

    qDebug() << "Бок треугольника" << bokTreugolnika;

    for(int i = 0; i <= 7; i++)
    {
        QString res;
        res += QString::number(i) + " --> ";
        res += QString::number(i, 2) + " --> ";

        int numTrue = QString::number(i, 2).count("1");   // количество единиц в числе

        res += QString::number(numTrue) + " ";

        if(bokTreugolnika[i] == '1') {
            res += " <<<<< входит";

            if(numTrue > 1)
            {
                resultIsLiney = false;
                res += " (НЕ ЛИНЕЙНА)";
            }
        }
        qDebug() << res;
    }

    qDebug() << "=======================================================";
    return resultIsLiney;
}
