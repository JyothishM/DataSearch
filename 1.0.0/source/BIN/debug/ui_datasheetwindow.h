/********************************************************************************
** Form generated from reading UI file 'datasheetwindow.ui'
**
** Created: Sat Oct 27 03:20:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASHEETWINDOW_H
#define UI_DATASHEETWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_DataSheetWindow
{
public:
    QAction *actionPrint;
    QAction *actionPrint_to_PDF;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DataSheetWindow)
    {
        if (DataSheetWindow->objectName().isEmpty())
            DataSheetWindow->setObjectName(QString::fromUtf8("DataSheetWindow"));
        DataSheetWindow->resize(800, 600);
        actionPrint = new QAction(DataSheetWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/print.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon);
        actionPrint_to_PDF = new QAction(DataSheetWindow);
        actionPrint_to_PDF->setObjectName(QString::fromUtf8("actionPrint_to_PDF"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/printtopdf.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint_to_PDF->setIcon(icon1);
        centralwidget = new QWidget(DataSheetWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(centralwidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        DataSheetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DataSheetWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        DataSheetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DataSheetWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DataSheetWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(DataSheetWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        DataSheetWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionPrint_to_PDF);
        toolBar->addAction(actionPrint);
        toolBar->addAction(actionPrint_to_PDF);

        retranslateUi(DataSheetWindow);

        QMetaObject::connectSlotsByName(DataSheetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DataSheetWindow)
    {
        DataSheetWindow->setWindowTitle(QApplication::translate("DataSheetWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("DataSheetWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionPrint_to_PDF->setText(QApplication::translate("DataSheetWindow", "Print to PDF", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("DataSheetWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("DataSheetWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("DataSheetWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataSheetWindow: public Ui_DataSheetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASHEETWINDOW_H
