#include "datasearchconfig.h"
#include "ui_datasearchconfig.h"
#include "constants.h"
#include "csvimportdialog.h"
#include "datasearchconfig_common.h"
#include <QSettings>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QProcess>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QSqlTableModel>

DataSearchConfig::DataSearchConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataSearchConfig)
{
    ui->setupUi(this);
    InitUi();

    DSConfigLogger->Log("DataSearchConfig started",Logger::DEBUG);
}
DataSearchConfig::~DataSearchConfig()
{
    delete ui;
}

void DataSearchConfig::on_btnTestConnectivity_clicked()
{
    ReadUi();
    if(TestConnectivity())
        on_btn_RefeshTableList_clicked();
}

void DataSearchConfig::on_btn_BrowseDsnFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open DSN file"),
                                                    QDir::currentPath(),
                                                     tr("DSN files (*.dsn)"));
    if(!fileName.isEmpty())
    {
        mDataBaseName = fileName;
        RefreshUi();
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("The dsn file selected is not proper, dsn is not changed"));
    }
}

void DataSearchConfig::on_btn_CreateDsnFile_clicked()
{
#ifdef Q_OS_WIN32
    QProcess::execute("odbcad32.exe");
#else
    QMessageBox::critical(this,
                          tr("Error"),
                          tr("This feature is currently awailable only in windows"));
    return;
#endif

    if(QMessageBox::information(this,
                             tr("Instruction...!"),
                             tr("Please open the dsn file created"),
                             QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        on_btn_BrowseDsnFile_clicked();
    }
}

void DataSearchConfig::on_btnGroup_Accept_accepted()
{
    on_btn_Apply_clicked();
}

void DataSearchConfig::on_btn_Apply_clicked()
{
    ReadUi();
    if(VerifyValues())
    {
        WriteConfigFile();
    }
}

void DataSearchConfig::on_btn_CreateTable_clicked()
{
    if(CreateTable())
    {
        QMessageBox::information(this,
                                 tr("Succes"),
                                 tr("Table succesfully created"));
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Table could not be created..!"));
    }
}

void DataSearchConfig::on_btn_RefeshTableList_clicked()
{
    ui->lst_Tables->clear();
    UpdateDB();
    if(mDataBase.open())
    {
        ui->lst_Tables->addItems(mDataBase.tables());
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Could not open database"));
    }

    if(mDataBase.isOpen())
        mDataBase.close();
}


void DataSearchConfig::on_btnImportCSV_clicked()
{
    on_btnTestConnectivity_clicked();
    UpdateDB();
    if(!mDataBase.isOpen())
        mDataBase.open();

    if(mDataBase.isOpen())
    {
        QSqlTableModel TableModel(this,mDataBase);
        TableModel.setTable(mTableName);
        TableModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
        TableModel.select();
        CSVimportDialog CSVImpDialog(&TableModel,this);
        if(CSVImpDialog.exec())
        {

        }

        mDataBase.close();
    }
}

void DataSearchConfig::on_btn_UseTable_clicked()
{
    if(ui->lst_Tables->selectedItems().count())
    {
        mTableName = ui->lst_Tables->selectedItems().last()->text();
        ui->edt_Tablename->setText(mTableName);
    }
}

///////////////////////Private/////////////////////////////
void DataSearchConfig::InitUi()
{
    ui->combo_DBdriver->clear();
    ui->combo_DBdriver->addItems(QSqlDatabase::drivers());
    if(ReadConfigFile())
    {
        RefreshUi();
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Could not read config file"));
    }
}

void DataSearchConfig::RefreshUi()
{
    if(mDBMS == STR_DBMS_MYSQL)
        ui->rad_DBMS_MySql->setChecked(true);
    else
        ui->rad_DBMS_MSAcces->setChecked(true);

    int DBdrvIndex = ui->combo_DBdriver->findText(mSQLdriverName);
    if(DBdrvIndex >= 0)
        ui->combo_DBdriver->setCurrentIndex(DBdrvIndex);

    ui->edt_DBhost->setText(mHostName);
    ui->edt_DBport->setText(QString::number(mPort));

    if(mDataBaseName.endsWith(".dsn"))
    {
        ui->rad_DB_DSNfile->setChecked(true);
        ui->edt_DSNfile->setText(mDataBaseName);
    }
    else
    {
        ui->rad_DB->setChecked(true);
        ui->edt_DBname->setText(mDataBaseName);
    }

    ui->edt_Tablename->setText(mTableName);
}

void DataSearchConfig::ReadUi()
{
    if(ui->rad_DBMS_MySql->isChecked())
        mDBMS = STR_DBMS_MYSQL;
    else
        mDBMS = STR_DBMS_MSACCES;

    mSQLdriverName = ui->combo_DBdriver->currentText();
    mHostName = ui->edt_DBhost->text();
    mPort = ui->edt_DBport->text().toInt();

    if(ui->rad_DB_DSNfile->isChecked())
        mDataBaseName = ui->edt_DSNfile->text();
    else
        mDataBaseName = ui->edt_DBname->text();

    mTableName = ui->edt_Tablename->text();

    mUserName = ui->edt_Username->text();
    mPassWord = ui->edt_Password->text();
}

bool DataSearchConfig::VerifyValues()
{
    // not implimented.
    bool succes=false;

    QString errorField;
    if(mDBMS.isEmpty())
        errorField = "DBMS";
    else if(mSQLdriverName.isEmpty())
        errorField = "SQLdriverName";
    else if(mHostName.isEmpty())
        errorField = "HostName";
    else if(mPort < 0)
        errorField = "Port number";
    else if(mDataBaseName.isEmpty())
        errorField = "DataBaseName";
    else if(mTableName.isEmpty())
        errorField = "TableName";
    else if(mUserName.isEmpty())
        errorField = "UserName";
    else if(mPassWord.isEmpty())
        errorField = "PassWord";
    else
        succes = true;

    if(!succes)
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("%0 is not proper").arg(errorField));
    }
    return succes;
}

bool DataSearchConfig::ReadConfigFile()
{
    bool succes=false;

    // reading from ini file
    QSettings settings(CONFIGFILE,QSettings::IniFormat);
    settings.beginGroup(STR_GROUP_DRIVER);
    mDBMS = settings.value(STR_DBMS,STR_DBMS_MYSQL).toString();
    mSQLdriverName = settings.value(STR_DRIVERNAME).toString();
    settings.endGroup();
    settings.beginGroup(STR_GROUP_DATABASE);
    mHostName = settings.value(STR_HOSTNAME).toString();
    mPort = settings.value(STR_PORT,3306).toInt();
    mDataBaseName = settings.value(STR_DATABASENAME).toString();
    mTableName = settings.value(STR_TABLENAME).toString();
    settings.endGroup();

    succes=true;
    return succes;
}

bool DataSearchConfig::WriteConfigFile()
{
    bool succes=false;

    QSettings settings(CONFIGFILE,QSettings::IniFormat);
    settings.beginGroup(STR_GROUP_DRIVER);
    settings.setValue(STR_DBMS,mDBMS);
    settings.setValue(STR_DRIVERNAME,mSQLdriverName);
    settings.endGroup();
    settings.beginGroup(STR_GROUP_DATABASE);
    settings.setValue(STR_HOSTNAME,mHostName);
    settings.setValue(STR_PORT,QString::number(mPort));
    settings.setValue(STR_DATABASENAME,mDataBaseName);
    settings.setValue(STR_TABLENAME,mTableName);
    settings.endGroup();

    settings.sync();  // syncing database
    succes=true;
    return succes;
}

bool DataSearchConfig::TestConnectivity()
{
    bool succes=false;

    if(!VerifyValues())
        return false;

    UpdateDB();
    bool dbOpen = mDataBase.open();

    qDebug() << mSQLdriverName
            << mHostName
            << mDataBaseName
            << mUserName
            << mPassWord;

    if(dbOpen)
    {
//        QMessageBox::information(this,
//                                     tr("Succes...!"),
//                                     tr("Database succesfully opened."));

        qDebug() << "Tables :" << mDataBase.tables();

        if(mDataBase.tables().contains(mTableName,Qt::CaseInsensitive))
        {
            QMessageBox::information(this,
                                         tr("Table Exists"),
                                         tr("Table '%0' exists in database '%1'")
                                                    .arg(mTableName)
                                                    .arg(mDataBaseName));
            succes = true;
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Table not found..!"),
                                  tr("Table %0 not found in database %1\n Please create a table using 'Table' tab..!")
                                        .arg(mTableName)
                                        .arg(mDataBaseName));
        }
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Database opening failed..!"),
                              tr("Error :%0\n Please create a proper database first..!").arg(mDataBase.lastError().text()));
    }

    if(mDataBase.isOpen())
        mDataBase.close();



    return succes;
}

void DataSearchConfig::UpdateDB()
{
    mDataBase = QSqlDatabase::addDatabase(mSQLdriverName);
    mDataBase.setHostName(mHostName);
    mDataBase.setDatabaseName(mDataBaseName);
    mDataBase.setUserName(mUserName);
    mDataBase.setPassword(mPassWord);
}

bool DataSearchConfig::RunSqlQuery(QString query)
{
    bool succes=false;
    UpdateDB();
    if(mDataBase.open())
    {
        mDataBase.exec(query);
        if(mDataBase.lastError().isValid())
        {
            QMessageBox::critical(this,
                                  tr("Error in sql query"),
                                  tr("Could not excecute sql query..!"));
        }
        else
            succes = true;
    }
    return succes;
}

QString DataSearchConfig::ReadFile(QString filename)
{
    QString str;
    QFile data(filename);
    if (data.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&data);
        str = stream.readAll();
    }
    return str;
}

bool DataSearchConfig::CreateTable()
{
    ReadUi();
    bool succes=false;
    QString sqlquery = ReadFile(QString(SQL_FOLDER_PATH).append(SQL_CREATETABLE_FILE));
    sqlquery.replace("<<tablename>>",mTableName);
    if(!sqlquery.isEmpty())
    {
        succes = RunSqlQuery(sqlquery);
    }
    return succes;
}





