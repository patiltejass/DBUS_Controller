#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDBus/QtDBus>
#include <QUrl>
#include <QString>
#include "sender1.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qputenv("QT_QUICK_CONTROLS_STYLE", "Material");

    QQmlApplicationEngine engine;

    qmlRegisterType<Sender1>("controller", 1, 0, "Sender1");

    Sender1 sender1;
    engine.rootContext()->setContextProperty("sender1", &sender1);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(QUrl::fromLocalFile("D:/Delta/DBUS/controller/Main.qml"));


    return app.exec();
}
