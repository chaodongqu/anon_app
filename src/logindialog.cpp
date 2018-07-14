#include "logindialog.h"
#include "ui_logindialog.h"
#include"net/authclient.h"

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

void LoginDialog::on_pushButton_clicked()
{

    AuthClient auth;
    int ret = auth.getLoginInfo( "username" , "password" , "key"  );

    if( AuthClient::OK == ret ){
           accept();
    }
    // login failed

}

void LoginDialog::on_pushButton_2_clicked()
{
    reject();
}
