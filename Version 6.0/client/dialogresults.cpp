#include "dialogresults.h"
#include "ui_dialogresults.h"

#include "singleton.h"
#include <QStringList>
#include <QByteArray>

DialogResults::DialogResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResults)
{
    ui->setupUi(this);

    setWindowTitle("Таблица результатов");
}

DialogResults::~DialogResults()
{
    delete ui;
}

void DialogResults::onOpen()
{
    ui->textBrowserResults->setText("Загрузка...");
    singleton::getInstance()->sendMessage("get_stat", "");
    show();
}

void DialogResults::onStatInput(QString stat)
{
    QStringList list = stat.split(";");
    QString stringToShow;

    for(int i = 0; i < list.length(); i++)
    {
        QStringList list2 = list[i].split(":");

        qDebug() << list << list2;

        if(list2.length() != 2) continue;

        stringToShow += QString(QByteArray::fromBase64(list2[0].toUtf8()));
        stringToShow += ": ";
        stringToShow += list2[1];
        stringToShow += "<br>";
    }



    ui->textBrowserResults->setText(stringToShow);
}
