#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>


class Employee {
public:
     Employee();
    Employee(int id,  QString nom,  QString prenom, QString mail,  QDate dateEmbauche,  QString salaire,  QString telephone,QString ROLE);
    // Getters
    int getId() ;
    QString getNom() ;
    QString getPrenom() ;
    QString getMail() ;
    QString getSalaire() ;
    QString getTelephone() ;
    QDate getDateEmbauche() ;
    QString getROLE();
    QString getmessage();
    // Setters
    void setNom( QString nom);
    void setPrenom( QString prenom);
    void setMail( QString mail);
    void setSalaire(QString salaire);
    void setTelephone( QString telephone);
    void setDateEmbauche( QDate dateEmbauche);
    void setROLE(QString ROLE);
    void setmessage(QString message);
    // Méthodes de gestion
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id, QString nom, QString prenom, QString mail, QDate dateEmbauche, QString salaire,QString telephone, QString ROLE);
    QSqlQueryModel* afficher() ;
    // Méthodes auxiliaires
    bool employeeExists(int id) ;
    QSqlQueryModel* tri(QString column);
    QSqlQueryModel* tri1(QString column);

    QSqlQueryModel* chercher(QString column,QString text);
    int countRole(const QString& role);
    QString chercherEMAIL(int id);

private:
    // Attributs
    int id;
    QString nom;
    QString prenom;
    QString mail;
    QDate dateEmbauche;
    QString salaire;
    QString telephone;
    QString ROLE;
    QString message;
};



#endif // EMPLOYES_H
