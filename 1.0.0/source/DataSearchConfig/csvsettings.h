#ifndef CSVSETTINGS_H
#define CSVSETTINGS_H

#include <QDialog>

namespace Ui {
    class CSVsettings;
}

class CSVsettings : public QDialog
{
    Q_OBJECT

public:
    explicit CSVsettings(QWidget *parent = 0);
    ~CSVsettings();
    void SetFieldSaporator(QString fieldSapo);
    void SetFieldEnd(QString fieldEnd);
    QString GetFieldSaporator();
    QString GetFieldEnd();
private:
    Ui::CSVsettings *ui;
};

#endif // CSVSETTINGS_H
