/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 27 03:20:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupSearch;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *edit_lSecV;
    QLabel *label_8;
    QLineEdit *edit_hSecV;
    QLabel *label_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *edit_lPrimV;
    QLabel *label_7;
    QLineEdit *edit_hPrimV;
    QLabel *label_5;
    QPushButton *btnSearch;
    QComboBox *combo_type;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edit_lKVA;
    QLabel *label_6;
    QLineEdit *edit_hKVA;
    QLabel *label_2;
    QComboBox *combo_phase;
    QPushButton *btnAllRecords;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QPushButton *btnLoginLogout;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupSearchResult;
    QGridLayout *gridLayout_3;
    QTableView *searchTableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(712, 580);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/DataSearchicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupSearch = new QGroupBox(layoutWidget);
        groupSearch->setObjectName(QString::fromUtf8("groupSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupSearch->sizePolicy().hasHeightForWidth());
        groupSearch->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupSearch);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupSearch);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        edit_lSecV = new QLineEdit(groupSearch);
        edit_lSecV->setObjectName(QString::fromUtf8("edit_lSecV"));

        horizontalLayout_3->addWidget(edit_lSecV);

        label_8 = new QLabel(groupSearch);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        edit_hSecV = new QLineEdit(groupSearch);
        edit_hSecV->setObjectName(QString::fromUtf8("edit_hSecV"));

        horizontalLayout_3->addWidget(edit_hSecV);


        gridLayout->addLayout(horizontalLayout_3, 4, 2, 1, 2);

        label_4 = new QLabel(groupSearch);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(groupSearch);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edit_lPrimV = new QLineEdit(groupSearch);
        edit_lPrimV->setObjectName(QString::fromUtf8("edit_lPrimV"));

        horizontalLayout_2->addWidget(edit_lPrimV);

        label_7 = new QLabel(groupSearch);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        edit_hPrimV = new QLineEdit(groupSearch);
        edit_hPrimV->setObjectName(QString::fromUtf8("edit_hPrimV"));

        horizontalLayout_2->addWidget(edit_hPrimV);


        gridLayout->addLayout(horizontalLayout_2, 3, 2, 1, 2);

        label_5 = new QLabel(groupSearch);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        btnSearch = new QPushButton(groupSearch);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));

        gridLayout->addWidget(btnSearch, 6, 3, 1, 1);

        combo_type = new QComboBox(groupSearch);
        combo_type->setObjectName(QString::fromUtf8("combo_type"));

        gridLayout->addWidget(combo_type, 0, 2, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edit_lKVA = new QLineEdit(groupSearch);
        edit_lKVA->setObjectName(QString::fromUtf8("edit_lKVA"));

        horizontalLayout->addWidget(edit_lKVA);

        label_6 = new QLabel(groupSearch);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        edit_hKVA = new QLineEdit(groupSearch);
        edit_hKVA->setObjectName(QString::fromUtf8("edit_hKVA"));

        horizontalLayout->addWidget(edit_hKVA);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 2);

        label_2 = new QLabel(groupSearch);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        combo_phase = new QComboBox(groupSearch);
        combo_phase->setObjectName(QString::fromUtf8("combo_phase"));

        gridLayout->addWidget(combo_phase, 2, 2, 1, 2);

        btnAllRecords = new QPushButton(groupSearch);
        btnAllRecords->setObjectName(QString::fromUtf8("btnAllRecords"));

        gridLayout->addWidget(btnAllRecords, 6, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 0, 1, 1);


        gridLayout_2->addWidget(groupSearch, 0, 0, 2, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/keltron.jpg")));

        gridLayout_2->addWidget(label_9, 0, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(48, 178, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        btnLoginLogout = new QPushButton(layoutWidget);
        btnLoginLogout->setObjectName(QString::fromUtf8("btnLoginLogout"));
        btnLoginLogout->setCheckable(false);
        btnLoginLogout->setChecked(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, btnLoginLogout);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);


        gridLayout_2->addLayout(formLayout, 1, 2, 1, 1);

        splitter->addWidget(layoutWidget);
        groupSearchResult = new QGroupBox(splitter);
        groupSearchResult->setObjectName(QString::fromUtf8("groupSearchResult"));
        gridLayout_3 = new QGridLayout(groupSearchResult);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        searchTableView = new QTableView(groupSearchResult);
        searchTableView->setObjectName(QString::fromUtf8("searchTableView"));

        gridLayout_3->addWidget(searchTableView, 0, 0, 1, 1);

        splitter->addWidget(groupSearchResult);

        gridLayout_4->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Data Searcher", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        groupSearch->setTitle(QApplication::translate("MainWindow", "Search data here..", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Phase", 0, QApplication::UnicodeUTF8));
        edit_lSecV->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "&", 0, QApplication::UnicodeUTF8));
        edit_hSecV->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Primary voltage between", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        edit_lPrimV->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "&", 0, QApplication::UnicodeUTF8));
        edit_hPrimV->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Secondary voltage between", 0, QApplication::UnicodeUTF8));
        btnSearch->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        combo_type->clear();
        combo_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choke", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Transformer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Inductor", 0, QApplication::UnicodeUTF8)
        );
        edit_lKVA->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "&", 0, QApplication::UnicodeUTF8));
        edit_hKVA->setText(QApplication::translate("MainWindow", "-1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "KVA between", 0, QApplication::UnicodeUTF8));
        combo_phase->clear();
        combo_phase->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
        );
        btnAllRecords->setText(QApplication::translate("MainWindow", "All records", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        btnLoginLogout->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        groupSearchResult->setTitle(QApplication::translate("MainWindow", "Search Results", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
