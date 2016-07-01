#include "buttonreaderut.h"
#include "../buttonreader.h"
#include <QtTest>
#include <QTest>
#include <QSignalSpy>
#include "mock_wiringpi.h"
#include "../wiringPi/wiringPi/wiringPi.h"

ButtonReaderUT::ButtonReaderUT()
{
}

void ButtonReaderUT::initTestCase()
{
}

void ButtonReaderUT::cleanupTestCase()
{
}

void ButtonReaderUT::readInitialValues()
{
    ButtonReader reader;
    QCOMPARE(reader.buttonDown, false);
    int pin = reader.getPin();
    QCOMPARE(pin, -1);
}

void ButtonReaderUT::checkModeChangesByBitmask()
{
    ButtonReader readerObj;
    QSignalSpy spy(&readerObj, SIGNAL(pinChanged()));
    for( int index = 0 ; index < 17 ; index++ )
    {
        modeSetByModeMock[index] = -1;
    }
    readerObj.setPin(1); // B1_0101_0101_0101_0101
    QCOMPARE(spy.count(), 1);
    for( int index = 0 ; index < 17 ; index++ )
    {
        if( index != 1)
        {
            QCOMPARE(modeSetByModeMock[index], -1);
        }
        else
        {
            QCOMPARE(modeSetByModeMock[index], INPUT);
        }
    }
    readerObj.setPin(2); // B0_1010_1010_1010_1010
    QCOMPARE(spy.count(), 2);
    for( int index = 0 ; index < 17 ; index++ )
    {
        if( (index != 1) &&
            (index != 2) )
        {
            QCOMPARE(modeSetByModeMock[index], -1);
        }
        else
        {
            QCOMPARE(modeSetByModeMock[index], INPUT);
        }
    }
}

void ButtonReaderUT::checkValueUpdatesBySignal()
{
    ButtonReader reader;
    QSignalSpy pressedSpy(&reader, SIGNAL(pressed()));
    QSignalSpy releasedSpy(&reader, SIGNAL(released()));
    pinStatesForReading[2] = HIGH;
    pinStatesForReading[3] = LOW;
    QCOMPARE(pressedSpy.count(), 0);
    QCOMPARE(releasedSpy.count(), 0);
    // These should not change value or emit signal
    reader.setPin(2);
    reader.readValueOfPin();
    pinStatesForReading[2] = LOW;
    QCOMPARE(reader.buttonDown, false);
    QCOMPARE(pressedSpy.count(), 0);
    QCOMPARE(releasedSpy.count(), 0);
    //This is first time value changes and signal gets emitted
    reader.readValueOfPin();
    QCOMPARE(pressedSpy.count(), 1);
    QCOMPARE(releasedSpy.count(), 0);
    QCOMPARE(reader.buttonDown, true);
    pinStatesForReading[2] = HIGH;
    reader.readValueOfPin();
    QCOMPARE(pressedSpy.count(), 1);
    QCOMPARE(releasedSpy.count(), 1);
    QCOMPARE(reader.buttonDown, false);
    reader.setPin(3);
    QCOMPARE(pressedSpy.count(), 2);
    QCOMPARE(releasedSpy.count(), 1);
    QCOMPARE(reader.buttonDown, true);
}

void ButtonReaderUT::uninitializedValues()
{
    for( int index = 0 ; index < 17 ; index++ )
    {
        modeSetByModeMock[index] = -1;
    }
    ButtonReader reader;
    for( int index = 0 ; index < 17 ; index++ )
    {
        QCOMPARE(modeSetByModeMock[index],  -1);
    }
    QSignalSpy spy(&reader, SIGNAL(pressed()));
    reader.readValueOfPin();
    QCOMPARE(spy.count(), 0);
    QCOMPARE(reader.buttonDown, false);
}
