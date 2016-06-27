#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include <QObject>
class LedController : public QObject
{
    friend class LedControllerUT;
public:
    LedController();
    virtual ~LedController();
    int getGpioPinNumber();
    void setGpioPinNumber(int pinNumber);
    bool getLedLightOn();
    void setLedLightOn(bool isOn);
signals:
    void gpioPinNumberChanged();
    void ledLightOnChanged();
private:
    Q_OBJECT
    Q_PROPERTY(int gpioPinNumber READ getGpioPinNumber WRITE setGpioPinNumber NOTIFY gpioPinNumberChanged)
    Q_PROPERTY(bool ledLightOn READ getLedLightOn WRITE setLedLightOn NOTIFY ledLightOnChanged)
    int gpioPinNumber;
    bool ledLightOn;
};

#endif // LEDCONTROLLER_H
