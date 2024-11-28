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
    void update_label();
    void on_pushButton_plus_clicked();  // Button "+"
    void on_pushButton_minus_clicked(); // Button "-"

private:
    Ui::MainWindow *ui;
    QByteArray data;
    Arduino A;
    int volume; // Variable to track volume level

};

#endif // MAINWINDOW_H
