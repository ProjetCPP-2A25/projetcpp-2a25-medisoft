#include "arduino.h"

Arduino::Arduino() {
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino::getarduino_port_name() {
    return arduino_port_name;
}

QSerialPort* Arduino::getserial() {
    return serial;
}

int Arduino::connect_arduino(const QString &portName) {
    arduino_is_available = false; // Réinitialiser à chaque tentative de connexion
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.portName() == portName) {
            arduino_is_available = true;
            arduino_port_name = serial_port_info.portName();
            break;
        }
    }

    qDebug() << "Arduino port name is :" << arduino_port_name;
    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0; // Connexion réussie
        }
        return 1;  // Échec de l'ouverture du port
    }
    return -1;  // Arduino non disponible
}

int Arduino::close_arduino() {
    if (serial->isOpen()) {
        serial->close();
        return 0; // Fermeture réussie
    }
    return 1; // Le port n'était pas ouvert
}

QByteArray Arduino::read_from_arduino() {
    if (serial->isReadable()) {
        data = serial->readAll();
        return data;
    }
    return QByteArray(); // Aucune donnée lue
}

void Arduino::write_to_arduino(QByteArray d) {
    if (serial->isWritable()) {
        serial->write(d);
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}
