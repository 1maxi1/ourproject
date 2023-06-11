/********************************************************************************
** Form generated from reading UI file 'dialogresults.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRESULTS_H
#define UI_DIALOGRESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DialogResults
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonReload;
    QTextBrowser *textBrowserResults;

    void setupUi(QDialog *DialogResults)
    {
        if (DialogResults->objectName().isEmpty())
            DialogResults->setObjectName("DialogResults");
        DialogResults->resize(570, 485);
        gridLayout = new QGridLayout(DialogResults);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(377, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label = new QLabel(DialogResults);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButtonClose = new QPushButton(DialogResults);
        pushButtonClose->setObjectName("pushButtonClose");

        gridLayout->addWidget(pushButtonClose, 2, 1, 1, 1);

        pushButtonReload = new QPushButton(DialogResults);
        pushButtonReload->setObjectName("pushButtonReload");

        gridLayout->addWidget(pushButtonReload, 2, 2, 1, 1);

        textBrowserResults = new QTextBrowser(DialogResults);
        textBrowserResults->setObjectName("textBrowserResults");
        QFont font1;
        font1.setPointSize(12);
        textBrowserResults->setFont(font1);

        gridLayout->addWidget(textBrowserResults, 1, 0, 1, 3);


        retranslateUi(DialogResults);

        pushButtonReload->setDefault(true);


        QMetaObject::connectSlotsByName(DialogResults);
    } // setupUi

    void retranslateUi(QDialog *DialogResults)
    {
        DialogResults->setWindowTitle(QCoreApplication::translate("DialogResults", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("DialogResults", "123", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("DialogResults", "\320\241\320\262\320\276\320\264\320\275\320\260\321\217 \321\202\320\260\320\261\320\273\320\270\321\206\320\260 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("DialogResults", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        pushButtonReload->setText(QCoreApplication::translate("DialogResults", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        textBrowserResults->setDocumentTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogResults: public Ui_DialogResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRESULTS_H
