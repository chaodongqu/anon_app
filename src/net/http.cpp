#include "http.h"

#include <QNetworkAccessManager>

#include <QSslKey>
#include <QSslSocket>
#include <QSslConfiguration>
#include <QSslCertificate>
#include <QSslError>
#include <QUrl>

#include <QNetworkRequest>
#include <QtNetwork>

/*
 * 说明，
 * 1 实现基础http/https 请求 ，SendHttpsRequest
 * 2 getReplyData 方法获取请求返回数据
 * 3 本模块使用单例模式， 见 GetInstance
 *
 *
 *
 * auth ： quchaoodng
 *
 * */

static http http_inst;

http* http::GetInstance(){
    return &http_inst ;
}

http::http( QNetworkAccessManager *parent)
    :m_pManager( parent)
{

    if(NULL == m_pManager){
        m_pManager = new QNetworkAccessManager();
    }
}



http::~http()
{

    if( NULL != m_pManager ){
        delete m_pManager ;
    }
}

// 发送请求
// 返回： 0 成功 1 失败
int http::SendHttpsRequest( QString url  , int useSSL , QByteArray postBody )
{
    nErro = 0;
    replyContent = "" ;

    QNetworkRequest request;

    // 发送https请求前准备工作;
    if( 1 == useSSL )
    {
        QSslConfiguration config;
        QSslConfiguration conf = request.sslConfiguration();
        conf.setPeerVerifyMode(QSslSocket::VerifyNone);
        conf.setProtocol(QSsl::TlsV1SslV3);
        request.setSslConfiguration(conf);
    }


    // 因为 设计文档中需要传递加密数据， 暂时认为postbody 全部为txt。
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");

    request.setUrl(QUrl(url));

#if 0
    QByteArray data;
    QUrlQuery qu;

    qu.addQueryItem("unm", "aUser");
    qu.addQueryItem("pwd", "aPass");
    QUrl params;
    params.setQuery(qu);
    data = params.toEncoded();
#endif
    QNetworkReply *pReply = m_pManager->post( request ,postBody );

    QEventLoop eventLoop;
    connect(pReply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

    connect(pReply,SIGNAL(finished()),this,SLOT(finished()));
    connect(pReply , SIGNAL(error(QNetworkReply::NetworkError)) ,
            this , SLOT(onError(QNetworkReply::NetworkError)) );
    connect(pReply,SIGNAL(downloadProgress(qint64,qint64)),
            this,SLOT(downloadProgress(qint64,qint64)));

    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    pReply->deleteLater();
    pReply = NULL;

    qWarning()<< "--end \n" ;


     return nErro ;
}

// 请求完成;
void http::finished()
{
    qWarning()<< "--get data \n";
    QNetworkReply *pReplay = qobject_cast<QNetworkReply*>(sender());

    replyContent = pReplay->readAll();

    qDebug()<<replyContent <<"\n";
}

// 请求过程中
void http::downloadProgress(qint64 bytesSent, qint64 bytesTotal){
    // 暂时不用
    qWarning()<< "\ndownloadProgress done:\t bytesTotal="
              << bytesTotal << "\t bytesSent="<< bytesSent
              <<"\n";
}

// 请求失败;
void http::onError(QNetworkReply::NetworkError errorCode)
{
    this->nErro = 1;

    qDebug()<< "on erro \n";
    QNetworkReply *pReplay = qobject_cast<QNetworkReply*>(sender());
    // 输出错误码及错误信息;
    qDebug()<< errorCode;
    qDebug()<< pReplay->errorString();
}
