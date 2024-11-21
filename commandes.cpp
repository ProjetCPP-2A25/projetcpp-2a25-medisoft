#include "commandes.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QSqlQueryModel>

bool Commandes::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO COMMANDES (IDC, QUANT, DATES, PRIX_PR, IDF) "
                  "VALUES (:idc, :quant, :dates, :prix_pr, :idf)");
    query.bindValue(":idc", idc);
    query.bindValue(":quant", quant);
    query.bindValue(":dates", dates);
    query.bindValue(":prix_pr", prix_pr);
    query.bindValue(":idf", idf);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text();
        return false;
    }
}

bool Commandes::supprimer(int idc) {
    QSqlQuery query;
    query.prepare("DELETE FROM COMMANDES WHERE IDC = :idc");
    query.bindValue(":idc", idc);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur de suppression: " << query.lastError().text();
        return false;
    }
}

bool Commandes::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET QUANT = :quant, DATES = :dates, PRIX_PR = :prix_pr, IDF = :idf "
                  "WHERE IDC = :idc");
    query.bindValue(":idc", idc);
    query.bindValue(":quant", quant);
    query.bindValue(":dates", dates);
    query.bindValue(":prix_pr", prix_pr);
    query.bindValue(":idf", idf);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur de modification: " << query.lastError().text();
        return false;
    }
}

QStandardItemModel* Commandes::afficher() {
    QSqlQuery query("SELECT * FROM COMMANDES");
    QStandardItemModel* model = new QStandardItemModel();

    model->setHorizontalHeaderLabels(QStringList() << "IDC" << "Quantité" << "Date" << "Prix" << "IDF");

    int row = 0;
    while (query.next()) {
        model->setItem(row, 0, new QStandardItem(query.value(0).toString()));
        model->setItem(row, 1, new QStandardItem(query.value(1).toString()));
        model->setItem(row, 2, new QStandardItem(query.value(2).toDate().toString("yyyy-MM-dd")));
        model->setItem(row, 3, new QStandardItem(QString::number(query.value(3).toFloat(), 'f', 2)));
        model->setItem(row, 4, new QStandardItem(query.value(4).toString()));
        row++;
    }
    return model;
}

// Fonction de recherche par texte
QStandardItemModel* Commandes::rechercherParIdc(const QString& text) {
    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDES WHERE IDC LIKE :text OR QUANT LIKE :text "
                  "OR DATES LIKE :text OR PRIX_PR LIKE :text OR IDF LIKE :text");
    query.bindValue(":text", "%" + text + "%");

    if (query.exec()) {
        QStandardItemModel* model = new QStandardItemModel();
        model->setHorizontalHeaderLabels(QStringList() << "IDC" << "Quantité" << "Date" << "Prix" << "IDF");

        int row = 0;
        while (query.next()) {
            model->setItem(row, 0, new QStandardItem(query.value(0).toString()));
            model->setItem(row, 1, new QStandardItem(query.value(1).toString()));
            model->setItem(row, 2, new QStandardItem(query.value(2).toDate().toString("yyyy-MM-dd")));
            model->setItem(row, 3, new QStandardItem(QString::number(query.value(3).toFloat(), 'f', 2)));
            model->setItem(row, 4, new QStandardItem(query.value(4).toString()));
            row++;
        }
        return model;
    } else {
        qDebug() << "Erreur de recherche: " << query.lastError().text();
        return nullptr;
    }
}
