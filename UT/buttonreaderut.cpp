#include "buttonreaderut.h"
#include "../buttonreader.h"
#include <QtTest>
#include <QSignalSpy>
#include "mock_wiringpi.h"
#include "../wiringPi/wiringPi/wiringPi.h"

ButtonReaderUT::ButtonReaderUT()
{

}

void ButtonReaderUT::readInitialValues()
{
    ButtonReader reader;
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    quint32 bitMask = reader.getReadModePinMask();
    QCOMPARE((int)bitMask, 0);
}

void ButtonReaderUT::checkModeChangesByBitmask()
{
    ButtonReader readerObj;
    QSignalSpy spy(&readerObj, SIGNAL(readModePinMaskChanged()));
    for( int index = 0 ; index < 17 ; index++ )
    {
        modeSetByModeMock[index] = -1;
    }
    readerObj.setReadModePinMask(0x15555); // B1_0101_0101_0101_0101
    QCOMPARE(spy.count(), 1);
    for( int index = 0 ; index < 17 ; index++ )
    {
        if( index & 1)
        {
            QCOMPARE(modeSetByModeMock[index], -1);
        }
        else
        {
            QCOMPARE(modeSetByModeMock[index], INPUT);
        }
    }
    readerObj.setReadModePinMask(0x0aaaa); // B0_1010_1010_1010_1010
    QCOMPARE(spy.count(), 2);
    for( int index = 0 ; index < 17 ; index++ )
    {
        QCOMPARE(modeSetByModeMock[index], INPUT);
    }
}

void ButtonReaderUT::checkValueUpdatesBySignal()
{
    ButtonReader reader;
    QSignalSpy spy(&reader, SIGNAL(pin0ButtonPressedChanged()));
    reader.setReadModePinMask(0x00001);
    pinStatesForReading[0] = HIGH;
    pinStatesForReading[1] = HIGH;
    pinStatesForReading[16] = HIGH;
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    QCOMPARE(spy.count(), 0);
    reader.readPinValues();
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    pinStatesForReading[0] = LOW;
    pinStatesForReading[1] = LOW;
    pinStatesForReading[16] = LOW;
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    QCOMPARE(spy.count(), 0);
    reader.readPinValues();
    QCOMPARE(spy.count(), 1);
    QCOMPARE(reader.pin0ButtonPressed, true);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    reader.setReadModePinMask(0x00002);
    QCOMPARE(spy.count(), 2);
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, true);
    QCOMPARE(reader.pin16ButtonPressed, false);
    reader.setReadModePinMask(0x10002);
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, true);
    QCOMPARE(reader.pin16ButtonPressed, true);
    pinStatesForReading[0] = HIGH;
    pinStatesForReading[1] = HIGH;
    pinStatesForReading[16] = HIGH;
    reader.readPinValues();
    QCOMPARE(reader.pin0ButtonPressed, false);
    QCOMPARE(reader.pin1ButtonPressed, false);
    QCOMPARE(reader.pin16ButtonPressed, false);
    QCOMPARE(spy.count(), 2);
}
