import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible:true
    width: Screen.width
    height: Screen.height

    Rectangle {
        id: root
        anchors.fill: parent
        color: "grey"
        Column {
            anchors.centerIn: parent
            spacing: 20
            LedSwitch {
                pinNumber: 0
                checked: false
                color: "red"
            }
            LedSwitch {
                pinNumber: 1
                checked: false
                color: "green"
            }
            LedSwitch {
                pinNumber: 2
                checked: false
                color: "yellow"
            }
            LedSwitch {
                pinNumber: 3
                checked: false
                color: "red"
            }
            LedSwitch {
                pinNumber: 4
                checked: false
                color: "green"
            }
            LedSwitch {
                pinNumber: 5
                checked: false
                color: "yellow"
            }
            LedSwitch {
                pinNumber: 6
                checked: false
                color: "red"
            }
            LedSwitch {
                pinNumber: 7
                checked: false
                color: "green"
            }
        }
    }
}
