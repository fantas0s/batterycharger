#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ledcontroller.h"
#include "wiringPi/wiringPi/wiringPi.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    wiringPiSetup();
    QQmlApplicationEngine engine;
    qmlRegisterType<LedController>("mygpio.ledcontroller", 1, 0, "LedController");
    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
