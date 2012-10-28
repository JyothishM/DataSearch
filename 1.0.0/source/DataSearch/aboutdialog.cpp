#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    QFont font;
    font.setPointSize(32);
    font.setBold(true);
    ui->lblSoftwareName->setFont(font);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
