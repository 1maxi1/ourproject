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
    QLabel *labelBallTask3;
    QPushButton *buttonTask4;
    QPushButton *buttonTask1;
    QPushButton *buttonTask3;
    QPushButton *buttonTask2;
    QLabel *labelBallTask1;
    QLabel *labelBallTask4;
    QLabel *labelBallTask2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(353, 211);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        labelBallTask3 = new QLabel(centralwidget);
        labelBallTask3->setObjectName("labelBallTask3");

        gridLayout->addWidget(labelBallTask3, 2, 1, 1, 1);

        buttonTask4 = new QPushButton(centralwidget);
        buttonTask4->setObjectName("buttonTask4");

        gridLayout->addWidget(buttonTask4, 3, 0, 1, 1);

        buttonTask1 = new QPushButton(centralwidget);
        buttonTask1->setObjectName("buttonTask1");

        gridLayout->addWidget(buttonTask1, 0, 0, 1, 1);

        buttonTask3 = new QPushButton(centralwidget);
        buttonTask3->setObjectName("buttonTask3");

        gridLayout->addWidget(buttonTask3, 2, 0, 1, 1);

        buttonTask2 = new QPushButton(centralwidget);
        buttonTask2->setObjectName("buttonTask2");

        gridLayout->addWidget(buttonTask2, 1, 0, 1, 1);

        labelBallTask1 = new QLabel(centralwidget);
        labelBallTask1->setObjectName("labelBallTask1");

        gridLayout->addWidget(labelBallTask1, 0, 1, 1, 1);

        labelBallTask4 = new QLabel(centralwidget);
        labelBallTask4->setObjectName("labelBallTask4");

        gridLayout->addWidget(labelBallTask4, 3, 1, 1, 1);

        labelBallTask2 = new QLabel(centralwidget);
        labelBallTask2->setObjectName("labelBallTask2");

        gridLayout->addWidget(labelBallTask2, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 - \320\272\320\273\320\270\320\265\320\275\321\202", nullptr));
        labelBallTask3->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\273\320\273\321\213: 0", nullptr));
        buttonTask4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 4", nullptr));
        buttonTask1->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 1", nullptr));
        buttonTask3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 3", nullptr));
        buttonTask2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 2", nullptr));
        labelBallTask1->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\273\320\273\321\213: 0", nullptr));
        labelBallTask4->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\273\320\273\321\213: 0", nullptr));
        labelBallTask2->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\273\320\273\321\213: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
