#ifndef DIALOGREGISTER_H
#define DIALOGREGISTER_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogRegister;
}

/*!
\brief Класс окна регистрации пользователя
*/
class DialogRegister : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegister(QWidget *parent = nullptr);
    ~DialogRegister();

private:
    Ui::DialogRegister *ui;

public slots:

    /// слот открытия окна
    void onOpen()
    {
        qDebug() << "REGISTER OPEN SLOT";
        show();
    }

    /// слот нажатия кнопки ок
    void onOk();
};

#endif // DIALOGREGISTER_H
