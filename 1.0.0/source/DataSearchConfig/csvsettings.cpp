#include "csvsettings.h"
#include "ui_csvsettings.h"

CSVsettings::CSVsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVsettings)
{
    ui->setupUi(this);
}

CSVsettings::~CSVsettings()
{
    delete ui;
}

void CSVsettings::SetFieldSaporator(QString fieldSapo)
{
    ui->edt_FieldSaporator->setText(fieldSapo);
}

void CSVsettings::SetFieldEnd(QString fieldEnd)
{
    ui->edt_FieldEnd->setText(fieldEnd);
}

QString CSVsettings::GetFieldSaporator()
{
    return ui->edt_FieldSaporator->text();
}

QString CSVsettings::GetFieldEnd()
{
    return ui->edt_FieldEnd->text();
}
