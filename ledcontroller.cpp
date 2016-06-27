#include "ledcontroller.h"
#include "wiringPi/wiringPi/wiringPi.h"
#include <QDebug>

LedController::LedController() :
    gpioPinNumber(-1),
    ledOn(false)
{
}

LedController::~LedController()
{
}

int LedController::getGpioPinNumber()
{
    return gpioPinNumber;
}

void LedController::setGpioPinNumber(const int pinNumber)
{
    if( pinNumber < 7 )
    {
        if( gpioPinNumber >= 0 )
        {
            digitalWrite(gpioPinNumber, LOW);
            emit ledOnChanged();
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

bool LedController::getLedOn()
{
    return ledOn;
}

void LedController::setLedOn(const bool isOn)
{
    if( gpioPinNumber >= 0 )
    {
        if( isOn != ledOn )
        {
            emit ledOnChanged();
        }
        if( isOn )
        {
            digitalWrite(gpioPinNumber, HIGH);
        }
        else
        {
            digitalWrite(gpioPinNumber, LOW);
        }
        ledOn = isOn;
    }
}
