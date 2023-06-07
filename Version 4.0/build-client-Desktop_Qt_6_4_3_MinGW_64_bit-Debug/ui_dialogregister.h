/********************************************************************************
** Form generated from reading UI file 'dialogregister.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGREGISTER_H
#define UI_DIALOGREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogRegister
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QLineEdit *editEmail;
    QLineEdit *editPassword;
    QLineEdit *editLogin;

    void setupUi(QDialog *DialogRegister)
    {
        if (DialogRegister->objectName().isEmpty())
            DialogRegister->setObjectName("DialogRegister");
        DialogRegister->resize(304, 160);
        gridLayout = new QGridLayout(DialogRegister);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(DialogRegister);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 3, 1, 1);

        label_2 = new QLabel(DialogRegister);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(DialogRegister);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonOk = new QPushButton(DialogRegister);
        buttonOk->setObjectName("buttonOk");

        gridLayout->addWidget(buttonOk, 5, 3, 1, 1);

        buttonCancel = new QPushButton(DialogRegister);
        buttonCancel->setObjectName("buttonCancel");

        gridLayout->addWidget(buttonCancel, 5, 2, 1, 1);

        editEmail = new QLineEdit(DialogRegister);
        editEmail->setObjectName("editEmail");

        gridLayout->addWidget(editEmail, 2, 2, 1, 2);

        editPassword = new QLineEdit(DialogRegister);
        editPassword->setObjectName("editPassword");

        gridLayout->addWidget(editPassword, 1, 2, 1, 2);

        editLogin = new QLineEdit(DialogRegister);
        editLogin->setObjectName("editLogin");

        gridLayout->addWidget(editLogin, 0, 2, 1, 2);


        retranslateUi(DialogRegister);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(DialogRegister);
    } // setupUi

    void retranslateUi(QDialog *DialogRegister)
    {
        DialogRegister->setWindowTitle(QCoreApplication::translate("DialogRegister", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("DialogRegister", "e-mail", nullptr));
        label_2->setText(QCoreApplication::translate("DialogRegister", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("DialogRegister", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        buttonOk->setText(QCoreApplication::translate("DialogRegister", "OK", nullptr));
        buttonCancel->setText(QCoreApplication::translate("DialogRegister", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRegister: public Ui_DialogRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGREGISTER_H
