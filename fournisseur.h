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

public:
    // Constructeurs
    Fournisseur() {}
    Fournisseur(int IDF, int QUANTITER, QString NOM, QString PRENOM,
                QString MAIL, float PRIXLEVRISON)
    {
        this->IDF = IDF;
        this->QUANTITER = QUANTITER;
        this->NOM = NOM;
        this->PRENOM = PRENOM;
        this->MAIL = MAIL;

        this->PRIXLEVRISON = PRIXLEVRISON;
    }

    // Getters
    int getIDF() const { return IDF; }
    int getQUANTITER() const { return QUANTITER; }
    QString getNOM() const { return NOM; }
    QString getPRENOM() const { return PRENOM; }
    QString getMAIL() const { return MAIL; }

    float getPRIXLEVRISON() const { return PRIXLEVRISON; }

    // Setters
    void setIDF(int id) { this->IDF = id; }
    void setQUANTITER(int q) { this->QUANTITER = q; }
    void setNOM(QString n) { this->NOM = n; }
    void setPRENOM(QString p) { this->PRENOM = p; }
    void setMAIL(QString m) { this->MAIL = m; }

    void setPRIXLEVRISON(float prix) { this->PRIXLEVRISON = prix; }

    // Fonctions CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int IDF);
    bool modifier();
};

#endif // FOURNISSEUR_H
