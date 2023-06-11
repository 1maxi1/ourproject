/********************************************************************************
** Form generated from reading UI file 'dialoglogin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOGIN_H
#define UI_DIALOGLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DialogLogin
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *editLogin;
    QLineEdit *editPassword;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonGoRegister;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DialogLogin)
    {
        if (DialogLogin->objectName().isEmpty())
            DialogLogin->setObjectName("DialogLogin");
        DialogLogin->resize(392, 181);
        gridLayout_3 = new QGridLayout(DialogLogin);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        label_2 = new QLabel(DialogLogin);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(DialogLogin);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        editLogin = new QLineEdit(DialogLogin);
        editLogin->setObjectName("editLogin");

        gridLayout_2->addWidget(editLogin, 0, 1, 1, 1);

        editPassword = new QLineEdit(DialogLogin);
        editPassword->setObjectName("editPassword");

        gridLayout_2->addWidget(editPassword, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 5);

        buttonGoRegister = new QPushButton(DialogLogin);
        buttonGoRegister->setObjectName("buttonGoRegister");

        gridLayout_3->addWidget(buttonGoRegister, 1, 0, 1, 1);

        buttonOk = new QPushButton(DialogLogin);
        buttonOk->setObjectName("buttonOk");

        gridLayout_3->addWidget(buttonOk, 1, 3, 1, 1);

        buttonCancel = new QPushButton(DialogLogin);
        buttonCancel->setObjectName("buttonCancel");

        gridLayout_3->addWidget(buttonCancel, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(DialogLogin);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(DialogLogin);
    } // setupUi

    void retranslateUi(QDialog *DialogLogin)
    {
        DialogLogin->setWindowTitle(QCoreApplication::translate("DialogLogin", "\320\222\321\205\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("DialogLogin", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("DialogLogin", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        buttonGoRegister->setText(QCoreApplication::translate("DialogLogin", "  \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217  ", nullptr));
        buttonOk->setText(QCoreApplication::translate("DialogLogin", "\320\236\320\232", nullptr));
        buttonCancel->setText(QCoreApplication::translate("DialogLogin", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLogin: public Ui_DialogLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOGIN_H
