#include "ledcontrollerut.h"
#include "../ledcontroller.h"
#include <QtTest>
#include <QSignalSpy>
#include "../wiringPi/wiringPi/wiringPi.h"
#include "mock_wiringpi.h"

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
    modeSetByModeMock[3] = -1;
    controller.setGpioPinNumber(3);
    QCOMPARE(modeSetByModeMock[3], OUTPUT);
    QCOMPARE(spy.count(), 1);
    QCOMPARE(controller.gpioPinNumber, 3);
    QCOMPARE(controller.getGpioPinNumber(), 3);
}

void LedControllerUT::setGetLedOn()
{
    LedController controller;
    QSignalSpy spy(&controller, SIGNAL(ledLightOnChanged()));
    controller.setGpioPinNumber(6);
    QCOMPARE(controller.getLedLightOn(), false);
    valueSetByWriteMock[6] = HIGH;
    QCOMPARE(spy.count(), 0);
    controller.setLedLightOn(false);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(controller.ledLightOn, false);
    QCOMPARE(valueSetByWriteMock[6], LOW);
    controller.setLedLightOn(true);
    QCOMPARE(controller.ledLightOn, true);
    QCOMPARE(valueSetByWriteMock[6], HIGH);
    QCOMPARE(controller.getLedLightOn(), true);
    QCOMPARE(spy.count(), 1);
    controller.setGpioPinNumber(3);
    QCOMPARE(spy.count(), 2);
    QCOMPARE(valueSetByWriteMock[6], LOW);
}

void LedControllerUT::testUnInitializedCalls()
{
    LedController controller;
    valueSetByWriteMock[0] = -2;
    controller.setLedLightOn(true);
    QCOMPARE(valueSetByWriteMock[0], -2);
    controller.setGpioPinNumber(0);;
    QCOMPARE(valueSetByWriteMock[0], -2);
}

void LedControllerUT::testInvalidPinIndex()
{
    LedController controller;
    QCOMPARE(controller.gpioPinNumber, -1);
    controller.setGpioPinNumber(17); // Too big
    QCOMPARE(controller.gpioPinNumber, -1);
    controller.setGpioPinNumber(16); // Last OK
    QCOMPARE(controller.gpioPinNumber, 16);
}
