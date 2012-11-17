#include "prereqsetup.h"
#include "ui_prereqsetup.h"
#include <QListWidgetItem>

PreReqSetup::PreReqSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreReqSetup)
{
    ui->setupUi(this);

    QListWidgetItem* listitem = new QListWidgetItem(ui->listWidget);
    listitem->setText("text");
    listitem->setCheckState(Qt::Checked);
    ui->listWidget->addItem(listitem);
}

PreReqSetup::~PreReqSetup()
{
    delete ui;
}
