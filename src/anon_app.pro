#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T13:51:48
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = anon_app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    timejumpsetdialog.cpp \
    outcontrysetdialog.cpp \
    cfg/appconfig.cpp \
    net/http.cpp \
    net/authclient.cpp \
    aboutdialog.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    timejumpsetdialog.h \
    outcontrysetdialog.h \
    cfg/appconfig.h \
    net/http.h \
    net/authclient.h \
    aboutdialog.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    timejumpsetdialog.ui \
    outcontrysetdialog.ui \
    aboutdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
