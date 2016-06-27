#include "../wiringPi/wiringPi/wiringPi.h"
#include <QTest>

int pinSetByModeMock = -1;
int modeSetByModeMock = -1;
int pinSetByWriteMock = -1;
int valueSetByWriteMock = -1;

void pinMode (int pin, int mode)
{
    pinSetByModeMock = pin;
    modeSetByModeMock = mode;
}


void digitalWrite (int pin, int value)
{
    pinSetByWriteMock = pin;
    valueSetByWriteMock = value;
}
