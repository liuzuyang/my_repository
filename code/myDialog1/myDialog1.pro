#-------------------------------------------------
#
# Project created by QtCreator 2018-11-01T16:54:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myDialog1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mywidget.cpp \
    mydialog.cpp

HEADERS += \
        mywidget.h \
    ../../build/build-myDialog1-Desktop_Qt_5_10_1_clang_64bit-Debug/ui_mywidget.h \
    mydialog.h

FORMS += \
        mywidget.ui \
    mydialog.ui
