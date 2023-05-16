#include "mainwindow.h"
#include "singleton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    w.hide();

    // проверяем, создать объект синглтона нельзя
    // singleton object;                /* <----- ошибка */
    // singleton::getInstance();        /* <----- верно  */




    singleton::getInstance();

    return a.exec();
}
