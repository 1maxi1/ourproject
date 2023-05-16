/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *buttonTask4;
    QPushButton *buttonTask2;
    QPushButton *buttonTask3;
    QPushButton *buttonTask1;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(353, 211);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        buttonTask4 = new QPushButton(centralwidget);
        buttonTask4->setObjectName("buttonTask4");

        gridLayout->addWidget(buttonTask4, 3, 0, 1, 1);

        buttonTask2 = new QPushButton(centralwidget);
        buttonTask2->setObjectName("buttonTask2");

        gridLayout->addWidget(buttonTask2, 1, 0, 1, 1);

        buttonTask3 = new QPushButton(centralwidget);
        buttonTask3->setObjectName("buttonTask3");

        gridLayout->addWidget(buttonTask3, 2, 0, 1, 1);

        buttonTask1 = new QPushButton(centralwidget);
        buttonTask1->setObjectName("buttonTask1");

        gridLayout->addWidget(buttonTask1, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 - \320\272\320\273\320\270\320\265\320\275\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\276: 0 / 0", nullptr));
        buttonTask4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 4", nullptr));
        buttonTask2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 2", nullptr));
        buttonTask3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 3", nullptr));
        buttonTask1->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\276: 0 / 0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\276: 0 / 0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\276: 0 / 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
