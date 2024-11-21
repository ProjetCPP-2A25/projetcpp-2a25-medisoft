#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Patient
{
    int IDP,AGE,TEL;
    QString NOM ,PRENOM,MAIL,GENRE;
public:
    //Constructeurs
    Patient(){}
    Patient(int,QString,QString,QString,QString,int,int);

    //getters
    int getidp(){return IDP;}
    QString getnom(){return NOM;}
    QString getprenom(){return PRENOM;}
    QString getmail(){return MAIL;}
    QString getgenre(){return GENRE;}
    int getage(){return AGE;}
    int gettel(){return TEL;}

    //setters
    void setidp (int id){this->IDP=id;}
    void setnom (QString n){NOM=n;}
    void setprenom (QString p){PRENOM=p;}
    void setmail (QString m){MAIL=m;}
    void setngenre (QString g){GENRE=g;}
    void setage (int a){this->AGE=a;}
    void settel (int t){this->TEL=t;}

    //fonctions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool suprimer(int);
    bool modifier(int id, const QString& n, const QString& p, const QString& m, const QString& g, int a, int t);
    std::unique_ptr<QSqlQueryModel> rechercher(int id);
    QMap<QString, double> calculerStatistiquesMoyenT();
    void exportToPDF();



};

#endif // PATIENT_H
