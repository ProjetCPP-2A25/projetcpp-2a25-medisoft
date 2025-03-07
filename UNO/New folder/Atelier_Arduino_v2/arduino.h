#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino {
public:
    Arduino();
    int connect_arduino();
    QByteArray read_from_arduino();
    void beep(); // Method to send beep command to Arduino
    QSerialPort* getserial();
    QString getarduino_port_name();
    void setVolume(int volume);

private:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUINO_H
