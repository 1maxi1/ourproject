#include "dialogregister.h"
#include "ui_dialogregister.h"
#include "singleton.h"

#include <QMessageBox>

DialogRegister::DialogRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegister)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->buttonOk, SIGNAL(clicked()), this, SLOT(onOk()));
}

DialogRegister::~DialogRegister()
{
    delete ui;
}

void DialogRegister::onOk()
{
    qDebug() << "register ok";

    QString login = ui->editLogin->displayText();
    QString password = ui->editPassword->displayText();
    QString email = ui->editEmail->displayText();

    QString err;

    if(email.isEmpty()) err = "Введите e-mail";
    if(password.isEmpty()) err = "Введите пароль";
    if(login.isEmpty()) err = "Введите логин";

    if(!err.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText(err);
        msgBox.exec();
        return;
    }

    login = QString(login.toUtf8().toBase64());
    password = QString(password.toUtf8().toBase64());
    email = QString(email.toUtf8().toBase64());

    qDebug() << login << password << email;

    singleton::getInstance()->sendMessage("register", (login + ";" + password + ";" + email));
}










