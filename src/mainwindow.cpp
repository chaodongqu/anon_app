#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "outcontrysetdialog.h"
#include "timejumpsetdialog.h"
#include "aboutdialog.h"

#include"net/http.h"
#include<QNetworkAccessManager>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false) ;
    ui->menuBar->setNativeMenuBar(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actiontimeset_triggered()
{

    // time set

    TimeJumpSetDialog dlg;
    dlg.exec();
}

void MainWindow::on_actionoutset_triggered()
{
    // out country set

    OutContrySetDialog dlg;
    dlg.exec();

}

void MainWindow::on_pushButton_clicked()
{

    http* h =  http::GetInstance() ;
    //h->SendHttpsRequest("https://127.0.0.1:8080/" , 1 , NULL );
    //
    h->SendHttpsRequest("http://127.0.0.1:8080/login2" , 0 , "hello world" );

    QByteArray d = h->getReplyData();
}


void MainWindow::on_action_triggered()
{
    // 关于
    AboutDialog dlg ;
    dlg.exec();

}
