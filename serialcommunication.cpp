/*#include "SerialCommunication.h"
#include <QDebug>
#include <QTimer>

SerialCommunication::SerialCommunication(QObject *parent)
    : QObject(parent)
{
    serial = new QSerialPort(this);

    // Rechercher tous les ports disponibles et essayer de se connecter à celui de l'Arduino
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.hasProductIdentifier() && info.hasVendorIdentifier()) {
            serial->setPort(info);
            break;
        }
    }

    // Ouvrir le port série
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Connexion avec Arduino réussie.";
    } else {
        qDebug() << "Erreur de connexion à Arduino.";
        return;
    }

    // Configurer la vitesse du port
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    connect(serial, &QSerialPort::readyRead, this, &SerialCommunication::onReadyRead);
    connect(serial, &QSerialPort::errorOccurred, this, &SerialCommunication::onErrorOccurred);

    // Vérifier le statut de l'Arduino toutes les 2 secondes
    QTimer::singleShot(2000, this, &SerialCommunication::checkArduinoStatus);
}

void SerialCommunication::sendDataToArduino(const QString &data)
{
    if (serial->isOpen()) {
        serial->write(data.toUtf8());
        qDebug() << "Donnée envoyée à Arduino:" << data;
    } else {
        qDebug() << "Port série non ouvert!";
    }
}

void SerialCommunication::checkArduinoStatus()
{
    // Exemple d'envoi de message à Arduino pour obtenir un retour sur l'état
    sendDataToArduino("status?");
}

void SerialCommunication::onReadyRead()
{
    QByteArray data = serial->readAll();
    qDebug() << "Données reçues de l'Arduino:" << data;

    // Analyse de la réponse d'Arduino (vous pouvez vérifier les messages reçus et agir en conséquence)
    if (data.contains("Température haute")) {
        qDebug() << "Température élevée détectée, actionner le ventilateur!";
        sendDataToArduino("ventilator_on");
    } else if (data.contains("Température normale")) {
        qDebug() << "Température normale, éteindre le ventilateur.";
        sendDataToArduino("ventilator_off");
    }
}

void SerialCommunication::onErrorOccurred(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        qDebug() << "Erreur de communication série:" << serial->errorString();
    }
}
*/
