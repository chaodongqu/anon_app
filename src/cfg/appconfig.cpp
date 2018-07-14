#include "appconfig.h"
#include<QFile>
#include<QCoreApplication>

AppConfig::AppConfig()
{
    load();
}


void
AppConfig::load(){

    QString fileName = "/Users/quchaodong/work/anon_app/src/test.json" ;
    QString val;
    QFile file;

    //fileName =  "test.json" ;// QCoreApplication::applicationDirPath() ;

    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    qWarning() << sett2["description"].toString();


}
