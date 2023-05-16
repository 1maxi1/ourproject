#include "mainwindow.h"
#include "dialoglogin.h"
#include "dialogregister.h"
#include "dialogtask.h"

#include <QApplication>
#include <QObject>
#include "singleton.h"

#include <string>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    DialogLogin loginDialog;
    DialogRegister registerDialog;
    DialogTask dialogTask;

    // Нажали кнопку зарегистрироваться
    QObject::connect(&loginDialog, &DialogLogin::doRegister, &registerDialog, &DialogRegister::onOpen);

    // Авторизация прошла успешно
    QObject::connect(singleton::getInstance(), &singleton::authOk, &w, &MainWindow::onOpen);
    QObject::connect(singleton::getInstance(), &singleton::authOk, &loginDialog, &DialogLogin::hide);

    // Регистрация прошла успешно
    QObject::connect(singleton::getInstance(), &singleton::registerOk, &w, &MainWindow::onOpen);
    QObject::connect(singleton::getInstance(), &singleton::registerOk, &registerDialog, &DialogRegister::hide);

    // Выбрали задачу

    QObject::connect(&w, &MainWindow::signalOpenTask, &dialogTask, &DialogTask::onOpen);


    // показываем диалог логина
    loginDialog.show();

    // вызываем первый раз singleton::getInstance(), чтобы создать экземпляр синглтона
    singleton::getInstance();

    return a.exec();
}







