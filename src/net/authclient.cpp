#include "authclient.h"
#include<QJsonDocument>
#include<QJsonArray>

#include"http.h"
#include<stdio.h>
#include "cfg/appconfig.h"

/*auth :quchaodong
 * 完成鉴权服务器操作
 *
 *
 */


#define MAX_BUFF 256

static QString strServer = "http://127.0.0.1:8080";
QString AuthClient::mac = "";

AuthClient::AuthClient()
{

   QJsonObject cfg =  AppConfig::getInst()->m_cfgData;

   strServer = cfg["authServer"].toString();

}

// 用户登陆
int AuthClient::getLoginInfo(QString username , QString password  , QString key)
{


    char szParam[MAX_BUFF] = "";    
    snprintf( szParam , MAX_BUFF-1 , 
                    "username=%s&password=%key=%s" , 
                    username.toLatin1().data() , 
                    password.toLatin1().data() , 
                    key.toLatin1().data() 
            );

    int ret = sendAuth( szParam , "/getLoginInfo.do") ;
    
    if( AuthClient::OK != ret ){
        return AuthClient::ERRO ; // test return OK
    }
    else {
        mac =  m_msg["mac"].toString();
        qDebug() << mac;
    }

    return AuthClient::OK;
}

// 网络总览
int AuthClient::getLimitMsg()
{    
    char szParam[MAX_BUFF] = "";

    getRandId();
    snprintf( szParam , MAX_BUFF-1 , "mac=%s&id=%d" , mac.toLatin1().data() , m_id);

    return sendAuth( szParam , "/getLimitMsg.do") ;

}

// 网络心跳
int  AuthClient::getMacMsg( int size )
{
    char szParam[MAX_BUFF] = "";

    getRandId();
    snprintf( szParam , MAX_BUFF-1 , "mac=%s&size=%d&id=%d" , mac.toLatin1().data() , size , m_id);

    return sendAuth( szParam , "/getMacMsg.do") ;
}

//出口国家
int AuthClient::getAddressInfo()
{
    return AuthClient::OK;
}

//出口城市
int AuthClient::getLocationInfo()
{
    return AuthClient::OK;
}

// 生成随机数
int AuthClient::getRandId(){

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    m_id = qrand();
   
    return m_id ;
}


int AuthClient::sendAuth( char *szParam , char *address){

     http* h =  http::GetInstance() ;

    int ret = h->SendHttpsRequest(strServer+QString(address) , 0 , szParam);
    if( 0 != ret ){
        return AuthClient::ERRO ; // 
    }
    else{
        QJsonDocument d = QJsonDocument::fromJson(  h->getReplyData());
        m_msg = d.object();
        qDebug()<< m_msg ;
    }

    return AuthClient::OK;
}
