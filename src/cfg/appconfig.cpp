#include "appconfig.h"
#include<QFile>
#include<QCoreApplication>
#include<QDir>


static AppConfig* cfgInst = NULL ;

AppConfig::AppConfig()
{
    load();
}

AppConfig* AppConfig::getInst(){

    if( NULL == cfgInst ){
        cfgInst = new AppConfig();
        cfgInst->load(); 
    }
    return cfgInst ;    
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
    m_cfgData = d.object();
    qWarning() << m_cfgData["authServer"].toString();


}
