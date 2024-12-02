#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    volume(50) // Initialize volume level
{
    ui->setupUi(this);

    // Create and add temperature trend widget
        temperatureTrend = new TemperatureTrend(this);
        ui->verticalLayout->addWidget(temperatureTrend);  // Add to existing layout

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

// Update volume control methods:
void MainWindow::on_pushButton_plus_clicked() {
    if (volume < 100) {
        volume += 10;
        ui->label_volume->setText(QString::number(volume));
        A.setVolume(volume);  // Send volume to Arduino
    }
}

void MainWindow::on_pushButton_minus_clicked() {
    if (volume > 0) {
        volume -= 10;
        ui->label_volume->setText(QString::number(volume));
        A.setVolume(volume);  // Send volume to Arduino
    }
}

// Update the temperature update method:
void MainWindow::update_label() {
    data = A.read_from_arduino();
    if (data.startsWith("T:")) {
        QString tempString = data.mid(2);
        bool ok;
        float temperature = tempString.toFloat(&ok);
        if (ok) {
            ui->label_temperature->setText(QString::number(temperature));
            temperatureTrend->addTemperature(temperature);  // Update trend

            if (temperature > 20.0) {
                A.beep();
            }
        }
    }
}
