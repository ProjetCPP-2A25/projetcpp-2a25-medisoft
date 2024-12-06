#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "serialcommunication.h"  // Assurez-vous d'inclure l'en-tête pour SerialCommunication

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Crée une seule instance de QApplication
    MainWindow w;
    Connection c;

    // Essayer de se connecter à la base de données
    bool test = c.createconnect();

    if (test) {
        // Si la connexion est réussie, afficher un message d'information et montrer la fenêtre principale
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        // Si la connexion échoue, afficher un message d'erreur
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    // Créer une instance de SerialCommunication pour gérer la communication série
    SerialCommunication communicator;

    return a.exec();  // Exécuter l'application principale
}
