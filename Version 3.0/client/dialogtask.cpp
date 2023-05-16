#include "dialogtask.h"
#include "ui_dialogtask.h"

DialogTask::DialogTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTask)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(hide()));
    //connect(ui->buttonOk, SIGNAL(clicked()), this, SLOT(hide()));
}

DialogTask::~DialogTask()
{
    delete ui;
}

void DialogTask::onOpen(QString name, QString body)
{
    m_taskName = name;
    m_taskBody = body;

    ui->textBrowserTask->setText(m_taskBody);

    show();
}
