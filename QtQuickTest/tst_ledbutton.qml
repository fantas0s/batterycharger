import QtQuick 2.3
import QtTest 1.0
import "../QML"

TestCase {
    name: "LedButtonTests"

    LedButton {
        id: buttonToTest
    }

    function test_text() {
        compare(buttonToTest.text, "Press to light LED")
    }
}
