#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T16:39:19
#
#-------------------------------------------------

QT       += core gui\
            sql\
            webkit

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
