#include <QString>
#include <QtTest>
#include "ledcontrollerut.h"

int main(int argc, char *argv[])
{
    LedControllerUT lcUT;
    QTEST_SET_MAIN_SOURCE_PATH
    int returnValue = QTest::qExec(&lcUT, argc, argv);
    return returnValue;
}

#include "tst_batterychargerut.moc"
