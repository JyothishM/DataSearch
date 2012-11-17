#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T20:34:00
#
#-------------------------------------------------

QT       += core gui

PLATFORM = 'linux'
BUILDTYPE = 'debug'

win32{
    PLATFORM = 'windows'
}
unix{
    PLATFORM = 'linux'
}
CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }


DESTDIR = $${PWD}../../BIN/$${PLATFORM}/$${BUILDTYPE}

TARGET = PreReqSetup
TEMPLATE = app


SOURCES += main.cpp\
        prereqsetup.cpp

HEADERS  += prereqsetup.h

FORMS    += prereqsetup.ui
