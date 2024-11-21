#include "update.h"
#include "ui_update.h"
#include "patient.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
}

Update::~Update()
{
    delete ui;
}

void Update::on_modifer_clicked()
{
               int idp = ui->idpaa->text().toInt();
               QString nom = ui->nom->text();
               QString prenom = ui->prenom->text();
               QString mail = ui->mail->text();
               int tel = ui->tel->text().toInt();
               int rdv = ui->rdv->text().toInt();
               QDate date = ui->date->date();
               QString ville = ui->ville->text();

               Patient P(idp, nom, prenom, mail, tel, rdv, date, ville);

               bool test = P.modifier();
               //ui->tableView->setModel(P.afficher());

               if(test)
               {
                   QMessageBox::information(nullptr, QObject::tr("OK"),
                           QObject::tr("Modification effectuée\n""Click Cancel to exit."), QMessageBox::Cancel);
               }
               else
               {
                   QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                         QObject::tr("Modification non effectuée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
               }
}
