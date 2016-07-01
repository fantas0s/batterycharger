#ifndef BUTTONREADER_H
#define BUTTONREADER_H
#include <QObject>
#include <QTimer>
class ButtonReader : public QObject
{
    friend class ButtonReaderUT;
public:
    ButtonReader();
    virtual ~ButtonReader();
    void setPin(int pin);
    int getPin();
signals:
    void pinChanged();
    void pressed();
    void released();
public slots:
    void readValueOfPin();
private:
    Q_OBJECT
    Q_PROPERTY(quint32 pin READ getPin WRITE setPin NOTIFY pinChanged)
    int pinToRead;
    bool buttonDown;
    QTimer *readIntervalTimer;
};

#endif // BUTTONREADER_H
