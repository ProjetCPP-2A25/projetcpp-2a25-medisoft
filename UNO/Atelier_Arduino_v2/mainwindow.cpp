#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    volume(50) // Initialize volume level
{
    ui->setupUi(this);


    int ret = A.connect_arduino();
    switch(ret) {
        case(0): qDebug() << "Arduino connecté sur :" << A.getarduino_port_name(); break;
        case(1): qDebug() << "Arduino disponible mais non connecté."; break;
        case(-1): qDebug() << "Arduino non disponible."; break;
    }
    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::update_label() {
    data = A.read_from_arduino();
    if (data.startsWith("T:")) {
        QString tempString = data.mid(2);
        bool ok;
        float temperature = tempString.toFloat(&ok);
        if (ok) {
            ui->label_temperature->setText(QString::number(temperature));

            // Check if temperature exceeds threshold
            if (temperature > 20.0) { // Example threshold
                A.beep(); // Send beep command to Arduino
            }
        }
    }
}

void MainWindow::on_pushButton_plus_clicked() {
    if (volume < 100) { // Limit volume to 100
        volume += 10; // Increment volume
        // Update UI or send volume level if necessary
        ui->label_volume->setText(QString::number(volume)); // Update volume label
    }
}

void MainWindow::on_pushButton_minus_clicked() {
    if (volume > 0) { // Limit volume to 0
        volume -= 10; // Decrement volume
        // Update UI or send volume level if necessary
        ui->label_volume->setText(QString::number(volume)); // Update volume label
    }
}
