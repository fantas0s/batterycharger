#ifndef BATTERYCHARGERUT_H
#define BATTERYCHARGERUT_H
#include <QObject>

class LedControllerUT : public QObject
{
    Q_OBJECT

public:
    LedControllerUT();

private Q_SLOTS:
    void readWriteGPIOPinNumber();
};
#endif // BATTERYCHARGERUT_H
