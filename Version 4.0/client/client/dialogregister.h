#ifndef DIALOGREGISTER_H
#define DIALOGREGISTER_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogRegister;
}

class DialogRegister : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegister(QWidget *parent = nullptr);
    ~DialogRegister();

private:
    Ui::DialogRegister *ui;

public slots:
    void onOpen()
    {
        qDebug() << "REGISTER OPEN SLOT";
        show();
    }

    void onOk();


};

#endif // DIALOGREGISTER_H
