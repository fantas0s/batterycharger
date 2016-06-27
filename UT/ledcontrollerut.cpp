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
    QSignalSpy spy(&controller, SIGNAL(ledOnChanged()));
    controller.setGpioPinNumber(6);
    QCOMPARE(controller.getLedOn(), false);
    pinSetByWriteMock = -1;
    valueSetByWriteMock = HIGH;
    QCOMPARE(spy.count(), 0);
    controller.setLedOn(false);
    QCOMPARE(spy.count(), 0);
    QCOMPARE(controller.ledOn, false);
    QCOMPARE(pinSetByWriteMock, 6);
    QCOMPARE(valueSetByWriteMock, LOW);
    pinSetByWriteMock = -1;
    valueSetByWriteMock = LOW;
    controller.setLedOn(true);
    QCOMPARE(controller.ledOn, true);
    QCOMPARE(pinSetByWriteMock, 6);
    QCOMPARE(valueSetByWriteMock, HIGH);
    QCOMPARE(controller.getLedOn(), true);
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
    controller.setLedOn(true);
    QCOMPARE(pinSetByWriteMock, -2);
    QCOMPARE(valueSetByWriteMock, -2);
    controller.setGpioPinNumber(0);
    QCOMPARE(pinSetByWriteMock, -2);
    QCOMPARE(valueSetByWriteMock, -2);
}
