#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseur
{
private:
    int IDF;
    int QUANTITER;
    QString NOM;
    QString PRENOM;
    QString MAIL;
    float PRIXLEVRISON;
    int rating;
    int LATITUDE;
    int LONGITUDE;
public:
    // Constructeurs
    Fournisseur() {}
    Fournisseur(int IDF, int QUANTITER, QString NOM, QString PRENOM,
                QString MAIL, float PRIXLEVRISON,int rating,int LATITUDE,int LONGITUDE)
    {
        this->IDF = IDF;
        this->QUANTITER = QUANTITER;
        this->NOM = NOM;
        this->PRENOM = PRENOM;
        this->MAIL = MAIL;

        this->PRIXLEVRISON = PRIXLEVRISON;
        this->rating=rating;
        this->LATITUDE=LATITUDE;
        this->LONGITUDE=LONGITUDE;

    }


    // Getters
    int getIDF() const { return IDF; }
    int getQUANTITER() const { return QUANTITER; }
    QString getNOM() const { return NOM; }
    QString getPRENOM() const { return PRENOM; }
    QString getMAIL() const { return MAIL; }

    float getPRIXLEVRISON() const { return PRIXLEVRISON; }
    int getLATITUDE()const { return LATITUDE;}


    int getRating() const { return rating; }
    void setRating(int r) { rating = r; }

    // Setters
    void setIDF(int id) { this->IDF = id; }

    void setQUANTITER(int q) { this->QUANTITER = q; }
    void setNOM(QString n) { this->NOM = n; }
    void setPRENOM(QString p) { this->PRENOM = p; }
    void setMAIL(QString m) { this->MAIL = m; }

    void setPRIXLEVRISON(float prix) { this->PRIXLEVRISON = prix; }
 void setLONGITUDE(int longi) { this->LONGITUDE = longi; }
    // Fonctions CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* affichere();
    QSqlQueryModel* affichern();
     QSqlQueryModel* afficherdn();
      QSqlQueryModel* afficherde();
    bool supprimer(int IDF);
    bool modifier();
    QSqlQueryModel* rechercherParNom(const QString& nom);
    int totalQuantity();
        double averageDeliveryPrice();
};

#endif // FOURNISSEUR_H
