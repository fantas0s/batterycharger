import QtQuick 2.3
import QtQuick.Controls 2.0
import mygpio.ledcontroller 1.0

Button {
    id: __ledLightButton
    text: "Press to light LED"
    property bool ledOn: false
    property int gpioPin: 0
    LedController {
        gpioPinNumber: __ledLightButton.gpioPin
        ledLightOn: __ledLightButton.ledOn
    }

    onClicked: {
        __ledLightButton.ledOn = !__ledLightButton.ledOn;
    }
}
