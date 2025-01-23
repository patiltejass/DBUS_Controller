#include "sender1.h"

Sender1::Sender1(QObject *parent) : QObject(parent)
{
    // Register the object on the session bus
    QDBusConnection connection = QDBusConnection::sessionBus();
    bool objRegistered = connection.registerObject("/Sender", this, QDBusConnection::ExportAllSignals | QDBusConnection::ExportAllSlots);
    bool serviceRegistered = connection.registerService("com.example.DBusDemo.Sender");

    if (!objRegistered)
        qDebug() << "DBus object registration FAILED!";
    else
        qDebug() << "DBus object registered successfully.";

    if (!serviceRegistered)
        qDebug() << "DBus service registration FAILED!";
    else
        qDebug() << "DBus service registered successfully.";

}

void Sender1::emitButton1()
{
    val1=!val1;
    qDebug() << "Button 1 pressed"<<val1;
    emit button1Pressed(val1);
}

void Sender1::emitButton2()
{
    val2=!val2;
    qDebug() << "Button 2 pressed"<<val2;
    emit button2Pressed(val2);
}

void Sender1::emitButton3()
{
    val3=!val3;
    qDebug() << "Button 3 pressed"<<val3;
    emit button3Pressed(val3);
}
