#include "dialogtask.h"
#include "ui_dialogtask.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QStringList>

#include "singleton.h"
#include <QMessageBox>

DialogTask::DialogTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTask)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->buttonOk, SIGNAL(clicked()), this, SLOT(onAnswer()));

    srand (time(NULL));
}

DialogTask::~DialogTask()
{
    delete ui;
}

void DialogTask::onOpen(QString name, QString body)
{
    m_taskName = name;
    m_taskBody = body;

    m_listInputVector.clear();
    int digitsCount = 3 + (rand() % 3);

    while(m_listInputVector.length() < digitsCount)
    {
        int val = rand() % 8;

        if(!m_listInputVector.contains(val)) {
            m_listInputVector.push_back(val);
            m_taskBody += QString::number(val) + " ";
        }
    }

    ui->textBrowserTask->setText(m_taskBody);
    ui->textEditSolution->clear();
    show();
}

void DialogTask::onAnswer()
{
    qDebug() << ui->textEditSolution->toPlainText();

    QString strVector;
    for(int i = 0; i < m_listInputVector.length(); i++)
    {
        strVector += QString::number(m_listInputVector[i]);
        if(i < m_listInputVector.length() - 1) strVector += ":";
    }

    QString answer = ui->textEditSolution->toPlainText();
    if((m_taskName == "task2" || m_taskName == "task3" || m_taskName == "task4") && (answer != "0" && answer != "1"))
    {
        QMessageBox msgBox;
        msgBox.setText("Правильно введите данные");
        msgBox.exec();
        return;
    }

    singleton::getInstance()->sendMessage("answer", (m_taskName + ";" + ui->textEditSolution->toPlainText() + ";" + strVector));
}







