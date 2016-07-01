import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible:true
    width: Screen.width
    height: Screen.height

    Rectangle {
        id: root
        anchors.fill: parent
        color: "black"
        ButtonLight {
            id: buttonReacter
            pin: 0
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        LedButton {
            gpioPin: 2
            anchors.bottom: buttonReacter.top
            anchors.left: buttonReacter.left
        }

        LedSwitch {
            pinNumber: 1
            anchors.top: buttonReacter.bottom
            anchors.left: buttonReacter.left
            color: "green"
        }
    }
}
