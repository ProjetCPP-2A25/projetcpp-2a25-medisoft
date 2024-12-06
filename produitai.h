#ifndef PRODUITAI_H
#define PRODUITAI_H


#include <QString>
#include <QStringList>
#include <QVector>


class ProduitAI {
public:
    // Constructeur
    ProduitAI(const QString& code, const QString& type);

    // Getter pour le tableau
    QStringList getTab() const;

    // Setters pour les fils OUI et NON
    void setOUI(ProduitAI* oui);
    void setNON(ProduitAI* non);
    void setCode(const QString& newCode);


    // Accesseurs
    QString getCode() const;
    QString getType() const;
    ProduitAI* getOUI() const;  // Retourne le pointeur vers le fils droit (OUI)
    ProduitAI* getNON() const;  // Retourne le pointeur vers le fils gauche (NON)


    void remplirTab();
    void supprimerArbre();

    void afficherArbre(int niveau = 0);

    int comparerTab(const ProduitAI* autreProduit) ;
    void afficherProduit() const ;





public:
    QString code;
    QString type;
    QStringList tab;            // Tableau des types
    ProduitAI* OUI = nullptr;   // Fils droit
    ProduitAI* NON = nullptr;   // Fils gauche
    int nbr;
};


#endif // PRODUITAI_H
