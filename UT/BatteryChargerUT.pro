#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T08:17:49
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = tst_batterychargerut
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ledcontrollerut.cpp \
    tst_batterycharger.cpp \
    ../ledcontroller.cpp \
    mock_wiringpi.cpp \
    buttonreaderut.cpp \
    ../buttonreader.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ledcontrollerut.h \
    ../ledcontroller.h \
    mock_wiringpi.h \
    buttonreaderut.h \
    ../buttonreader.h
