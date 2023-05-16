/********************************************************************************
** Form generated from reading UI file 'dialogtask.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTASK_H
#define UI_DIALOGTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogTask
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditSolution;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;
    QTextBrowser *textBrowserTask;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *DialogTask)
    {
        if (DialogTask->objectName().isEmpty())
            DialogTask->setObjectName("DialogTask");
        DialogTask->resize(492, 348);
        gridLayout = new QGridLayout(DialogTask);
        gridLayout->setObjectName("gridLayout");
        textEditSolution = new QTextEdit(DialogTask);
        textEditSolution->setObjectName("textEditSolution");

        gridLayout->addWidget(textEditSolution, 3, 0, 1, 2);

        buttonOk = new QPushButton(DialogTask);
        buttonOk->setObjectName("buttonOk");

        gridLayout->addWidget(buttonOk, 4, 1, 1, 1);

        buttonCancel = new QPushButton(DialogTask);
        buttonCancel->setObjectName("buttonCancel");

        gridLayout->addWidget(buttonCancel, 4, 0, 1, 1);

        textBrowserTask = new QTextBrowser(DialogTask);
        textBrowserTask->setObjectName("textBrowserTask");

        gridLayout->addWidget(textBrowserTask, 1, 0, 1, 2);

        label_2 = new QLabel(DialogTask);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(DialogTask);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(DialogTask);

        QMetaObject::connectSlotsByName(DialogTask);
    } // setupUi

    void retranslateUi(QDialog *DialogTask)
    {
        DialogTask->setWindowTitle(QCoreApplication::translate("DialogTask", "\320\227\320\260\320\264\320\260\321\207\320\260", nullptr));
        buttonOk->setText(QCoreApplication::translate("DialogTask", "\320\236\321\202\320\262\320\265\321\202\320\270\321\202\321\214", nullptr));
        buttonCancel->setText(QCoreApplication::translate("DialogTask", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("DialogTask", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("DialogTask", "\320\242\320\265\320\272\321\201\321\202 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTask: public Ui_DialogTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTASK_H
