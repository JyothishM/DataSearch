/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Sat Oct 27 03:20:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblSoftwareName;
    QLabel *lblVismayalogo;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 300);
        gridLayout = new QGridLayout(AboutDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblSoftwareName = new QLabel(AboutDialog);
        lblSoftwareName->setObjectName(QString::fromUtf8("lblSoftwareName"));
        lblSoftwareName->setTextFormat(Qt::RichText);
        lblSoftwareName->setScaledContents(false);

        gridLayout->addWidget(lblSoftwareName, 0, 0, 1, 1);

        lblVismayalogo = new QLabel(AboutDialog);
        lblVismayalogo->setObjectName(QString::fromUtf8("lblVismayalogo"));
        lblVismayalogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/icons/vismayalogo.jpg")));

        gridLayout->addWidget(lblVismayalogo, 1, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        btnOk = new QPushButton(AboutDialog);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 2, 1, 1, 1);


        retranslateUi(AboutDialog);
        QObject::connect(btnOk, SIGNAL(clicked()), AboutDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lblSoftwareName->setText(QApplication::translate("AboutDialog", "Data Searcher   1.0.0", 0, QApplication::UnicodeUTF8));
        lblVismayalogo->setText(QString());
        btnOk->setText(QApplication::translate("AboutDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
