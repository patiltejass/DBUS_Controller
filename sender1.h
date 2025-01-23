#ifndef SENDER1_H
#define SENDER1_H

#include <QObject>
#include <QDBusConnection>

class Sender1 : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.example.DBusDemo.Sender")

public:
    explicit Sender1(QObject *parent = nullptr);

signals:
    void button1Pressed(bool value);
    void button2Pressed(bool value);
    void button3Pressed(bool value);

public slots:
    Q_INVOKABLE void emitButton1();
    Q_INVOKABLE void emitButton2();
    Q_INVOKABLE void emitButton3();

private:
    bool val1 = false;
    bool val2 = false;
    bool val3 = false;
};

#endif // SENDER1_H
