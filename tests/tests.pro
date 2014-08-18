#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T09:48:06
#
#-------------------------------------------------

QT       += widgets network testlib

TARGET = tests
CONFIG   += console
CONFIG   -= app_bundle

LIBS	+= -lcrypto

TEMPLATE = app

include(../cryptfile/cryptfile.pri);

SOURCES += tst_testmainwindow.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
