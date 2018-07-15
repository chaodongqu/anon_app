#include "mainwindow.h"

#include <QApplication>
#include <QtGui/QtGui>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    LoginDialog dlg;
    if (QDialog::Accepted == dlg.exec() )
    {
        MainWindow w;
        w.show();
        return a.exec();
    }

    return 0;
}
