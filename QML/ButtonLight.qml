import QtQuick 2.3
import QtQuick.Controls 2.0
import mygpio.buttonreader 1.0

Rectangle {
    id: __liteableItem
    property int pinMask: 0x1ffff
    color: "red"
    ButtonReader {
        id: _buttonState
        readmodePinmask: __liteableItem.pinMask
        onPin0ButtonPressedChanged: {
            if( pin0ButtonPressed )
                __liteableItem.color = "#50FF50";
            else
                __liteableItem.color = "red";
        }
    }
}
