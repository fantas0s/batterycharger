import QtQuick 2.3
import QtQuick.Controls 2.0
import mygpio.ledcontroller 1.0

Button {
    text: "Press to light LED"
    LedController {
        id: ledControl
        gpioPinNumber: 0
    }

    onClicked: {
        ledControl.gpioPinNumber = 1;
    }
}
