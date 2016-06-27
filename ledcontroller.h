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
    void setGpioPinNumber(const int pinNumber);
    bool getLedOn();
    void setLedOn(const bool isOn);
signals:
    void gpioPinNumberChanged();
    void ledOnChanged();
private:
    Q_OBJECT
    Q_PROPERTY(int gpioPinNumber READ getGpioPinNumber WRITE setGpioPinNumber NOTIFY gpioPinNumberChanged)
    Q_PROPERTY(bool ledOn READ getLedOn WRITE setLedOn NOTIFY ledOnChanged)
    int gpioPinNumber;
    bool ledOn;
};

#endif // LEDCONTROLLER_H
