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
    pinSetByModeMock = -1;
    modeSetByModeMock = -1;
    controller.setGpioPinNumber(3);
    QCOMPARE(pinSetByModeMock, 3);
    QCOMPARE(modeSetByModeMock, OUTPUT);
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
    pinSetByWriteMock = -1;
    valueSetByWriteMock = HIGH;
    QCOMPARE(spy.count(), 0);
    controller.setLedLightOn(false);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(controller.ledLightOn, false);
    QCOMPARE(pinSetByWriteMock, 6);
    QCOMPARE(valueSetByWriteMock, LOW);
    pinSetByWriteMock = -1;
    valueSetByWriteMock = LOW;
    controller.setLedLightOn(true);
    QCOMPARE(controller.ledLightOn, true);
    QCOMPARE(pinSetByWriteMock, 6);
    QCOMPARE(valueSetByWriteMock, HIGH);
    QCOMPARE(controller.getLedLightOn(), true);
    QCOMPARE(spy.count(), 1);
    controller.setGpioPinNumber(3);
    QCOMPARE(spy.count(), 2);
    QCOMPARE(pinSetByWriteMock, 6);
    QCOMPARE(valueSetByWriteMock, LOW);
}

void LedControllerUT::testUnInitializedCalls()
{
    LedController controller;
    pinSetByWriteMock = -2;
    valueSetByWriteMock = -2;
    controller.setLedLightOn(true);
    QCOMPARE(pinSetByWriteMock, -2);
    QCOMPARE(valueSetByWriteMock, -2);
    controller.setGpioPinNumber(0);
    QCOMPARE(pinSetByWriteMock, -2);
    QCOMPARE(valueSetByWriteMock, -2);
}
