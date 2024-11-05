#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Afficher la liste des fournisseurs au démarrage
    ui->tableView->setModel(ftmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    // Récupération des informations depuis l'interface
    int id = ui->lineEdit_id->text().toInt();
    int quantiter = ui->lineEdit_quantiter->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mail = ui->lineEdit_mail->text();
    float prixLevrison = ui->lineEdit_prix->text().toFloat();

    Fournisseur F(id, quantiter, nom, prenom, mail, prixLevrison);
    bool test = F.ajouter();

    if(test)
    {
        // Actualiser l'affichage
        ui->tableView->setModel(ftmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test = ftmp.supprimer(id);

    if(test)
    {
        // Actualiser l'affichage
        ui->tableView->setModel(ftmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression non effectuée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupération des informations depuis l'interface
    int id = ui->lineEdit_id->text().toInt();
    int quantiter = ui->lineEdit_quantiter->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mail = ui->lineEdit_mail->text();
    float prixLevrison = ui->lineEdit_prix->text().toFloat();

    Fournisseur F(id, quantiter, nom, prenom, mail, prixLevrison);
    bool test = F.modifier();

    if(test)
    {
        // Actualiser l'affichage
        ui->tableView->setModel(ftmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->tableView->setModel(ftmp.afficher());
}
#include "fournisseur.h"
#include <QDebug>

bool Fournisseur::ajouter()
{
    QSqlQuery query;

    // Conversion des valeurs numériques en QString
    QString id_string = QString::number(IDF);
    QString QUANTITER_string = QString::number(QUANTITER);

    QString PRIXLEVRISON_string = QString::number(PRIXLEVRISON);

    // Préparation de la requête
    query.prepare("INSERT INTO ALAEDIN FOURNISSEUR (IDF, QUANTITER, NOM, PRENOM, "
                 "MAIL, PRIX_LEVRISON) "
                 "VALUES (:id, :QUANTITER, :NOM, :PRENOM, :MAIL, :PRIXLEVRISON)");

    // Binding des valeurs
    query.bindValue(":IDF", id_string);
    query.bindValue(":QUANTITER", QUANTITER_string);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON_string);

    // Exécution de la requête
    return query.exec();
}

bool Fournisseur::supprimer(int IDF)
{
    QSqlQuery query;
    QString id_string = QString::number(IDF);

    query.prepare("DELETE FROM FOURNISSEUR WHERE IDF = :id");
    query.bindValue(":id", id_string);

    return query.exec();
}

QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PréNOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID Commande"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Prix Livraison"));

    return model;
}

bool Fournisseur::modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(IDF);
    QString QUANTITER_string = QString::number(QUANTITER);
    QString PRIXLEVRISON_string = QString::number(PRIXLEVRISON);

    query.prepare("UPDATE FOURNISSEUR SET QUANTITER=:QUANTITER, NOM=:NOM, PRENOM=:PRENOM, "
                 "MAIL=:MAIL, PRIX_LEVRISON=:PRIXLEVRISON "
                 "WHERE IDF=:id");

    query.bindValue(":id", id_string);
    query.bindValue(":QUANTITER", QUANTITER_string);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":PRIXLEVRISON", PRIXLEVRISON_string);

    return query.exec();
}
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
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

if (db.open())
test=true;





    return  test;
}
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_actualiser_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur ftmp; // Instance temporaire pour les opérations CRUD
};

#endif // MAINWINDOW_H
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>630</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Gestion des Clients</string>
  </property>
  <widget class="QWidget" name="centralWidget">
   <widget class="QGroupBox" name="groupBox">
    <property name="geometry">
     <rect>
      <x>20</x>
      <y>10</y>
      <width>351</width>
      <height>181</height>
     </rect>
    </property>
    <property name="title">
     <string>gest fournisseur</string>
    </property>
    <widget class="QLabel" name="label">
     <property name="geometry">
      <rect>
       <x>10</x>
       <y>20</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>Nom</string>
     </property>
    </widget>
    <widget class="QLabel" name="label_2">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>20</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>Prénom</string>
     </property>
    </widget>
    <widget class="QLabel" name="label_3">
     <property name="geometry">
      <rect>
       <x>10</x>
       <y>60</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>Mail</string>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_prenom">
     <property name="geometry">
      <rect>
       <x>210</x>
       <y>20</y>
       <width>121</width>
       <height>20</height>
      </rect>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_mail">
     <property name="geometry">
      <rect>
       <x>40</x>
       <y>60</y>
       <width>101</width>
       <height>20</height>
      </rect>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_id">
     <property name="geometry">
      <rect>
       <x>210</x>
       <y>60</y>
       <width>113</width>
       <height>20</height>
      </rect>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_nom">
     <property name="geometry">
      <rect>
       <x>40</x>
       <y>20</y>
       <width>113</width>
       <height>22</height>
      </rect>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_quantiter">
     <property name="geometry">
      <rect>
       <x>220</x>
       <y>100</y>
       <width>113</width>
       <height>22</height>
      </rect>
     </property>
    </widget>
    <widget class="QLineEdit" name="lineEdit_prix">
     <property name="geometry">
      <rect>
       <x>40</x>
       <y>150</y>
       <width>113</width>
       <height>22</height>
      </rect>
     </property>
    </widget>
    <widget class="QLabel" name="label_4">
     <property name="geometry">
      <rect>
       <x>170</x>
       <y>60</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>ID</string>
     </property>
    </widget>
    <widget class="QLabel" name="label_6">
     <property name="geometry">
      <rect>
       <x>160</x>
       <y>100</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>Qnt</string>
     </property>
    </widget>
    <widget class="QLabel" name="label_7">
     <property name="geometry">
      <rect>
       <x>10</x>
       <y>150</y>
       <width>47</width>
       <height>13</height>
      </rect>
     </property>
     <property name="text">
      <string>prix_l</string>
     </property>
    </widget>
   </widget>
   <widget class="QPushButton" name="pushButton">
    <property name="geometry">
     <rect>
      <x>550</x>
      <y>220</y>
      <width>75</width>
      <height>23</height>
     </rect>
    </property>
    <property name="text">
     <string>Ajouter</string>
    </property>
   </widget>
   <widget class="QTableView" name="tableView">
    <property name="geometry">
     <rect>
      <x>375</x>
      <y>20</y>
      <width>231</width>
      <height>192</height>
     </rect>
    </property>
    <property name="focusPolicy">
     <enum>Qt::NoFocus</enum>
    </property>
    <property name="dragEnabled">
     <bool>true</bool>
    </property>
    <property name="alternatingRowColors">
     <bool>true</bool>
    </property>
    <property name="selectionMode">
     <enum>QAbstractItemView::NoSelection</enum>
    </property>
    <property name="selectionBehavior">
     <enum>QAbstractItemView::SelectRows</enum>
    </property>
   </widget>
   <widget class="QPushButton" name="on_pushButton_supprimer_clicked">
    <property name="geometry">
     <rect>
      <x>100</x>
      <y>220</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="text">
     <string>supprimer</string>
    </property>
   </widget>
   <widget class="QPushButton" name="on_pushButton_modifier_clicked">
    <property name="geometry">
     <rect>
      <x>10</x>
      <y>220</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="acceptDrops">
     <bool>false</bool>
    </property>
    <property name="accessibleName">
     <string>on_pushButton_modifier_clicked</string>
    </property>
    <property name="text">
     <string>modifier</string>
    </property>
   </widget>
   <widget class="QPushButton" name="on_pushButton_ajouter_clicked">
    <property name="geometry">
     <rect>
      <x>190</x>
      <y>220</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="text">
     <string>ajouter</string>
    </property>
   </widget>
   <widget class="QPushButton" name="pushButton_5">
    <property name="geometry">
     <rect>
      <x>290</x>
      <y>220</y>
      <width>75</width>
      <height>24</height>
     </rect>
    </property>
    <property name="text">
     <string>actualiser</string>
    </property>
   </widget>
  </widget>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>630</width>
     <height>22</height>
    </rect>
   </property>
  </widget>
  <widget class="QToolBar" name="mainToolBar">
   <attribute name="toolBarArea">
    <enum>TopToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
  </widget>
  <widget class="QStatusBar" name="statusBar"/>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources/>
 <connections/>
</ui>
#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
CREATE TABLE FOURNISSEUR 
(
  IDF NUMBER NOT NULL 
, QUANTITER NUMBER NOT NULL 
, NOM VARCHAR2(20 BYTE) NOT NULL 
, PRENOM VARCHAR2(20 BYTE) 
, MAIL VARCHAR2(20 BYTE) NOT NULL 
, PRIXLEVRISON FLOAT(126) NOT NULL 
, CONSTRAINT FOURNISSEUR_PK PRIMARY KEY 
  (
    IDF 
  )