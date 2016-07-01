#include "buttonreader.h"
#include "wiringPi/wiringPi/wiringPi.h"
#include <QDebug>

#define MAX_NUM_IO_PINS_FROM_WIRINGPI 17

ButtonReader::ButtonReader() :
    pinToRead(-1),
    buttonDown(false)
{
    readIntervalTimer = new QTimer(this);
    connect(readIntervalTimer, SIGNAL(timeout()), this, SLOT(readValueOfPin()));
    readIntervalTimer->start(100);
}

ButtonReader::~ButtonReader()
{
}

void ButtonReader::setPin(int pin)
{
    if( (pin < 0) ||
        (pin >= MAX_NUM_IO_PINS_FROM_WIRINGPI) )
    {
        qDebug() << "Trying to set invalid pin" << pin;
    }
    else
    {
        pinMode(pin, INPUT);
        pinToRead = pin;
        emit pinChanged();
        readValueOfPin();
    }
}

int ButtonReader::getPin()
{
    return pinToRead;
}

void ButtonReader::readValueOfPin()
{
    if( (0<=pinToRead) &&
        (MAX_NUM_IO_PINS_FROM_WIRINGPI>pinToRead) )
    {
        bool newValue = (LOW == digitalRead(pinToRead));
        if( newValue != buttonDown )
        {
            buttonDown = newValue;
            if( buttonDown )
                emit pressed();
            else
                emit released();
        }
    }
}
