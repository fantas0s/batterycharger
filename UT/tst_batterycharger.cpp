#include <QString>
#include <QtTest>
#include "ledcontrollerut.h"

int main(int argc, char *argv[])
{
    BatteryChargerUT bcUT;
    QTEST_SET_MAIN_SOURCE_PATH
    int returnValue = QTest::qExec(&bcUT, argc, argv);
    return returnValue;
}

#include "tst_batterychargerut.moc"
