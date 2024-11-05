#include "fournisseur.h"
#include "qsqlerror.h"
#include <QDebug>

bool Fournisseur::ajouter()
{
    QSqlQuery query;

    // Conversion des valeurs numériques en QString
    QString id_string = QString::number(IDF);
    QString QUANTITER_string = QString::number(QUANTITER);

    QString PRIXLEVRISON_string = QString::number(PRIXLEVRISON);

    // Préparation de la requête
    query.prepare("INSERT INTO FOURNISSEUR (IDF, QUANTITER, NOM, PRENOM, MAIL, PRIXLEVRISON) "
                  "VALUES (:IDF, :QUANTITER, :NOM, :PRENOM, :MAIL, :PRIXLEVRISON)");

    // Binding des valeurs
    query.bindValue(":IDF", IDF);
    query.bindValue(":QUANTITER", QUANTITER);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON);


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

    return model;
}


bool Fournisseur::modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(IDF);
    QString QUANTITER_string = QString::number(QUANTITER);
    QString PRIXLEVRISON_string = QString::number(PRIXLEVRISON);

    query.prepare("UPDATE FOURNISSEUR SET QUANTITER=:QUANTITER, NOM=:NOM, PRENOM=:PRENOM, MAIL=:MAIL, PRIXLEVRISON=:PRIXLEVRISON WHERE IDF=:id");

    query.bindValue(":id", IDF);
    query.bindValue(":QUANTITER", QUANTITER);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON);

    return query.exec();
}
