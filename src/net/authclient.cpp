#include "authclient.h"
#include<QJsonObject>
#include<QJsonDocument>

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
    h->SendHttpsRequest(strServer+"/login2" , 0 , strJson.toUtf8());
    // h->getReplyData();

    // todo get Mac (indentify)
    mac = "14:12:00:e2:26:eb" ;

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

