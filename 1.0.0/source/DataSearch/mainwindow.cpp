#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "constants.h"
#include "datasheetwindow.h"
#include "aboutdialog.h"
#include "logger.h"

#include <QLabel>
#include <QSettings>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // creating logger
    Logger* logger = new Logger(QString("%0/%1.%2").arg(LOGFOLDER_PATH)
                                .arg(QDate::currentDate().toString("yy MM dd"))
                                .arg("log"));
    Logger::SetCurLogger(logger);
    logger->SetTraceLevel((unsigned int)Logger::DEBUG);


    mStatusLabel = new QLabel(tr("Started..!"),this);
    ui->statusBar->addWidget(mStatusLabel);

    mTableModel = 0;
    bLoginStatus = false;
    on_btnLoginLogout_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    Logout();
}

void MainWindow::on_btnLoginLogout_clicked()
{
    if(!bLoginStatus)
    {
        // login
        LoginDialog mLoginDialog;
        if(Init())
        {
            if(mLoginDialog.exec())
            {
                mUserName = mLoginDialog.GetUserName();
                QString password = mLoginDialog.GetPassWord();
                bLoginStatus = Login(mUserName,password);
                if(bLoginStatus)
                {
                    mStatusLabel->setText(tr("Login succes.."));
                    ui->btnLoginLogout->setText(tr("Logout"));
                    UpdateTableUI();
                    Logger::curLog("Login succes");
                }
                else
                {
                    QMessageBox::critical(this,
                                          tr("Error..!"),
                                          tr("Login Failed"));
                    mStatusLabel->setText(tr("Login failed.."));
                    Logger::curLog(QString("Login failed , user :%0, error :%1").arg(mUserName)
                                   .arg(mDataBase.lastError().text()),Logger::ERROR);
                }
            }
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Initialisation failed, please check if the file '%0' is proper").arg(CONFIGFILE));
            Logger::curLog("Login initialisation failed",Logger::ERROR);
        }
    }
    else
    {
        // logout
        bLoginStatus = !Logout();
        if(!bLoginStatus)
        {
            mStatusLabel->setText(tr("Logout succes.."));
            ui->btnLoginLogout->setText(tr("Login"));
            UpdateTableUI();
            Logger::curLog("Logout succes");
        }
        else
        {
            mStatusLabel->setText(tr("Logout failed.."));
            Logger::curLog("Logout failed",Logger::ERROR);
        }
    }
    SetSearchVisible(bLoginStatus);
}
void MainWindow::on_btnSearch_clicked()
{
    mFilterStr = FindFilterStr();
    mTableModel->setFilter(mFilterStr);
}
void MainWindow::on_btnAllRecords_clicked()
{
    mTableModel->setFilter("");
}
void MainWindow::on_searchTableView_doubleClicked(const QModelIndex &index)
{
    if(!mTableModel)
        return;
    int row = index.row();
    if(row == -1 || !bLoginStatus)
        return;
    QSqlRecord record = mTableModel->record(row);
    DataSheetWindow* tempwindow = new DataSheetWindow(record,this);
    tempwindow->setAttribute(Qt::WA_DeleteOnClose,true);
    tempwindow->show();
}
void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutdlg(0);
    aboutdlg.exec();
}
bool MainWindow::Init()
{
    // reading from ini file
    QSettings settings(CONFIGFILE,QSettings::IniFormat);
    settings.beginGroup(STR_GROUP_DRIVER);
    mSQLdriverName = settings.value(STR_DRIVERNAME).toString();
    settings.endGroup();
    settings.beginGroup(STR_GROUP_DATABASE);
    mHostName = settings.value(STR_HOSTNAME).toString();
    mDataBaseName = settings.value(STR_DATABASENAME).toString();
    mTableName = settings.value(STR_TABLENAME).toString();
    settings.endGroup();
    settings.beginGroup(STR_GROUP_UITABLE);
    mVisibleCols = settings.value(STR_VISIBLECOLS).toString().split("|");
    settings.endGroup();

    mConditionFields.clear();
    settings.beginGroup(STR_GROUP_CONDITIONFIELDS);
    foreach(QString key,settings.childKeys())
    {
        if(!key.isEmpty())
        {
            mConditionFields.insert(key,
                                    settings.value(key).toString().trimmed());
        }
    }

    bool succes = !(mSQLdriverName.isEmpty() ||
                    mHostName.isEmpty() ||
                    mDataBaseName.isEmpty() ||
                    mTableName.isEmpty());

    mStatusLabel->setText(QString("%0,%1,%2,%3").arg(mSQLdriverName)
                          .arg(mHostName)
                          .arg(mDataBaseName)
                          .arg(mTableName));
    return succes;
}
bool MainWindow::Login(QString username, QString password)
{
    mDataBase = QSqlDatabase::addDatabase(mSQLdriverName);
    mDataBase.setHostName(mHostName);

    mDataBase.setDatabaseName(mDataBaseName);
    mDataBase.setUserName(username);
    mDataBase.setPassword(password);
    bool succes = mDataBase.open();
    if(!succes)
    {
        qCritical() << tr("Login fail :")
                << mDataBase.lastError().databaseText();
    }
    return succes;
}
bool MainWindow::Logout()
{
    mDataBase.close();
    return true;
}
void MainWindow::UpdateTableUI()
{
    if(bLoginStatus)
    {
        if(mTableModel)
            delete mTableModel;
        mTableModel = new QSqlTableModel(this,mDataBase);
        mTableModel->setTable(mTableName);
        mTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        mTableModel->setFilter(mFilterStr);
        mTableModel->select();
        ui->searchTableView->setModel(mTableModel);

        // hiding the unnessasary cols.
        int colcount = mTableModel->columnCount();
        for(int i=0; i<colcount; i++)
        {
            if(!mVisibleCols.contains(mTableModel->headerData(i,Qt::Horizontal).toString()))
                 ui->searchTableView->hideColumn(i);
        }
    }
    else
    {
        if(mTableModel)
        {
            delete mTableModel;
            mTableModel = 0;
        }
        ui->searchTableView->setModel(0);
    }
}
QString MainWindow::FindFilterStr()
{
    QString filterStr;

    // reading values.
    QString strType = GetType();
    QString strPhType = GetPhaseType();
    bool ok=false;
    double lKva = ConvToDouble(ui->edit_lKVA->text(),tr("KVA low value"),&ok);
    if(!ok)
    {
        return "";
    }
    double hKva = ConvToDouble(ui->edit_hKVA->text(),tr("KVA high value"),&ok);
    if(!ok)
    {
        return "";
    }
    double pVoltL = ConvToDouble(ui->edit_lPrimV->text(),tr("Primary voltage low value"),&ok);
    if(!ok)
    {
        return "";
    }
    double pVoltH = ConvToDouble(ui->edit_hPrimV->text(),tr("Primary voltage high value"),&ok);
    if(!ok)
    {
        return "";
    }
    double sVoltL = ConvToDouble(ui->edit_lSecV->text(),tr("Secondary voltage low value"),&ok);
    if(!ok)
    {
        return "";
    }
    double sVoltH = ConvToDouble(ui->edit_hSecV->text(),tr("Secondary voltage high value"),&ok);
    if(!ok)
    {
        return "";
    }

    // creating filter string.


    if(!strType.isEmpty())
    {
        filterStr += QString("%0 = '%1' AND ").arg(mConditionFields.value(STR_TYPE,STR_TYPE))
                .arg(strType);      //type condition
    }
    if(!strPhType.isEmpty())
    {
        filterStr += QString("%0 = %1 AND ").arg(mConditionFields.value(STR_PHASE,STR_PHASE))
                .arg(strPhType);      //phase condition
    }
    if(lKva>0)
    {
        filterStr += QString("%0 >= %1 AND ").arg(mConditionFields.value(STR_KVA,STR_KVA))
                .arg(lKva);      //KVA low condition
    }
    if(hKva>0)
    {
        filterStr += QString("%0 <= %1 AND ").arg(mConditionFields.value(STR_KVA,STR_KVA))
                .arg(hKva);      //KVA high condition
    }
    if(pVoltL>0)
    {
        filterStr += QString("%0 >= %1 AND ").arg(mConditionFields.value(STR_PRY_VOLTAGE,STR_PRY_VOLTAGE))
                .arg(pVoltL);      //Primary voltage low condition
    }
    if(pVoltH>0)
    {
        filterStr += QString("%0 <= %1 AND ").arg(mConditionFields.value(STR_PRY_VOLTAGE,STR_PRY_VOLTAGE))
                .arg(pVoltH);      //Primary voltage high condition
    }
    if(sVoltL>0)
    {
        filterStr += QString("%0 >= %1 AND ").arg(mConditionFields.value(STR_SRY_VOLTAGE,STR_SRY_VOLTAGE))
                .arg(sVoltL);      //Secondary voltage low condition
    }
    if(sVoltH>0)
    {
        filterStr += QString("%0 <= %1").arg(mConditionFields.value(STR_SRY_VOLTAGE,STR_SRY_VOLTAGE))
                .arg(sVoltH);      //Secondary voltage high condition
    }

    if(filterStr.endsWith("AND "))
        filterStr = filterStr.left(filterStr.length()-QString("AND ").length());

    return filterStr;
}
bool MainWindow::SetSearchVisible(bool visible)
{
    ui->groupSearch->setVisible(visible);
    ui->groupSearchResult->setVisible(visible);
    return true;
}
double MainWindow::ConvToDouble(QString str,QString errName, bool *ok)
{
    double value=0;
    bool succes=false;
    value = str.toDouble(&succes);
    if(!succes && !errName.isEmpty())
    {
        QMessageBox::critical(this,
                              tr("Error."),
                              tr("%0 could not be converted to a valid number").arg(errName));
    }

    if(ok)
        *ok = succes;
    return value;
}
QString MainWindow::GetType()
{
    return ui->combo_type->currentText();
}
QString MainWindow::GetPhaseType()
{
    return ui->combo_phase->currentText();
}




