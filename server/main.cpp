#include "singleton.h"

#include <QApplication>

/**
    \file
    @brief Главная функция, точка входа программы

    Создает синглтон и главное окно. Открывает главное окно
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // проверяем, создать объект синглтона нельзя
    // singleton onject;                /* <----- ошибка */
    // singleton::getInstance();        /* <----- верно  */

    singleton::getInstance();

    return a.exec();
}
