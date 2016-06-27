TEMPLATE = app

QT += qml quick
CONFIG += c++11 qmltestcase

SOURCES += \
    tst_main.cpp \
    ../ledcontroller.cpp \
    dummywiringpi.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    tst_ledbutton.qml

HEADERS += \
    ../ledcontroller.h
