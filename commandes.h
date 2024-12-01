#ifndef COMMANDES_H
#define COMMANDES_H


#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QZXing.h>
#include <QPixmap>
#include <QLabel>


class Commandes
{
public:
    Commandes getCommandeByIdc(int idc) {
        Commandes commande;


        QSqlQuery query;
        query.prepare("SELECT * FROM COMMANDES WHERE IDC = :idc");
        query.bindValue(":idc", idc);

        if (query.exec() && query.next()) {

            commande.setIdc(query.value(0).toInt());
            commande.setQuantite(query.value(1).toInt());
            commande.setDate(query.value(2).toDate());
            commande.setPrix(query.value(3).toFloat());
            commande.setIdf(query.value(4).toInt());
        } else {

            commande.isValid = false;
        }

        return commande;
    }

    Commandes(int idc = 0, int quant = 0, QDate dates = QDate(), float prix_pr = 0.0, int idf = 0)
        : idc(idc), quant(quant), dates(dates), prix_pr(prix_pr), idf(idf) {}


    void setIdc(int idc) { this->idc = idc; }
    void setQuantite(int quant) { this->quant = quant; }
    void setDate(QDate date) { this->dates = date; }
    void setPrix(float prix) { this->prix_pr = prix; }
    void setIdf(int idf) { this->idf = idf; }
     bool isValidCommande() const { return isValid; }
    // Getters pour accéder aux membres privés
    int getIdc() const { return idc; }
    int getQuant() const { return quant; }
    QDate getDates() const { return dates; }
    float getPrix() const { return prix_pr; }
    int getIdf() const { return idf; }



    bool ajouter();
    bool existeIDC(int idc);
    bool supprimer(int idc);
    bool modifier();
    bool verifierCode(const QString& code);

    QStandardItemModel* afficher();
    QStandardItemModel* rechercherParTexte(const QString& text);
    QStandardItemModel* filtrer();
    QStandardItemModel* rechercherParIdc(const QString& text);


    QImage generateQRCode(int idc);

private:
    int idc;
    int quant;
    QDate dates;
    float prix_pr;
    int idf;
    bool isValid = true;
};

#endif // COMMANDES_H
