#ifndef PRODUITS_H
#define PRODUITS_H

#include <QByteArray> // Pour l'image
#include <QDate>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class produits
{
    int CODE;
    float PRIX;
    QDate DATE_EXP;
    int QUANTITEE;
    QString DESCRIPTION;
    QString NOM;
    QString TYPE;
    QByteArray IMAGE; // Nouvel attribut pour l'image

public:
    produits();
    produits(int, float, QDate, int, QString, QString, QString, const QString &imagePath);

    int getcode() const { return CODE; }
    QString getdesc() const { return DESCRIPTION; }
    QString getnom() const { return NOM; }
    QString gettype() const { return TYPE; }
    QDate getDate_exp() const { return DATE_EXP; }
    float getprix() const { return PRIX; }
    int getqte() const { return QUANTITEE; }
    QByteArray getimage() const { return IMAGE; } // Getter pour l'image
    QByteArray getImageFromDatabase(int codeP);

    QByteArray imageToByteArray(const QString &imagePath);

    void setcode(const int &codeP) { CODE = codeP; }
    void setprix(const float &prixP) { PRIX = prixP; }
    void setdate_exp(const QDate &dateP) { DATE_EXP = dateP; }
    void setqte(const int &qteP) { QUANTITEE = qteP; }
    void setdesc(const QString &descP) { DESCRIPTION = descP; }
    void setnom(const QString &nomP) { NOM = nomP; }
    void settype(const QString &typeP) { TYPE = typeP; }
    void setimage(const QByteArray &imageP) { IMAGE = imageP; } // Setter pour l'image

    //bool ajouter();
    // Déclarez la méthode ajouter avec le paramètre imagePath
    bool ajouter(const QString &imagePath);

    std::unique_ptr<QSqlQueryModel> afficher();
    bool modifier(int codeP,
                  float prixP,
                  const QDate &dateP,
                  int qteP,
                  const QString &descP,
                  const QString &nomP,
                  const QString &typeP,
                  const QByteArray &imageP);
    bool supprimer(int);
    std::unique_ptr<QSqlQueryModel> rechercher(int);
    std::unique_ptr<QSqlQueryModel> trier(const QString &critere, const QString &ordre);
    void afficherImage(QLabel *label, int codeP);

    std::unique_ptr<QSqlQueryModel> afficher2();
};

#endif // PRODUITS_H
