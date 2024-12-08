#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect() {
    // Créer une connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source25"); // Nom de la base de données
    db.setUserName("yassine");
    db.setPassword("yassine123");

    // Essayer d'ouvrir la base de données
    if (!db.open()) {
        return false; // Connexion échouée
    }


    return true; // Connexion réussie
}
