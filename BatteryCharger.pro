TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    ledcontroller.cpp \
    wiringPi/wiringPi/wiringPi.c \
    wiringPi/wiringPi/softPwm.c \
    wiringPi/wiringPi/softTone.c \
    wiringPi/wiringPi/piHiPri.c

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ledcontroller.h \
    wiringPi/wiringPi/wiringPi.h \
    wiringPi/wiringPi/softPwm.h \
    wiringPi/wiringPi/softTone.h
