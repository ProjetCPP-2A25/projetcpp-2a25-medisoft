#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("CPP_Project");//inserer le nom de la source de données
    db.setUserName("mohamedlaid");//inserer nom de l'utilisateur
    db.setPassword("oracle");

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données :\n" + db.lastError().text());
    } else {
        qDebug() << "Connexion à la base de données réussie.";
    }

    int ret = A.connect_arduino("COM8");  // Connexion au port COM8
    switch (ret) {
    case 0:
        qDebug() << "Arduino connecté sur :" << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Erreur : Impossible de se connecter à l'Arduino.";
        break;
    case -1:
        qDebug() << "Arduino non disponible";
        break;
    }

    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(handleArduinoResponse()));
    connect(ui->sendCodeButton, SIGNAL(clicked()), this, SLOT(sendCode()));
    connect(ui->openServoButton, SIGNAL(clicked()), this, SLOT(openServo()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::sendCode() {
    QString enteredCode = ui->codeInput->text(); // Lire le code entré
    if (enteredCode.isEmpty()) {
        ui->statusLabel->setText("Veuillez entrer un code !");
        return;
    }

    // Vérification dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEURES WHERE IDF = :code"); // Table : "Codes", Colonne : "code"
    query.bindValue(":code", enteredCode);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification du code :\n" + query.lastError().text());
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count > 0) {
        ui->statusLabel->setText("Code valide, porte ouverte !");
        QByteArray command = "1"; // Commande pour ouvrir le servo
        A.write_to_arduino(command);
        qDebug() << "Code valide, commande envoyée à l'Arduino.";
    } else {
        ui->statusLabel->setText("Code invalide !");
        qDebug() << "Code invalide.";
    }
}


void MainWindow::handleArduinoResponse() {
    QByteArray receivedData = A.read_from_arduino(); // Lire les données reçues
    static QString inputBuffer; // Buffer pour accumuler les données

    inputBuffer += QString(receivedData); // Ajouter les nouvelles données au buffer

    // Vérifier si une ligne complète a été reçue
    if (inputBuffer.contains('\n')) {
        QStringList messages = inputBuffer.split('\n'); // Diviser les données par lignes
        for (int i = 0; i < messages.size() - 1; ++i) {
            QString message = messages[i].trimmed(); // Supprimer les espaces inutiles
            qDebug() << "Message reçu: " << message; // Log du message reçu

            if (message.startsWith("KEY:")) {
                // Extraire la touche
                QString key = message.mid(4); // Supprimer "KEY:"
                qDebug() << "Touche reçue: " << key; // Log de la touche

                // Ajouter la touche au champ de texte
                ui->codeInput->setText(ui->codeInput->text() + key); // Ajouter la touche à l'entrée
            } else if (message == "CLEAR") {
                // Effacer le champ de texte
                ui->codeInput->clear();
            }
                else {
                 verifyCodeAndOpenServo();

            }
        }

        // Garder les données restantes (incomplètes) dans le buffer
        inputBuffer = messages.last();
    }
}


void MainWindow::verifyCodeAndOpenServo() {
    QString enteredCode = ui->codeInput->text(); // Lire le code entré
    if (enteredCode.isEmpty()) {
        ui->statusLabel->setText("Veuillez entrer un code !");
        return;
    }

    // Vérification dans la base de données
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEURES WHERE IDF = :code"); // Table : "FOURNISSEURES", Colonne : "IDF"
    query.bindValue(":code", enteredCode);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification du code :\n" + query.lastError().text());
        return;
    }

    query.next();
    int count = query.value(0).toInt();

    if (count > 0) {
        ui->statusLabel->setText("Code valide, porte ouverte !");
        QByteArray command = "1"; // Commande pour ouvrir le servo
        A.write_to_arduino(command); // Envoyer la commande à Arduino
        qDebug() << "Code valide, commande envoyée à l'Arduino.";
    } else {
        ui->statusLabel->setText("Code invalide !");
        qDebug() << "Code invalide.";
    }
}




void MainWindow::openServo() {
    A.write_to_arduino("1"); // Envoyer une commande pour ouvrir le servo
    ui->statusLabel->setText("Commande pour ouvrir le servo envoyée.");
    qDebug() << "Commande pour ouvrir le servo envoyée.";
}
