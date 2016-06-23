#include "ledcontroller.h"
#include <QDebug>

LedController::LedController() :
    gpioPinNumber(-1)
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
    qDebug() << "GPIO PIN changed from" << gpioPinNumber << "to" << pinNumber;
    gpioPinNumber = pinNumber;
    emit gpioPinNumberChanged();
}
