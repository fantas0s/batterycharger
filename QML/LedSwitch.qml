import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import mygpio.ledcontroller 1.0

Switch {
    id: __switch
    property int pinNumber: -1
    property color color: "blue"
    style: SwitchStyle {
        groove: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                color: __switch.color
                radius: 5
        }
    }
    LedController {
        gpioPinNumber: __switch.pinNumber
        ledLightOn: __switch.checked
    }
}
