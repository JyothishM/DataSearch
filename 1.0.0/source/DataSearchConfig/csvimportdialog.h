#ifndef CSVIMPORTDIALOG_H
#define CSVIMPORTDIALOG_H

#include <QDialog>
#include "csv/CSVcommon.h"

namespace Ui {
    class CSVimportDialog;
}

class QStandardItemModel;
class QSqlTableModel;

class CSVimportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSVimportDialog(QSqlTableModel* SqlTableModel,QWidget *parent = 0);
    ~CSVimportDialog();
private slots:
    void on_tblView_ImportedData_customContextMenuRequested(QPoint pos);
    void on_btnCSVsettings_clicked();
    void on_btnAddToTable_clicked();
    void on_btnImportCSV_clicked();
private:
    Ui::CSVimportDialog *ui;
    QStandardItemModel* mImpDataModel;
    QSqlTableModel* mSqlTableModel;
    CSVTable mCSVTable;
    QStringList mHeaders;
    QString mCSVsaporator;
    QString mCSVstringEnd;

    bool ImportData(QIODevice* iodevice);
    bool VerifyData();
    void RefreshUi();
    bool UpdateSQLTable();
    bool AddRecordToTable(int row);
};

#endif // CSVIMPORTDIALOG_H
