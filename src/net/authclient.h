#ifndef AUTHCLIENT_H
#define AUTHCLIENT_H

#include<QString>
#include<QJsonObject>

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
    int  getMacMsg(int size);

    //出口国家
    int getAddressInfo();

    //出口城市
    int getLocationInfo();

public :
    QJsonObject m_msg; // 保存来自服务端消息

private :

    int getRandId();

    int sendAuth( char *param , char *address );

private :

    // 登录后，服务端返回客户端的唯一标识
    static QString mac;

    int m_id  ; // 保存随机数idß

};

#endif // AUTHCLIENT_H
