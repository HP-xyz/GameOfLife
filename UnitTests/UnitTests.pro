#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T07:46:33
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = tst_unittests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_unittests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Domain/release/ -lDomain
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Domain/debug/ -lDomain
else:unix: LIBS += -L$$OUT_PWD/../Domain/ -lDomain

INCLUDEPATH += $$PWD/../Domain
DEPENDPATH += $$PWD/../Domain
