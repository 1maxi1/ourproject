#ifndef FUNCS_H
#define FUNCS_H

#include <QChar>
#include <QList>

/*!
\brief Класс решения 4 задач

Решает 4 задачи - находит двойственную функцию, определяет самодвойственность,
определяет ее линейность и монотонность.
*/

class funcs
{
private:
    QChar inverseUppercase(QChar c);

public:
    funcs();

    /// возвращяет тройки значений: 011 101 110 ...
    QList<bool> getBoolTable(QList<int> list);

    /// возвращает булеву функцию: 01101101 (всегда 8 значений)
    QList<bool> getBoolFunc(QList<int> list);

    /// возвращает СДНФ
    QString getSdnf(QList<int> list);

    /// возвращает СКНФ
    QString getSknf(QList<int> list);

    /// возвращает двойственную функцию
    QString getDvoistvFunc(QList<int> list);

    /// определяет самодвойственность
    bool isSamodvoistv(QList<int> list);

    /// преобразует массив нулей и единиц в целое число (INEGER)
    int boolToDec(QList<bool> boolList);

    /// определяет монотонность функции
    bool isMonoton(QList<int> list);

    /// строит треугольник Паскаля
    QList<QList<bool>> getTreugolnik(QList<bool> boolFunc);

    /// определяет линейность функции
    bool isLiney(QList<int> list);   // Проверка на линейность
};

#endif // FUNCS_H
