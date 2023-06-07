#ifndef FUNCS_H
#define FUNCS_H

#include <QChar>
#include <QList>

class funcs
{
private:
    QChar inverseUppercase(QChar c);

public:
    funcs();

    QList<bool> getBoolTable(QList<int> list);   // возвращяет тройки значений: 011 101 110 ...
    QList<bool> getBoolFunc(QList<int> list);    // возвращает булеву функцию: 01101101 (всегда 8 значений)
    QString getSdnf(QList<int> list);
    QString getSknf(QList<int> list);
    QString getDvoistvFunc(QList<int> list);
    bool isSamodvoistv(QList<int> list);
    int boolToDec(QList<bool> boolList);
    bool isMonoton(QList<int> list);
    QList<QList<bool>> getTreugolnik(QList<bool> boolFunc);
    bool isLiney(QList<int> list);   // Проверка на линейность
};

#endif // FUNCS_H
