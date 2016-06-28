import QtQuick 2.3
import QtTest 1.0
import "../QML"

TestCase {
    name: "LedSwitchTests"
    width: 300
    height: 200
    when: windowShown

    LedSwitch {
        id: switchToTest
    }

    function test_initial_values() {
        compare(switchToTest.color, "#0000ff")
        compare(switchToTest.pinNumber, -1)
        compare(switchToTest.checked, false)
    }
}
