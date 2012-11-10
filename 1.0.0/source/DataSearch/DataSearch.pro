#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T16:39:19
#
#-------------------------------------------------

QT       += core gui\
            sql\
            webkit

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

win32:RC_FILE = resources\DataSearch.rc

TARGET = DataSearch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    datasheetwindow.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    constants.h \
    datasheetwindow.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    datasheetwindow.ui \
    aboutdialog.ui

RESOURCES += \
    resources/icons.qrc

OTHER_FILES += \
    resources/DataSearch.rc.txt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities
else:symbian: LIBS += -lUtilities
else:unix: LIBS += -L$$PWD/../BIN/$${PLATFORM}/$${BUILDTYPE}/ -lUtilities

INCLUDEPATH += $$PWD/../Utilities
DEPENDPATH += $$PWD/../Utilities
