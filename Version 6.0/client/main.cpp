#include "mainwindow.h"
#include "dialoglogin.h"
#include "dialogregister.h"
#include "dialogtask.h"
#include "dialogresults.h"

#include <QApplication>
#include <QObject>
#include <QVector>
#include "singleton.h"

#include <string>
#include <iostream>

/// \file

/**
    @brief Главная функция, точка входа программы

    Создает синглтон и окна и делает связи между ними при помощи функции connect
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    DialogLogin loginDialog;
    DialogRegister registerDialog;
    DialogTask dialogTask;
    DialogResults dialogResults;

    /// \details Подробное описание
    QObject::connect(&loginDialog, &DialogLogin::doRegister, &registerDialog, &DialogRegister::onOpen); ///< Нажали кнопку зарегистрироваться

    // Авторизация прошла успешно
    QObject::connect(singleton::getInstance(), &singleton::authOk, &w, &MainWindow::onOpen);
    QObject::connect(singleton::getInstance(), &singleton::authOk, &loginDialog, &DialogLogin::hide);

    QObject::connect(&w, &MainWindow::openStat, &dialogResults, &DialogResults::onOpen);

    QObject::connect(singleton::getInstance(), &singleton::statIncoming, &dialogResults, &DialogResults::onStatInput);

    // Регистрация прошла успешно
    QObject::connect(singleton::getInstance(), &singleton::registerOk, &w, &MainWindow::onOpen);
    QObject::connect(singleton::getInstance(), &singleton::registerOk, &registerDialog, &DialogRegister::hide);

    // Выбрали задачу

    QObject::connect(&w, &MainWindow::signalOpenTask, &dialogTask, &DialogTask::onOpen);

    // Сервер принял ответ

    QObject::connect(singleton::getInstance(), &singleton::ansReply, &dialogTask, &DialogTask::hide);

    // Пришли баллы

    QObject::connect(singleton::getInstance(), &singleton::tasksBalls, &w, &MainWindow::redrawBalls);

    // показываем диалог логина
    loginDialog.show();

    // вызываем первый раз singleton::getInstance(), чтобы создать экземпляр синглтона
    singleton::getInstance();

    return a.exec();
}







