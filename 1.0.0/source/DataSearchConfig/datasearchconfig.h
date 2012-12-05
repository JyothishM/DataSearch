#ifndef DATASEARCHCONFIG_H
#define DATASEARCHCONFIG_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
    class DataSearchConfig;
}

class QSqlTableModel;

class DataSearchConfig : public QDialog
{
    Q_OBJECT

public:
    explicit DataSearchConfig(QWidget *parent = 0);
    ~DataSearchConfig();
private slots:
    void on_btnImportCSV_clicked();
    void on_btn_UseTable_clicked();
    void on_btn_RefeshTableList_clicked();
    void on_btn_CreateTable_clicked();
    void on_btn_Apply_clicked();
    void on_btnGroup_Accept_accepted();
    void on_btn_CreateDsnFile_clicked();
    void on_btn_BrowseDsnFile_clicked();
    void on_btnTestConnectivity_clicked();
private:
    Ui::DataSearchConfig *ui;
    QString mDBMS;
    QString mSQLdriverName;
    QString mHostName;
    int mPort;
    QString mUserName;
    QString mPassWord;
    QString mDataBaseName;
    QString mTableName;
    QSqlDatabase mDataBase;

    void InitUi();
    void RefreshUi();
    void ReadUi();
    bool VerifyValues();
    bool ReadConfigFile();
    bool WriteConfigFile();
    bool TestConnectivity();
    void UpdateDB();
    bool RunSqlQuery(QString query);
    QString ReadFile(QString filename);
    bool CreateTable();
};

#endif // DATASEARCHCONFIG_H
