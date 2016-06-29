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
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
    }
}
