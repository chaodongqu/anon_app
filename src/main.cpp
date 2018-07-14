#include "mainwindow.h"

#include <QApplication>
#include <QtGui/QtGui>
#include "logindialog.h"

#include"cfg/appconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppConfig *pCfg = new AppConfig();

    delete pCfg;

    LoginDialog dlg;
    if (QDialog::Accepted == dlg.exec() )
    {
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}
