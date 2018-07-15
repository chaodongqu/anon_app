#ifndef APPCONFIG_H
#define APPCONFIG_H
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include<QDebug>


class AppConfig
{
public:
    AppConfig();


    static AppConfig* getInst();
    
public :
    QJsonObject m_cfgData;

private:

    void load() ;
};

#endif // APPCONFIG_H
