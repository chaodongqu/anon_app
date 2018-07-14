#include "authclient.h"
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>

#include"http.h"

/*auth :quchaodong
 * 完成鉴权服务器操作
 *
 *
 */

static QString strServer = "http://127.0.0.1:8080";

AuthClient::AuthClient()
{

}

// 用户登陆
int AuthClient::getLoginInfo(QString username , QString password  , QString key)
{
    QJsonObject obj;

    obj.insert("username", username);
    obj.insert("password", password);
    obj.insert("key", key);

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    http* h =  http::GetInstance() ;

    int ret = h->SendHttpsRequest(strServer+"/getLoginInfo.do" , 0 , strJson.toUtf8());
    if( 0 != ret ){
        return AuthClient::ERRO ;
    }
    else {
        QJsonDocument d = QJsonDocument::fromJson(  h->getReplyData());
        QJsonObject userInfo = d.object();

        mac =  userInfo["mac"].toString();
        qDebug() << userInfo["mac"].toString();
        qDebug()<< userInfo["flag"].toInt() ;

    }

    return AuthClient::OK;
}

// 网络总览
int AuthClient::getLimitMsg()
{
    return AuthClient::OK;
}

// 网络心跳
int  AuthClient::getMacMsg()
{
    return AuthClient::OK;
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

