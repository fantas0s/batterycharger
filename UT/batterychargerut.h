#ifndef BATTERYCHARGERUT_H
#define BATTERYCHARGERUT_H
#include <QObject>
class BatteryChargerUT : public QObject
{
    Q_OBJECT

public:
    BatteryChargerUT();

private Q_SLOTS:
    void blinkLed();
};
#endif // BATTERYCHARGERUT_H
