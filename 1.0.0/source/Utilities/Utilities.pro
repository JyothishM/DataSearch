#-------------------------------------------------
#
# Project created by QtCreator 2012-11-10T12:09:23
#
#-------------------------------------------------

QT       -= gui

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

TARGET = Utilities
TEMPLATE = lib

DEFINES += UTILITIES_LIBRARY

SOURCES += \
    csv/csvwriter.cpp \
    csv/csvreader.cpp \
    logger.cpp

HEADERS +=\
        Utilities_global.h \
    csv/csvwriter.h \
    csv/csvreader.h \
    csv/CSVcommon.h \
    logger.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE462C9DB
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Utilities.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
