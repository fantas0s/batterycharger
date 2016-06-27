import QtQuick 2.3
import QtTest 1.0
import "../QML"

TestCase {
    name: "LedButtonTests"
    width: 300
    height: 200
    when: windowShown

    LedButton {
        id: buttonToTest
    }

    function test_text() {
        compare(buttonToTest.text, "Press to light LED")
        compare(buttonToTest.ledOn, false)
        compare(buttonToTest.gpioPin, 0)
    }
}
