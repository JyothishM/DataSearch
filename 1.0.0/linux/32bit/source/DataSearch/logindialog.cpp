#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
void LoginDialog::SetUserName(QString username)
{
    ui->edit_username->setText(username);
}
QString LoginDialog::GetUserName()
{
    return ui->edit_username->text();
}
void LoginDialog::SetPassWord(QString password)
{
    ui->edit_password->setText(password);
}
QString LoginDialog::GetPassWord()
{
    return ui->edit_password->text();
}
