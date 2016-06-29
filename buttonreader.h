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
    void setReadModePinMask(quint32 bitmask);
    quint32 getReadModePinMask();
    bool getPin0ButtonPressed();
signals:
    void readModePinMaskChanged();
    void pin0ButtonPressedChanged();
public slots:
    void readPinValues();
private:
    Q_OBJECT
    Q_PROPERTY(quint32 readmodePinmask READ getReadModePinMask WRITE setReadModePinMask NOTIFY readModePinMaskChanged)
    Q_PROPERTY(bool pin0ButtonPressed READ getPin0ButtonPressed NOTIFY pin0ButtonPressedChanged)
    quint32 readmodePins;
    bool pin0ButtonPressed;
    bool pin1ButtonPressed;
    bool pin16ButtonPressed;
    QTimer *pinReadIntervalTimer;
};

#endif // BUTTONREADER_H
