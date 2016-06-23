#include "ledcontrollerut.h"
#include "../ledcontroller.h"
#include <QtTest>
#include <QSignalSpy>

LedControllerUT::LedControllerUT()
{
}

void LedControllerUT::readWriteGPIOPinNumber()
{
    LedController controller;
    QSignalSpy spy(&controller, SIGNAL(gpioPinNumberChanged()));
    QCOMPARE(controller.gpioPinNumber, -1);
    QCOMPARE(controller.getGpioPinNumber(), -1);
    QCOMPARE(spy.count(), 0);
    controller.setGpioPinNumber(1);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(controller.gpioPinNumber, 1);
    QCOMPARE(controller.getGpioPinNumber(), 1);
}
