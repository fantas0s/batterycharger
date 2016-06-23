import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible:true
    width: Screen.width
    height: Screen.height

    Item {
        id: root
        anchors.fill: parent
        LedButton {
            anchors.centerIn: parent
        }
    }
}
