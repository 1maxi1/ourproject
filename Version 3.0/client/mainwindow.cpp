#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singleton.h"

#include <QByteArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(singleton::getInstance(), &singleton::incomingTask, this, &MainWindow::incomingTask);

    connect(ui->buttonTask1, SIGNAL(clicked()), this, SLOT(slotOpenTask()));
    connect(ui->buttonTask2, SIGNAL(clicked()), this, SLOT(slotOpenTask()));
    connect(ui->buttonTask3, SIGNAL(clicked()), this, SLOT(slotOpenTask()));
    connect(ui->buttonTask4, SIGNAL(clicked()), this, SLOT(slotOpenTask()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOpen()
{
    show();
    singleton::getInstance()->sendMessage("get_tasks", "");
    setWindowTitle("Логин: " + singleton::getInstance()->getCurrentLogin());
}

void MainWindow::incomingTask(QString name, QString body)
{
    QString nameDecoded = QString(QByteArray::fromBase64(name.toUtf8()));
    QString bodyDecoded = QString(QByteArray::fromBase64(body.toUtf8()));

    m_tasks[nameDecoded] = bodyDecoded;
}

void MainWindow::slotOpenTask()
{
    QObject *object = QObject::sender();

    if(object->objectName() == "buttonTask1")       emit signalOpenTask("task1", m_tasks["task1"]);
    else if(object->objectName() == "buttonTask2")  emit signalOpenTask("task2", m_tasks["task2"]);
    else if(object->objectName() == "buttonTask3")  emit signalOpenTask("task3", m_tasks["task3"]);
    else if(object->objectName() == "buttonTask4")  emit signalOpenTask("task4", m_tasks["task4"]);

    qDebug() << object->objectName();
}


