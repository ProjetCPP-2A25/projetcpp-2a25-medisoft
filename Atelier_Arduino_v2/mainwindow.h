#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "arduino.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendCode();               // Envoi du code à Arduino
    void handleArduinoResponse();  // Traitement de la réponse d'Arduino
    void openServo();        // Envoyer une commande pour ouvrir le servo
    void verifyCodeAndOpenServo();

private:
    Ui::MainWindow *ui;
    Arduino A;                     // Instance d'Arduino
    QByteArray data;               // Données reçues d'Arduino
};

#endif // MAINWINDOW_H
