#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T09:41:56
#
#-------------------------------------------------

QT       += core gui
LIBS	+= -lcrypto

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += 	$$PWD/main.cpp

TARGET = cryptfile
TEMPLATE = app

include(cryptfile.pri);
