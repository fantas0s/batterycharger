#ifndef BUTTONREADERUT_H
#define BUTTONREADERUT_H
#include <QObject>

class ButtonReaderUT : public QObject
{
    Q_OBJECT

public:
    ButtonReaderUT();
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void readInitialValues();
    void checkModeChangesByBitmask();
    void checkValueUpdatesBySignal();
    void uninitializedValues();
};
#endif // BUTTONREADERUT_H
