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
        datasearchconfig.cpp \
    csvimportdialog.cpp \
    csvsettings.cpp \
    datasearchconfig_common.cpp

HEADERS  += datasearchconfig.h \
    ../DataSearch/constants.h \
    csvimportdialog.h \
    csvsettings.h \
    datasearchconfig_common.h

FORMS    += datasearchconfig.ui \
    csvimportdialog.ui \
    csvsettings.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities
else:symbian: LIBS += -lUtilities
else:unix: LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities

INCLUDEPATH += $$PWD/../Utilities
DEPENDPATH += $$PWD/../Utilities

INCLUDEPATH += $$PWD/../DataSearch
DEPENDPATH += $$PWD/../DataSearch
