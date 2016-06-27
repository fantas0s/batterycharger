import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible:true
    width: Screen.width
    height: Screen.height

    Rectangle {
        id: root
        anchors.fill: parent
        color: ledLighter.ledOn ? "green" : "red"
        LedButton {
            id: ledLighter
            anchors.centerIn: parent
        }
    }
}
