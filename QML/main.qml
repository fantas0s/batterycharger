import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible:true
    width: Screen.width
    height: Screen.height

    Item {
        id: root
        anchors.fill: parent

        Button {
            anchors.centerIn: parent
            text: "Press to light LED"
            onClicked: {

            }
        }
    }
}
