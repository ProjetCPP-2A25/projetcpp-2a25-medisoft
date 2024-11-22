#include "fournisseur.h"
#include "qsqlerror.h"
#include <QDebug>

bool Fournisseur::ajouter()
{
    QSqlQuery query;



    // Préparation de la requête
    query.prepare("INSERT INTO FOURNISSEUR (IDF, QUANTITER, NOM, PRENOM, MAIL, PRIXLEVRISON, RATING,LONGITUDE,LATITUDE) "
                      "VALUES (:IDF, :QUANTITER, :NOM, :PRENOM, :MAIL, :PRIXLEVRISON, :RATING,:LONGITUDE,:LATITUDE)");


    // Binding des valeurs
    query.bindValue(":IDF", IDF);
    query.bindValue(":QUANTITER", QUANTITER);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON);
     query.bindValue(":RATING", rating);
     query.bindValue(":LONGITUDE",LONGITUDE);
     query.bindValue(":LATITUDE",LATITUDE);


    // Exécution de la requête
    return query.exec();
}

bool Fournisseur::supprimer(int IDF)
{
    QSqlQuery query;
    QString id_string = QString::number(IDF);

    query.prepare("DELETE FROM FOURNISSEUR WHERE IDF = :id");
    query.bindValue(":id", IDF);

    return query.exec();
}

QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR");

    if (model->lastError().isValid()) {
        qDebug() << "Error in afficher query:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PréNOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix Livraison"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Rating")); // Add header for rating
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("LONGITUDE"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("LATITUDE"));


    return model;
}
QSqlQueryModel* Fournisseur::affichern()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY NOM ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Error in afficher query:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PréNOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix Livraison"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Rating")); // Add header for rating
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("LONGITUDE"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("LATITUDE"));


    return model;
}
QSqlQueryModel* Fournisseur::affichere()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY RATING ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Error in afficher query:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PréNOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix Livraison"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Rating")); // Add header for rating
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("LONGITUDE"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("LATITUDE"));


    return model;
}


bool Fournisseur::modifier()
{
    QSqlQuery query;


    query.prepare("UPDATE FOURNISSEUR SET QUANTITER=:QUANTITER, NOM=:NOM, PRENOM=:PRENOM, MAIL=:MAIL, PRIXLEVRISON=:PRIXLEVRISON, RATING=:RATING,LATITUDE=:LATITUDE,LONGITUDE=:LONGITUDE WHERE IDF=:id");
    query.bindValue(":id", IDF);
    query.bindValue(":QUANTITER", QUANTITER);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON);
    query.bindValue(":RATING", rating);
     query.bindValue(":LONGITUDE",LONGITUDE);
     query.bindValue(":LATITUDE",LATITUDE);


    return query.exec();
}
QSqlQueryModel* Fournisseur::rechercherParNom(const QString& nom) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (query.exec()) {
        model->setQuery(std::move(query)); // Move the query object
        return model;
    } else {
        qDebug() << "Error filtering by name:" << query.lastError().text();
        delete model; // Free memory if query fails
        return nullptr;
    }
}
int Fournisseur::totalQuantity() {
    QSqlQuery query;
    query.prepare("SELECT SUM(QUANTITER) FROM FOURNISSEUR");
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return 0; // Or handle the error appropriately
}

double Fournisseur::averageDeliveryPrice() {
    QSqlQuery query;
    query.prepare("SELECT AVG(PRIXLEVRISON) FROM FOURNISSEUR");
    if (query.exec() && query.next()) {
        return query.value(0).toDouble();
    }
    return 0.0; // Or handle the error
}
