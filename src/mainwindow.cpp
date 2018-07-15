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
    m_IsConnect = 0;
    m_StartRunTime = 0 ; // 开始计时--运行时间
    m_UsedNetwork = 0; //  已经使用流量

    ui->setupUi(this);
    ui->mainToolBar->setVisible(false) ;
    ui->menuBar->setNativeMenuBar(false);

    m_nTimerID = this->startTimer(TIMER_TIMEOUT);

    updateNetworkStatus();
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

        char szTmp[256] = "";

        // 类型
        int type = auth.m_msg["type"].toInt() ;
        if( 0 == type ){
            this->ui->limmit_type->setText("时间限制");
        }
        else{
            this->ui->limmit_type->setText("流量限制");
        }

        // 剩余天数
        int maxassoc = auth.m_msg["maxassoc"].toInt();

        snprintf(szTmp , 255 , "%d 天",maxassoc ) ;
        this->ui->label_days->setText( szTmp );

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
    // 连接网络
    // TODO ， if connect by ssr clent  ， m_IsConnect = 1

    if(1 == m_IsConnect ){
        time_t t;
        time(&t);

        m_StartRunTime = t ; // 开始计时--运行时间
        m_UsedNetwork = 0; //  已经使用流量
    }

    updateNetworkStatus();


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

void MainWindow::updateNetworkStatus(){

    if( m_IsConnect){
        this->ui->label_network->setText("断开");
    }
    else{
        this->ui->label_network->setText("已连");
    }
}

