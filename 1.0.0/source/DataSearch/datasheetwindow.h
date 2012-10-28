#ifndef DATASHEETWINDOW_H
#define DATASHEETWINDOW_H

#include <QMainWindow>
#include <QSqlRecord>

namespace Ui {
class DataSheetWindow;
}


class DataSheetWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DataSheetWindow(QSqlRecord record,QWidget *parent = 0);
    ~DataSheetWindow();  
private slots:
    void on_actionPrint_triggered();
    void on_actionPrint_to_PDF_triggered();
private:
    bool PopulateUI(QSqlRecord& record);
    QString ReadTemplate();
    void ReplaceValues(QSqlRecord& record,QString& string);
    bool WriteTempFile(QString& string);
    QString FindTempFileURL();

    Ui::DataSheetWindow *ui;
    QSqlRecord mRecord;
};

#endif // DATASHEETWINDOW_H
