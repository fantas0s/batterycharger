#include <QString>
#include <QtTest>

class BatteryChargerUT : public QObject
{
    Q_OBJECT

public:
    BatteryChargerUT();

private Q_SLOTS:
    void blinkLed();
};

BatteryChargerUT::BatteryChargerUT()
{
}

void BatteryChargerUT::blinkLed()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BatteryChargerUT)

#include "tst_batterychargerut.moc"
