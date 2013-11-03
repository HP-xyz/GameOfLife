#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T07:44:11
#
#-------------------------------------------------

QT       -= gui

TARGET = Domain
TEMPLATE = lib

DEFINES += DOMAIN_LIBRARY

SOURCES += world.cpp \
    cell.cpp

HEADERS += world.h\
        domain_global.h \
    cell.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
