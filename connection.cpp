#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source25");//inserer le nom de la source de données
db.setUserName("alaedin");//inserer nom de l'utilisateur
db.setPassword("esprit2024");//inserer mot de passe de cet utilisateur

qDebug() << "Available drivers:" << QSqlDatabase::drivers();

if (db.open())
test=true;






    return  test;
}
