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
signals:
    void gpioPinNumberChanged();
private:
    Q_OBJECT
    Q_PROPERTY(int gpioPinNumber READ getGpioPinNumber WRITE setGpioPinNumber NOTIFY gpioPinNumberChanged)
    int gpioPinNumber;
};

#endif // LEDCONTROLLER_H
