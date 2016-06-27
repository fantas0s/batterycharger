#include <QtQuickTest/quicktest.h>
#include "../ledcontroller.h"
#include <QQmlApplicationEngine>

int main(int argc, char **argv)
{
    QTEST_ADD_GPU_BLACKLIST_SUPPORT
    QTEST_SET_MAIN_SOURCE_PATH
    qmlRegisterType<LedController>("mygpio.ledcontroller", 1, 0, "LedController");
    return quick_test_main(argc, argv, "batteryChargerQMLTests", QUICK_TEST_SOURCE_DIR); \
}

