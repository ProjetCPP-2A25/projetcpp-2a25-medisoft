#include "employes.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
Employee::Employee(int id,  QString nom,  QString prenom,QString mail,  QDate dateEmbauche, QString salaire,  QString telephone,QString ROLE) {
 this->id=id;
 this->nom=nom;
 this->prenom=prenom;
 this->mail=mail;
 this->dateEmbauche=dateEmbauche;
 this->salaire=salaire;
 this->telephone=telephone;
    this->ROLE=ROLE;
}

Employee::Employee()
    {
      id=0;
      nom="";
      prenom=("");
      mail=("");
      dateEmbauche=QDate::currentDate();
      salaire="0";
      telephone="";
      ROLE="";
}

int Employee::getId()  {
    return id;
}

QString Employee::getNom()  {
    return nom;
}

QString Employee::getPrenom()  {
    return prenom;
}

QString Employee::getMail()  {
    return mail;
}

QString Employee::getSalaire()  {
    return salaire;
}

QString Employee::getTelephone()  {
    return telephone;
}

QDate Employee::getDateEmbauche()  {
    return dateEmbauche;
}
QString Employee::getROLE()  {
    return ROLE;
}
QString Employee::getmessage()  {
    return message;
}


void Employee::setNom( QString nom) {
    this->nom = nom;
}

void Employee::setPrenom( QString prenom) {
    this->prenom = prenom;
}

void Employee::setMail( QString mail) {
    this->mail = mail;
}

void Employee::setSalaire(QString salaire) {
    this->salaire = salaire;
}

void Employee::setTelephone( QString telephone) {
    this->telephone = telephone;
}

void Employee::setDateEmbauche( QDate dateEmbauche) {
    this->dateEmbauche = dateEmbauche;
}

void Employee::setROLE( QString ROLE) {
    this->ROLE = ROLE;
}

void Employee::setmessage(QString  message) {
    this->message = message;
}


bool Employee::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (IDE, NOM, PRENOM, MAIL, DATE_EMB, SALAIRE, TELEPHONE,ROLE) "
                  "VALUES (:IDE, :NOM, :PRENOM, :MAIL, :DATE_EMB, :SALAIRE, :TELEPHONE,:ROLE)");

    query.bindValue(":IDE", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":DATE_EMB", dateEmbauche);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":ROLE", ROLE);


    return query.exec();
}


QSqlQueryModel* Employee::afficher()  {
    QSqlQueryModel* model = new QSqlQueryModel();
    // Exécutez la requête
    model->setQuery("SELECT IDE, NOM, PRENOM, MAIL, DATE_EMB, SALAIRE, TELEPHONE,ROLE,PRESENCE FROM EMPLOYES");

model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_EMBAUCHE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("TELEPHONE"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("ROLE"));

    return model;
}

bool Employee::employeeExists(int id)  {
    QSqlQuery query;
    query.prepare("SELECT IDE FROM EMPLOYES WHERE IDE = :ID");
    query.bindValue(":ID", id);
    if(query.exec() && query.next())
     {
      int count = query.value(0).toInt();
      return count >0;

    }
return false;
}


bool Employee::supprimer(int id)
{
QSqlQuery query;
query.prepare("Delete from EMPLOYES WHERE IDE=:ID");
query.bindValue(0,id);
return query.exec();
}


bool Employee::modifier(int id, QString nom, QString prenom, QString mail, QDate dateEmbauche, QString salaire,QString telephone, QString ROLE) {
    QSqlQuery query;
    query.prepare("UPDATE  EMPLOYES SET  NOM=:NOM, PRENOM=:PRENOM, MAIL=:MAIL, DATE_EMB=:DATE_EMB, SALAIRE=:SALAIRE, TELEPHONE=:TELEPHONE,ROLE=:ROLE WHERE IDE=:IDE ");
    query.bindValue(":IDE", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":MAIL", mail);
    query.bindValue(":DATE_EMB", dateEmbauche);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":TELEPHONE", telephone);
    query.bindValue(":ROLE", ROLE);
    return query.exec();
}



QSqlQueryModel* Employee::tri(QString column)
 {
 QSqlQueryModel* model = new QSqlQueryModel();
 model->setQuery("SELECT IDE, NOM, PRENOM, MAIL, DATE_EMB, SALAIRE, TELEPHONE,ROLE,PRESENCE FROM EMPLOYES ORDER BY " + column + " ASC");

 return model;
 }

QSqlQueryModel* Employee::tri1(QString column)
 {
 QSqlQueryModel* model = new QSqlQueryModel();
 model->setQuery("SELECT IDE, NOM, PRENOM, MAIL, DATE_EMB, SALAIRE, TELEPHONE,ROLE,PRESENCE FROM EMPLOYES ORDER BY " + column + " DESC");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_EMBAUCHE"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("TELEPHONE"));
 model->setHeaderData(7,Qt::Horizontal,QObject::tr("ROLE"));
 return model;
 }


QSqlQueryModel* Employee::chercher(QString column,QString text)
 {
 QSqlQueryModel* model = new QSqlQueryModel();
 model->setQuery("SELECT IDE, NOM, PRENOM, MAIL, DATE_EMB, SALAIRE, TELEPHONE,ROLE,PRESENCE FROM EMPLOYES WHERE  " + column + " LIKE '%" + text + "%' ");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_EMBAUCHE"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("SALAIRE"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("TELEPHONE"));
 model->setHeaderData(7,Qt::Horizontal,QObject::tr("ROLE"));
 return model;
 }
int Employee::countRole(const QString& role)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(ROLE) FROM EMPLOYES WHERE ROLE = :ROLE");
    query.bindValue(":ROLE", role);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}

QString Employee::chercherEMAIL(int id)
{
    QString mail = "";

    QSqlQuery query;
    query.prepare("SELECT MAIL FROM EMPLOYES WHERE IDE=:ID");
    query.bindValue(":ID", id);

    if (query.exec() && query.next()) {
        mail = query.value(0).toString();

    }

    return mail;
}

