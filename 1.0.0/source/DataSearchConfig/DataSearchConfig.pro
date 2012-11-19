#-------------------------------------------------
#
# Project created by QtCreator 2012-11-18T19:27:55
#
#-------------------------------------------------

QT       += core gui\
            sql

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

TARGET = DataSearchConfig
TEMPLATE = app


SOURCES += main.cpp\
        datasearchconfig.cpp

HEADERS  += datasearchconfig.h \
    ../DataSearch/constants.h

FORMS    += datasearchconfig.ui
