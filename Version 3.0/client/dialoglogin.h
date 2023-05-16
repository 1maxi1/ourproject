#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = nullptr);
    ~DialogLogin();

private:
    Ui::DialogLogin *ui;

public slots:
    void onRegisterClicked();
    void onLogin();

signals:
    void doRegister();
};

#endif // DIALOGLOGIN_H
