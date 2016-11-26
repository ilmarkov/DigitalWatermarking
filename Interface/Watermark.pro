#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T23:20:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Watermark
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    creation.cpp \
    validation.cpp \
    makewm.cpp

HEADERS  += menu.h \
    creation.h \
    validation.h \
    makewm.h

FORMS    += menu.ui \
    creation.ui \
    validation.ui \
    makewm.ui

RESOURCES += \
    resource.qrc
