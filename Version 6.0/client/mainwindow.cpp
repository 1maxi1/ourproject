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
    delete ui;QMap<QString, QString> m_tasks;
}

void MainWindow::onOpen()
{
    if(singleton::getInstance()->getCurrentRole() == 2)     // УЧИТЕЛЬ
    {
        emit openStat();
        return;
    }

    show();
    singleton::getInstance()->sendMessage("get_tasks", "");
    singleton::getInstance()->sendMessage("get_balls", "");
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


void MainWindow::redrawBalls(QString body)
{
    QStringList list = body.split(";");

    for(int i = 0; i < list.length(); i++)
    {
        QStringList list2 = list[i].split(":");
        if(list2.length() != 2) continue;

        QString taskName = list2[0];
        QString ball = "Балл: " + list2[1];

        if(taskName == "task1")         ui->labelBallTask1->setText(ball);
        else if(taskName == "task2")    ui->labelBallTask2->setText(ball);
        else if(taskName == "task3")    ui->labelBallTask3->setText(ball);
        else if(taskName == "task4")    ui->labelBallTask4->setText(ball);
    }
}
