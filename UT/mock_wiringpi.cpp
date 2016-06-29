#include "../wiringPi/wiringPi/wiringPi.h"
#include <QTest>

int modeSetByModeMock[17] = {-1};
int valueSetByWriteMock[17] = {-1};
int pinStatesForReading[17] = {HIGH};

void pinMode (int pin, int mode)
{
    modeSetByModeMock[pin] = mode;
}

void digitalWrite (int pin, int value)
{
    valueSetByWriteMock[pin] = value;
}

int digitalRead(int pin)
{
    return pinStatesForReading[pin];
}
