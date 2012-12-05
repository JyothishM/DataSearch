#include "csvimportdialog.h"
#include "ui_csvimportdialog.h"
#include "csv/csvreader.h"
#include "csvsettings.h"
#include "datasearchconfig_common.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlField>
#include <QDebug>
#include <QMenu>
#include <QAction>

CSVimportDialog::CSVimportDialog(QSqlTableModel* SqlTableModel,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVimportDialog)
{
    ui->setupUi(this);
    mSqlTableModel = SqlTableModel;
    mImpDataModel = new QStandardItemModel(this);
    ui->tblView_ImportedData->setModel(mImpDataModel);

    if(mSqlTableModel)
    {
        mSqlTableModel->select();
        ui->tblView_ActualTable->setModel(mSqlTableModel);
    }

    mCSVsaporator = ",";
    mCSVstringEnd = "\"";
    ui->tblView_ImportedData->setContextMenuPolicy(Qt::CustomContextMenu);
    DSConfigLogger->Log("CSVimportDialog started",Logger::DEBUG);
}

CSVimportDialog::~CSVimportDialog()
{
    delete ui;
}

void CSVimportDialog::on_tblView_ImportedData_customContextMenuRequested(QPoint pos)
{
    enum ContextMenuActions
    {
        ADD_RECORD_ACTION
    };

    QMenu menu(ui->tblView_ImportedData);
    QAction* addRectordAction = menu.addAction(tr("Add record to main table"));
    addRectordAction->setData((int)ADD_RECORD_ACTION);


    QAction* action = menu.exec(ui->tblView_ImportedData->mapToGlobal(pos));
    if(action)
    {
        switch(action->data().toInt())
        {
        case ADD_RECORD_ACTION:
            {
                int row = ui->tblView_ImportedData->rowAt(pos.y());
                if(row != -1)
                {
                    if(AddRecordToTable(row))
                    {
                        QMessageBox::information(this,
                                                 tr("Succes...!"),
                                                 tr("The record is succesfully added to database"));
                        DSConfigLogger->Log("record added",Logger::INFO);
                    }
                    else
                    {
                        QMessageBox::critical(this,
                                                 tr("Error..!"),
                                                 tr("The record could not be added to the database,\n error :'%0'").arg(mSqlTableModel->lastError().text()));
                        DSConfigLogger->Log(QString("record could not be added,error :'%0'").arg(mSqlTableModel->lastError().text()),
                                            Logger::ERROR);
                    }
                }
            }
        }
    }
}

void CSVimportDialog::on_btnCSVsettings_clicked()
{
    CSVsettings csvsettings(this);
    csvsettings.SetFieldSaporator(mCSVsaporator);
    csvsettings.SetFieldEnd(mCSVstringEnd);
    if(csvsettings.exec())
    {
        mCSVsaporator = csvsettings.GetFieldSaporator();
        mCSVstringEnd = csvsettings.GetFieldEnd();
    }
}

void CSVimportDialog::on_btnAddToTable_clicked()
{
    if(UpdateSQLTable())
    {
        QMessageBox::information(this,
                                 tr("Data appended"),
                                 tr("The csv data is added succesfully..!"));
    }
    else
    {
        QMessageBox::critical(this,
                                 tr("Data could not be appended"),
                                 tr("The csv data is not added completly..!\n Please see logs for more information"));
    }
}

void CSVimportDialog::on_btnImportCSV_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open csv file"),
                                                    QDir::currentPath(),
                                                    "CSV files (*.csv)");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if(ImportData(&file))
            {
                if(VerifyData())
                {
                    RefreshUi();
                }
                else
                    mImpDataModel->clear();
            }
            else
            {
                QMessageBox::critical(this,
                                      tr("Error"),
                                      tr("Data importing failed..!"));
                DSConfigLogger->Log("Data importing failed from :"+filename,Logger::ERROR);
            }
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Could not open file"));
            DSConfigLogger->Log("Could not open file :"+filename,Logger::ERROR);
        }
    }
}
//////////////////////Private///////////////////////////
bool CSVimportDialog::ImportData(QIODevice* iodevice)
{
    bool succes = false;
    mCSVTable.clear();
    if(CSVreader::ReadCSV(iodevice,mCSVTable,mCSVsaporator,mCSVstringEnd))
    {
        succes = true;
    }

    return succes;
}

bool CSVimportDialog::VerifyData()
{
    bool succes = false;
    if(mCSVTable.count()>1)    //  headers + 1 datarow
    {
        bool bEmptyFound = false;
        foreach(QVariant hdr,mCSVTable.at(0))
        {
            QString strHdr = hdr.toString().trimmed();
            if(strHdr.isEmpty())
            {
                QMessageBox::critical(this,
                                      tr("Error"),
                                      tr("Empty header item found"));
                DSConfigLogger->Log("VerifyData,Empty header item found :",Logger::ERROR);

                bEmptyFound = true;
                break;
            }

            if(!bEmptyFound)
            {
                succes = true;
            }
        }
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("No proper data found in file"));
        DSConfigLogger->Log("VerifyData,No proper data found in file :",Logger::ERROR);
    }
    return succes;
}

void CSVimportDialog::RefreshUi()
{
    mImpDataModel->clear();
    if(mCSVTable.isEmpty())
        return;

    mHeaders.clear();
    QVariantList hdrs = mCSVTable.at(0);
    int fieldCount = hdrs.count();
    for(int i=0; i<fieldCount; i++)
    {
        mHeaders << hdrs.at(i).toString();
    }

    mImpDataModel->setHorizontalHeaderLabels(mHeaders);

    int recordCount = mCSVTable.count();   //  header already read;
    for(int i=1; i<recordCount; i++)
    {
        for(int j=0; j<fieldCount; j++)
        {
            if(j < mCSVTable.at(i).count())
            {
                QStandardItem *item = new QStandardItem(mCSVTable.at(i).at(j).toString());
                mImpDataModel->setItem(i-1, j, item);
            }
            else
                break;
        }
    }
}

bool CSVimportDialog::UpdateSQLTable()
{
    bool succes = false;
    if(!mSqlTableModel)
        return succes;
    // reading from ui and populating the actual db
    const int recordCount = mImpDataModel->rowCount();
    const int fieldCount = mImpDataModel->columnCount();
    if(recordCount>0 && fieldCount>0)
    {
        for(int rec=0; rec<recordCount; rec++)
        {
            if(!AddRecordToTable(rec))
                succes = false;
        }    
    }
    return succes;
}

bool CSVimportDialog::AddRecordToTable(int row)
{
    bool succes = true;
    const int fieldCount = mImpDataModel->columnCount();
    QSqlRecord record;
    for(int field=0; field<fieldCount; field++)
    {
        QString header = mImpDataModel->headerData(field,Qt::Horizontal).toString();
        QVariant data = mImpDataModel->data(mImpDataModel->index(row,field)).toString();
        //record.setValue(header,data);
        QSqlField sqlField(header);
        sqlField.setValue(data.toString().toAscii());
        record.append(sqlField);
    }
    if(!mSqlTableModel->insertRecord(-1,record))
    {
        succes = false;
        // log error here
        DSConfigLogger->Log(QString("AddRecordToTable, insert rectord failed error '%0'")
                            .arg(mSqlTableModel->lastError().text()),
                            Logger::ERROR);
    }
    else
    {
        if(!mSqlTableModel->submitAll())
        {
            QString ErrorStr = mSqlTableModel->lastError().text();
            qDebug() << ErrorStr;
            succes = false;
            //mSqlTableModel->revert();
            // log error here
            DSConfigLogger->Log(QString("AddRecordToTable, submit all failed error '%0'")
                                .arg(ErrorStr),
                                Logger::ERROR);

            // for removing the record not added
            mSqlTableModel->removeRow(mSqlTableModel->rowCount()-1);
        }
    }

    // error. changing row color
    for(int field=0; field<fieldCount; field++)
    {
        QStandardItem* item = mImpDataModel->item(row,field);
        if(item)
        {
            item->setForeground( succes ? Qt::black : Qt::red);
        }
    }

    return succes;
}






