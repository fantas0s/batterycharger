import QtQuick 2.3
import QtQuick.Controls 2.0
import mygpio.buttonreader 1.0

Rectangle {
    id: __liteableItem
    property int pin: -1
    color: "red"
    ButtonReader {
        id: _buttonState
        pin: __liteableItem.pin
        onPressed: {
            __liteableItem.color = "#50FF50";
        }
        onReleased: {
            __liteableItem.color = "red";
        }
    }
}
