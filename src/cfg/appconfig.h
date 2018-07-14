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

private:

    void load() ;
};

#endif // APPCONFIG_H
