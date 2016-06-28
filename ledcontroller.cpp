#include "ledcontroller.h"
#include "wiringPi/wiringPi/wiringPi.h"
#include <QDebug>

#define MAX_NUM_IO_PINS_FROM_WIRINGPI 17

LedController::LedController() :
    gpioPinNumber(-1),
    ledLightOn(false)
{
}

LedController::~LedController()
{
}

int LedController::getGpioPinNumber()
{
    return gpioPinNumber;
}

void LedController::setGpioPinNumber(int pinNumber)
{
    if( pinNumber < MAX_NUM_IO_PINS_FROM_WIRINGPI )
    {
        if( gpioPinNumber >= 0 )
        {
            digitalWrite(gpioPinNumber, LOW);
            emit ledLightOnChanged();
        }
        pinMode(pinNumber, OUTPUT);
        gpioPinNumber = pinNumber;
        emit gpioPinNumberChanged();
    }
    else
    {
        qDebug() << "Attempt to change GPIO PIN from" << gpioPinNumber << "to invalid" << pinNumber;
    }
}

bool LedController::getLedLightOn()
{
    return ledLightOn;
}

void LedController::setLedLightOn(bool isOn)
{
    if( gpioPinNumber >= 0 )
    {
        if( isOn != ledLightOn )
        {
            emit ledLightOnChanged();
        }
        if( isOn )
        {
            digitalWrite(gpioPinNumber, HIGH);
        }
        else
        {
            digitalWrite(gpioPinNumber, LOW);
        }
        ledLightOn = isOn;
    }
}
