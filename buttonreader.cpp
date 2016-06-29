#include "buttonreader.h"
#include "wiringPi/wiringPi/wiringPi.h"

#define MAX_NUM_IO_PINS_FROM_WIRINGPI 17

ButtonReader::ButtonReader() :
    readmodePins(0),
    pin0ButtonPressed(false),
    pin1ButtonPressed(false),
    pin16ButtonPressed(false)
{
    pinMode (0, INPUT) ;
/*    pinReadIntervalTimer = new QTimer(this);
    connect(pinReadIntervalTimer, SIGNAL(timeout()), this, SLOT(readPinValues()));
    timer->start(1000);*/
}

ButtonReader::~ButtonReader()
{
}

void ButtonReader::setReadModePinMask(quint32 bitmask)
{
    readmodePins = bitmask;
    for( int pin = 0 ; pin < MAX_NUM_IO_PINS_FROM_WIRINGPI ; ++pin )
    {
        if( (0x1 << pin) & bitmask )
        {
            pinMode(pin, INPUT);
        }
    }
    emit readModePinMaskChanged();
    readPinValues();
}

quint32 ButtonReader::getReadModePinMask()
{
    return readmodePins;
}

bool ButtonReader::getPin0ButtonPressed()
{
    return pin0ButtonPressed;
}

void ButtonReader::readPinValues()
{
    for( int pin = 0 ; pin < MAX_NUM_IO_PINS_FROM_WIRINGPI ; ++pin )
    {
        bool newValue = false;
        if( (0x1 << pin) & readmodePins )
        {
            newValue = (LOW == digitalRead(pin));
        }
        if( 0 == pin )
        {
            if( pin0ButtonPressed != newValue )
            {
                pin0ButtonPressed = newValue;
                emit pin0ButtonPressedChanged();
            }
        }
        if( 1 == pin )
        {
            pin1ButtonPressed = newValue;
        }
        if( 16 == pin )
        {
            pin16ButtonPressed = newValue;
        }
    }
}
