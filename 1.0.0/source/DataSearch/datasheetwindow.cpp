#include "datasheetwindow.h"
#include "ui_datasheetwindow.h"
#include "constants.h"
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QSqlField>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QtGlobal>

DataSheetWindow::DataSheetWindow(QSqlRecord record,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataSheetWindow)
{
    ui->setupUi(this);
    mRecord = record;
    PopulateUI(mRecord);
}
DataSheetWindow::~DataSheetWindow()
{
    delete ui;
}
//slots
void DataSheetWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Print datasheet"));
    if(dialog->exec() == QDialog::Accepted)
    {
        ui->webView->print(&printer);
    }
}
void DataSheetWindow::on_actionPrint_to_PDF_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                 tr("Export to PDF"),
                                 QDir::currentPath());
    if(!filename.isEmpty())
    {
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);

        // printing
        ui->webView->print(&printer);
        QDir::setCurrent(QFileInfo(filename).path());
    }
}
// private
bool DataSheetWindow::PopulateUI(QSqlRecord& record)
{
    QString strTemplate = ReadTemplate();
    if(!strTemplate.isEmpty())
    {
        ReplaceValues(record,strTemplate);
        if(WriteTempFile(strTemplate))
        {
            // showing in webview.
            QString templatefileURL = FindTempFileURL();
            ui->webView->setUrl(QUrl(templatefileURL));
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Could not write temporary file,please check the file writing permissions..!"));
        }
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Empty template file..!"));
    }
}
QString DataSheetWindow::ReadTemplate()
{
    QFile file(DATASHEET_TEMPLATE_FILE);
    QString string;
    if (file.open(QFile::ReadOnly | QFile::Text))
         string = file.readAll();
    file.close();
    return string;
}
void DataSheetWindow::ReplaceValues(QSqlRecord& record,QString& string)
{
    if(record.isEmpty())
        return;

    const int fieldcount = record.count();
    for(int i=0; i<fieldcount; i++)
    {
        QSqlField field = record.field(i);
        if(!field.isNull())
        {
            QString fieldname = field.name();
            if(!fieldname.isEmpty())
            {
                string = string.replace(QString("\%%0\%").arg(fieldname),
                                        field.value().toString());
            }
        }
    }
}
bool DataSheetWindow::WriteTempFile(QString& string)
{
    QFile tempfile(DATASHEET_TEMP_FILE);
    if (tempfile.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream outstream(&tempfile);
        outstream << string;
        tempfile.close();
        return true;
    }
    return false;
}
QString DataSheetWindow::FindTempFileURL()
{
    QString url;
#ifdef Q_OS_WIN32

///////////////////////////Windows///////////////////////////////////////
    #if DEVELOPMENT_BUILD
        url = QString("%0../../%1").arg(QApplication::applicationDirPath())
                              .arg(DATASHEET_TEMP_FILE);
    #else
        url = QString("%0../%1").arg(QApplication::applicationDirPath())
                              .arg(DATASHEET_TEMP_FILE);
    #endif
/////////////////////////////////////////////////////////////////////////

#else
    url = QString("file://%0/%1").arg(QApplication::applicationDirPath())
                          .arg(DATASHEET_TEMP_FILE);
#endif

    return url;
}
