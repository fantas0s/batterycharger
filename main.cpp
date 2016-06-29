#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ledcontroller.h"
#include "buttonreader.h"
#include "wiringPi/wiringPi/wiringPi.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    wiringPiSetup();
    QQmlApplicationEngine engine;
    qmlRegisterType<LedController>("mygpio.ledcontroller", 1, 0, "LedController");
    qmlRegisterType<ButtonReader>("mygpio.buttonreader", 1, 0, "ButtonReader");
    engine.load(QUrl(QStringLiteral("qrc:/QML/main.qml")));

    return app.exec();
}
