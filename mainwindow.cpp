#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlQueryModel *model = ftmp.afficher();
        if (model == nullptr) {
            qDebug() << "Model returned from afficher() is null";
        } else {
            ui->tableView->setModel(ftmp.afficher());
        }
        connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
            connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
            connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
            connect(ui->pushButton_actualiser, &QPushButton::clicked, this, &MainWindow::on_pushButton_actualiser_clicked);

            ui->tabWidget->setCurrentIndex(1); // Set to tab 2 at startup

    // Afficher la liste des fournisseurs au démarrage
    //ui->tableView->setModel(ftmp.afficher());
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
