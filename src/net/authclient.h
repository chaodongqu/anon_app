#ifndef AUTHCLIENT_H
#define AUTHCLIENT_H

#include<QString>

class AuthClient
{
public:
    enum AuthStatus {
        OK =0,
        ERRO,

    };

public:
    AuthClient();

    // 用户登陆
    int getLoginInfo(QString username , QString password , QString key);

    // 网络总览
    int getLimitMsg();

    // 网络心跳
    int  getMacMsg();

    //出口国家
    int getAddressInfo();

    //出口城市
    int getLocationInfo();

private :

    // 登录后，服务端返回客户端的唯一标识
    QString mac;

};

#endif // AUTHCLIENT_H
