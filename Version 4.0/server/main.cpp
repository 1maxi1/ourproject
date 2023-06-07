#include "singleton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // проверяем, создать объект синглтона нельзя
    // singleton onject;                /* <----- ошибка */
    // singleton::getInstance();        /* <----- верно  */

    singleton::getInstance();

    return a.exec();
}
