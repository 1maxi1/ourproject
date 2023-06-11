#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

/*!
\brief Класс окна авторизации пользователя
*/

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private:
    Ui::DialogLogin *ui;

public slots:

    /// слот открытия окна
    void onRegisterClicked();

    /// слот нажатия кнопки ок
    void onLogin();

signals:

    /// сигнал - открытия окна регистации
    void doRegister();
};

#endif // DIALOGLOGIN_H
