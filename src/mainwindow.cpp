#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "outcontrysetdialog.h"
#include "timejumpsetdialog.h"
#include "aboutdialog.h"

#include"net/http.h"
#include"net/authclient.h"

#define TIMER_TIMEOUT	(5*1000)


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->setVisible(false) ;
    ui->menuBar->setNativeMenuBar(false);

    m_nTimerID = this->startTimer(TIMER_TIMEOUT);

}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        handleTimeout();
    }
}

void MainWindow::handleTimeout()
{
    qDebug()<<"handleTimeout\n";

    AuthClient auth ;
    // 获取概览信息
    if( AuthClient::OK == auth.getLimitMsg() ){

        // 根据回传信息， 更新界面
    }

    // 心跳上报
    if(AuthClient::OK == auth.getMacMsg( 10)){
        // 上报流量
    }
}


MainWindow::~MainWindow()
{
    killTimer(m_nTimerID);

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

//    http* h =  http::GetInstance() ;
//    h->SendHttpsRequest("http://127.0.0.1:8080/login2" , 0 , "hello world" );
//    QByteArray d = h->getReplyData();
}


void MainWindow::on_action_triggered()
{
    // 关于
    AboutDialog dlg ;
    dlg.exec();

}

