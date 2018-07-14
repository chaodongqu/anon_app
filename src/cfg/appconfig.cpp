#include "appconfig.h"
#include<QFile>
#include<QCoreApplication>
#include<QDir>

AppConfig::AppConfig()
{
    load();
}


void
AppConfig::load(){

    QString fileName = "anon_app.json";//"/Users/quchaodong/work/anon_app/src/test.json" ;
    QString val;
    QFile file;


    fileName =  QCoreApplication::applicationDirPath() + "/anon_app.json" ;

    qWarning()<<fileName;

    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    qWarning() << sett2["authServer"].toString();


}
