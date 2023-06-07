#include <QDebug>
#include <QMessageBox>

#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "singleton.h"

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);

    connect(ui->buttonGoRegister, SIGNAL(clicked()), this, SLOT(onRegisterClicked()));
    connect(ui->buttonGoRegister, SIGNAL(clicked()), this, SLOT(close()));

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->buttonOk, SIGNAL(clicked()), this, SLOT(onLogin()));
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::onRegisterClicked()
{
    emit doRegister();
}

void DialogLogin::onLogin()
{
    qDebug() << "on login";

    //singleton::getInstance()->sendMessage("login", "123");
    //qDebug() << "register ok";

    QString login = ui->editLogin->displayText();
    QString password = ui->editPassword->displayText();

    QString err;

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

    qDebug() << login << password;

    singleton::getInstance()->sendMessage("login", (login + ";" + password));
    singleton::getInstance()->setCurrentLogin(ui->editLogin->displayText(), ui->editPassword->displayText());
}

