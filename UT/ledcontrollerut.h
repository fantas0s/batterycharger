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
    void setGetLedOn();
    void testUnInitializedCalls();
};
#endif // BATTERYCHARGERUT_H
