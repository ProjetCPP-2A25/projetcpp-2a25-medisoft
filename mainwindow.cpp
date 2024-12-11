#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>
#include <QChart>
#include <email.h>
#include <cstdlib>
#include <ctime>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QSqlError>
#include <QComboBox>
#include <QMap>
#include "qqml.h"

#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFileDialog>
#include <QtCharts/QPieSeries>
#include "SMS.h"
#include "MAILER.h"
#include <QThread>
#include <QPrinter>
#include <QPageSize>
//produit
//#include "ventilateur.h"

#include "produitai.h"
#include "produits.h"
//#include "listproduit.h"
#include <QSpinBox> // Inclure QSpinBox pour utiliser le widget de saisie de nombre
#include <QtCharts/QCategoryAxis>
//#include "xlsxdocument.h"
//#include "xlsxformat.h"

#include <QBarSet>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QLabel>
#include <QPixmap>
#include <QScrollBar>
#include <QString>
#include <QTimer>
//#include <QXlsx>
#include <QCoreApplication>
//#include <QSerialPort>
//#include <QSerialPortInfo>
#include <QtCharts/QPieSlice>
//using namespace  QtCharts;

//commandes ///////////
#include "commandes.h"
#include "connection.h"
#include <QZXing.h>
#include <QStandardItemModel>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextCursor>
#include <QTextTableCell>
#include <QRegularExpressionMatch>
//#include <QSoundEffect>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    , timer(new QTimer(this)) // Initialisation correcte
    //ventilateur(new Ventilateur())
    ,c(),
    historiqueEfface(false)

{
    ui->setupUi(this);

    ui->tableViewE->setModel(e.afficher());
remplir_combo_idemploye();


QIntValidator *intValidator = new QIntValidator(0, 9999, this);
ui->le_idd->setValidator(intValidator);

QRegularExpressionValidator *charValidator = new QRegularExpressionValidator(QRegularExpression("^[A-Za-z]+$"), this);
ui->le_nom->setValidator(charValidator);
ui->le_prenom->setValidator(charValidator);
GESTION_EMPLOYE_STATISTIQUE();

ui->login_mdp->setEchoMode(QLineEdit::Password);
ui->menu->hide();
ui->gestion_client->hide();
ui->login->show();

/*connect(ui->bt_login, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(0);
});*/

    connect(ui->g_c_menu, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
connect(ui->MENU, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(0);
});
    connect(ui->menuuuu, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
connect(ui->pushButton_4, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(0);
});
connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(0);
});

    connect(ui->g_c_deconnecter_2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
connect(ui->deconnecterrr, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
connect(ui->pushButton_3, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
connect(ui->loginnn, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
connect(ui->motdepasse, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(5);
});
    connect(ui->revenirrr, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
connect(ui->revenir_2, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
connect(ui->g_c_deconnecter, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});
    connect(ui->DECONNECTER, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
/*connect(ui->login, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);
});*/
ui->stackedWidget->setCurrentIndex(3);  // 1 correspond à la page 'login'
//connect(ui->Ajouter, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
//connect(ui->Supprimer, &QPushButton::clicked, this, &MainWindow::on_Supprimer_clicked);
connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::on_tableView_doubleClicked);
//connect(ui->Afficher, &QPushButton::clicked, this, &MainWindow::on_Afficher_clicked);
//connect(ui->savebutton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
//connect(ui->Rechercher, &QPushButton::clicked, this, &MainWindow::on_Rechercher_clicked);
//connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
//connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
connect(ui->savebutton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);

//connect(ui->btn_statistiques, &QPushButton::clicked, this, &MainWindow::on_btn_statistiques_clicked);
//connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);
connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::on_Refresh_clicked);
//connect(ui->pb_notfier, &QPushButton::clicked, this, &MainWindow::on_pb_notfier_clicked);
//connect(ui->btn_sendEmail, &QPushButton::clicked, this, &MainWindow::on_btn_sendEmail_clicked);
//fournisseur
//arduino_init();
model = ftmp.afficher(); // Populate model with initial data
ui->tableView->setModel(model);
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

//ui->tabWidget->setCurrentIndex(1); // Set to tab 2 at startup
connect(ui->tableView_2, &QTableView::doubleClicked, this, &MainWindow::on_tableView_2_clicked); // Connect the signal


connect(ui->radioButton_nom, &QPushButton::clicked, this, &MainWindow::on_radioButton_nom_clicked);
connect(ui->radioButton_etoile, &QPushButton::clicked, this, &MainWindow::on_radioButton_deetoile_clicked);

connect(ui->radioButton_nom_2, &QPushButton::clicked, this, &MainWindow::on_radioButton_denom_clicked);
connect(ui->radioButton_nom_3, &QPushButton::clicked, this, &MainWindow::on_radioButton_etoile_clicked);
connect(ui->pushButton_showMap, &QPushButton::clicked, this, &MainWindow::showMap);
connect(ui->on_pushButton_showStats1, &QPushButton::clicked, this, &MainWindow::on_pushButton_showStats2_clicked);
//connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readSerial);


// Afficher la liste des fournisseurs au démarrage
//ui->tableView->setModel(ftmp.afficher());
//ui->tableView->setSortingEnabled(true);


setupClock();


ui->tableView->setModel(pat.afficher());
ui->tableView_2->setModel(ftmp.afficher());
ui->tableView_3->setModel(c.afficher());



//produit
//serialPort = new QSerialPort(this);

/*// Vérification des ports série disponibles
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Nom du port : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Fabricant : " << info.manufacturer();
    }

    // Définir le port série (modifiez le nom du port si nécessaire)
    serialPort->setPortName("COM4"); // Remplacez par le bon port
    // Définir les paramètres du port séri
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Tenter d'ouvrir le port série
    if (serialPort->open(QIODevice::ReadOnly)) {
        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    } else {
        QString errorMessage = serialPort->errorString();
        qDebug() << "Erreur de connexion avec le port série: " << errorMessage;
    }
*/
// Créer un timer pour actualiser l'UI toutes les secondes
/*timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateUI);
    timer->start(1000); // Mise à jour toutes les secondes*/
connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
connect(ui->Modifier, &QPushButton::clicked, this, &MainWindow::on_Modifier_clicked);
connect(ui->sauvegarder, &QPushButton::clicked, this, &MainWindow::on_sauvegarder_clicked);
connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
connect(ui->boutonTrier, &QPushButton::clicked, this, &MainWindow::trierProduits);
connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::on_statistique_clicked);
connect(ui->ListProduit, &QPushButton::clicked, this, &MainWindow::on_ListProduit_clicked);

// Connexion du bouton à la fonction pour ajouter une image
connect(ui->addImageButton, &QPushButton::clicked, this, &MainWindow::on_addImageButton_clicked);

connect(ui->AiDoctorButton, &QPushButton::clicked, this, &MainWindow::on_AiDoctorButton_clicked);
//connect(ui->exportButton, &QPushButton::clicked, this, &MainWindow::onExportButtonClicked);

// Set up validators to ensure only numbers can be entered
ui->lineCode->setValidator(new QIntValidator(0, 999999, this));
ui->lineqte->setValidator(new QIntValidator(0, 999999, this)); // For QUANTITEE as an integer
ui->linePrice->setValidator(new QDoubleValidator(0, 999999.99, 2, this));

/*// Connecter le signal ventilateurOn à un slot pour afficher l'alerte
    connect(ventilateur, &Ventilateur::ventilateurOn, this, &MainWindow::onVentilateurOn);
    connect(ventilateur, &Ventilateur::ventilateurOff, this, &MainWindow::onVentilateurOff);*/

// Dans le constructeur de MainWindow
/*QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, ventilateur, &Ventilateur::checkVentilateurStatus);
    timer->start(1000); // Vérifie toutes les 1 seconde*/

refreshTable();

//commandes////////

connect(ui->tableView_3, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);
connect(ui->supprimerHistoriqueButton, &QPushButton::clicked, this, &MainWindow::on_supprimerHistorique_clicked);


chargerHistorique();
}

MainWindow::~MainWindow()
{
    /*if (serialPort->isOpen()) {
        serialPort->close();
    }*/
    delete ui;
    ///AI////
    //delete chatWindow;
    //delete fermerAiButton;
}

//////employee////////
#include <QProcess>
#include <QDebug>

void MainWindow::on_m_patient_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_m_produit_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}


void MainWindow::remplir_combo_idemploye()
{
    //repetition
    ui->combo_ide->clear();

QSqlQuery query;
query.exec("SELECT IDE FROM EMPLOYES ");
while(query.next()){
    QString id = query.value(0).toString();
ui->combo_ide->addItem(id);
}

}

void MainWindow::on_ajouter_clicked()
{

    //compteur
    int c=0;
    // Récupération des valeurs depuis l'interface utilisateur
       int id = ui->le_idd->text().toInt();  // Assurez-vous d'avoir un champ pour l'ID
       QString nom = ui->le_nom->text();
       QString prenom = ui->le_prenom->text();
       QString mail = ui->le_mail->text();  // Assurez-vous d'avoir un champ pour l'email
       QDate dateEmbauche = ui->dateE->date();  // Assurez-vous d'avoir un champ pour la date d'embauche
       QString salaire = ui->le_salaire->text();  // Assurez-vous d'avoir un champ pour le salaire (QString)
       QString telephone = ui->le_tel->text();  // Assurez-vous d'avoir un champ pour le téléphone
       QString ROLE=ui->role->currentText();

if(e.employeeExists(id))
{
    c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("id déja existe"), QMessageBox::Cancel);
}
if(ui->le_idd->text().isEmpty() || nom.isEmpty() || prenom.isEmpty() || prenom.isEmpty() ||mail.isEmpty() ||salaire.isEmpty() || telephone.isEmpty())
{
    c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("tu dois remplir tous les champs"), QMessageBox::Cancel);
}

if( QString::number(id).length()>7)
{
c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("le longuer doit etre 8 chiffre "), QMessageBox::Cancel);
}
QRegularExpression regex("^[2|5|7|9]\\d{7}$");
if(!regex.match(telephone).hasMatch() )
{
     c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("numero invalide"), QMessageBox::Cancel);

}

// Vérifier si l'e-mail est valide
       QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
       QRegularExpressionMatch match = emailRegex.match(mail);
       if (!match.hasMatch())
       {
           QMessageBox::critical(nullptr, QObject::tr("Email invalide"), QObject::tr("Le format de l'e-mail est invalide. Veuillez entrer un e-mail valide."), QMessageBox::Cancel);
           c++;
       }

if(c==0)
{       // Création de l'objet Employee avec les attributs correspondants
  Employee e1(id, nom, prenom, mail,dateEmbauche, salaire, telephone,ROLE);

       // Tente d'ajouter l'employé à la base de données
       bool insertionSuccess = e1.ajouter();
       QMessageBox messageBox;

       if (insertionSuccess)
       {


           // Réinitialisez les champs de saisie
           ui->le_idd->clear();
           ui->le_nom->clear();
           ui->le_prenom->clear();
           ui->le_mail->clear();
           ui->le_salaire->clear();
           ui->le_tel->clear();
           ui->dateE->clear();

            ui->tableViewE->setModel(e.afficher());
            remplir_combo_idemploye();
            GESTION_EMPLOYE_STATISTIQUE();
            QString nom = ui->le_nom->text();
            QString prenom = ui->le_prenom->text();
            QString mail = ui->le_mail->text();  // Assurez-vous d'avoir un champ pour l'email
            QDate dateEmbauche = ui->dateE->date();  // Assurez-vous d'avoir un champ pour la date d'embauche
            QString salaire = ui->le_salaire->text();  // Assurez-vous d'avoir un champ pour le salaire (QString)
            QString telephone = ui->le_tel->text();  // Assurez-vous d'avoir un champ pour le téléphone
            QString ROLE = ui->role->currentText();

            // Create the message with placeholders
            QString message = QString("Bonjour %1 %2,\n\n"
                                      "Votre compte a été ajouté avec succès.\n"
                                      "Voici les détails de votre compte :\n"
                                      "Nom: %1\n"
                                      "Prénom: %2\n"
                                      "Email: %3\n"
                                      "Date d'embauche: %4\n"
                                      "Salaire: %5\n"
                                      "Téléphone: %6\n"
                                      "Rôle: %7\n\n"
                                      "Cordialement,\n"
                                      "L'équipe de gestion")
                                      .arg(nom)      // Replace %1 with nom
                                      .arg(prenom)   // Replace %2 with prenom
                                      .arg(mail)     // Replace %3 with mail
                                      .arg(dateEmbauche.toString("dd/MM/yyyy"))  // Replace %4 with formatted date
                                      .arg(salaire)  // Replace %5 with salaire
                                      .arg(telephone)  // Replace %6 with telephone
                                      .arg(ROLE);     // Replace %7 with ROLE

            // Send the email with the composed message
            emailSender.sendEmail(mail, "Notification d'ajout", message);

 QMessageBox::warning(this, "", "Données ajoutées à la base de données avec succès !");

       }
       else
       {

           QMessageBox::warning(this, "", "Échec de l'ajout des données dans la base de données.");

       }

}
}

void MainWindow::on_refresh_clicked()
{

            ui->tableViewE->setModel(e.afficher());
       remplir_combo_idemploye();

}


void MainWindow::on_bt_supprimer_clicked()
{
    int id=ui->combo_ide->currentText().toInt();
    bool test =e.supprimer(id);
    QMessageBox msgBox;
    if(test)
    {
        remplir_combo_idemploye();
        GESTION_EMPLOYE_STATISTIQUE();

        ui->tableViewE->setModel(e.afficher());
   remplir_combo_idemploye();
         emailSender.sendEmail(e.chercherEMAIL(id),"notification du suppression", "ton compte a ete supprimer");

         QMessageBox::warning(this, "", "suppression avec succés");

    } else
    {
      QMessageBox::warning(this, "Erreur", "Échec de suppression des employés.");
    }

}

void MainWindow::on_modifier_clicked()
{
int c=0;
    // Récupération des valeurs depuis l'interface utilisateur
       int id = ui->le_idd->text().toInt();  // Assurez-vous d'avoir un champ pour l'ID
       QString nom = ui->le_nom->text();
       QString prenom = ui->le_prenom->text();
       QString mail = ui->le_mail->text();  // Assurez-vous d'avoir un champ pour l'email
       QDate dateEmbauche = ui->dateE->date();  // Assurez-vous d'avoir un champ pour la date d'embauche
       QString salaire = ui->le_salaire->text();  // Assurez-vous d'avoir un champ pour le salaire (QString)
       QString telephone = ui->le_tel->text();  // Assurez-vous d'avoir un champ pour le téléphone
       QString ROLE=ui->role->currentText();
       // Création de l'objet Employee avec les attributs correspondants
//controle saisie
if(!e.employeeExists(id))
{
    c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("id n' existe pas"), QMessageBox::Cancel);
}
if(ui->le_idd->text().isEmpty() || nom.isEmpty() || prenom.isEmpty() || prenom.isEmpty() ||mail.isEmpty() ||salaire.isEmpty() || telephone.isEmpty())
{
    c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("tu dois remplir tous les champs"), QMessageBox::Cancel);
}

QRegularExpression regex("^[2|5|7|9]\\d{7}$");
if(!regex.match(telephone).hasMatch() )
{
     c++;
    QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                          QObject::tr("numero invalide"), QMessageBox::Cancel);

}

// Vérifier si l'e-mail est valide
       QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
       if (!emailRegex.match(mail).hasMatch())
       {
           QMessageBox::critical(nullptr, QObject::tr("Email invalide"), QObject::tr("Le format de l'e-mail est invalide. Veuillez entrer un e-mail valide."), QMessageBox::Cancel);
           c++;
       }

       if(c==0)
       {// Tente d'ajouter l'employé à la base de données
       bool insertionSuccess = e.modifier(id, nom, prenom, mail,dateEmbauche, salaire, telephone,ROLE);
       QMessageBox messageBox;

       if (insertionSuccess)
       {
           QMessageBox::information(nullptr, QObject::tr(""), QObject::tr("Données modifiés à la base de données avec succès !"), QMessageBox::Cancel);

           // Réinitialisez les champs de saisie
           ui->le_idd->clear();
           ui->le_nom->clear();
           ui->le_prenom->clear();
           ui->le_mail->clear();
           ui->le_salaire->clear();
           ui->le_tel->clear();
           ui->dateE->clear();
            ui->tableViewE->setModel(e.afficher());
            remplir_combo_idemploye();
             emailSender.sendEmail(mail,"notification du modification", "ton compte a ete modifier");

GESTION_EMPLOYE_STATISTIQUE();
       }
       else
       {
           QMessageBox::warning(nullptr, QObject::tr(""), QObject::tr("Échec de modification des données dans la base de données."), QMessageBox::Cancel);


       }
       }
}




void MainWindow::on_tableViewE_clicked(const QModelIndex &index)
{

    int row = index.row();
      QString val = ui->tableViewE->model()->data(ui->tableViewE->model()->index(row, 0)).toString();
      QSqlQuery qry;
           qry.prepare("select * from EMPLOYES where IDE='" + val + "'");

           if (qry.exec()) {
               while (qry.next()) {
                   QString id = qry.value(0).toString();
                   QString nom = qry.value(1).toString();
                   QString prenom = qry.value(2).toString();
                     QString mail = qry.value(3).toString();
                     QDate EMB = qry.value(4).toDate();
                     QString SALAIRE = qry.value(5).toString();
                     QString TELEPHONE = qry.value(6).toString();
                     QString ROLE = qry.value(7).toString();

                     ui->le_idd->setText(id);
                     ui->le_nom->setText(nom);
                     ui->le_prenom->setText(prenom);
                     ui->le_mail->setText(mail);
                     ui->le_salaire->setText(SALAIRE);
                     ui->le_tel->setText(TELEPHONE);
                     ui->dateE->setDate(EMB);
                     ui->role->setCurrentText(ROLE);

               }
           }


}




void MainWindow::on_PDF_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableViewE->model()->rowCount();
    const int columnCount = ui->tableViewE->model()->columnCount();

    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           "<title>%1</title>\n"
           "<style>\n"
           "table {\n"
           "    width: 100%;\n"
           "    border-collapse: collapse;\n"
           "}\n"
           "th, td {\n"
           "    padding: 8px;\n"
           "    text-align: left;\n"
           "    border-bottom: 1px solid #ddd;\n"
           "}\n"
           "tr:nth-child(even) {\n"
           "    background-color: #f2f2f2;\n"
           "}\n"
           "</style>\n"
           "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<center> <H1>Liste des EMPLOYES</H1></center><br/><br/>\n"
           "<img src='C:/Users/user/Desktop/Atelier_Connexion/Atelier_Connexion/logo.jpg' width='50' height='50'> <br></br>\n"
           "<table>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        if (!ui->tableViewE->isColumnHidden(column))
        {
            out << QString("<th>%1</th>").arg(ui->tableViewE->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableViewE->isColumnHidden(column))
            {
                QString data = ui->tableViewE->model()->data(ui->tableViewE->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }



    QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    //doc.setPageSize(printer.printableRect().size());
    doc.print(&printer);

}

void MainWindow::GESTION_EMPLOYE_STATISTIQUE()
{
    QList<QWidget*> childWidgets = ui->label_stat->findChildren<QWidget*>();
        for (QWidget* childWidget : childWidgets) {
            childWidget->deleteLater();

        }
        //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
        ui->label_stat->clear();
        ui->label_stat->hide();

    int s0, s1,s2;

    s0 = e.countRole("RH");
    s1 = e.countRole("DEV");
    s2 = e.countRole("SECURITE");




    int stat = s0 + s1 + s2  ;
    // Calculate percentages
        float x = (stat != 0) ? (s0 * 100.0f) / stat : 0.0f;
        float x1 = (stat != 0) ? (s1 * 100.0f) / stat : 0.0f;
        float x2 = (stat != 0) ? (s2 * 100.0f) / stat : 0.0f;


        // Adjust the percentages to ensure they sum up to 100%
        float totalPercentage = x + x1+ x2  ;
        if (totalPercentage != 100.0f && stat != 0) {
            float correction = 100.0f - totalPercentage;
            x += correction;  // Apply correction to one of the slices (usually the largest one)
        }



//qDebug() <<  x <<endl;
// 3 jour  33.00 %
    QString ch1 = QString("RH %1%").arg(QString::number(x, 'f', 2));
    QString ch2 = QString("DEV %2%").arg(QString::number(x1, 'f', 2));
    QString ch3 = QString("SECURITE %3%").arg(QString::number(x2, 'f', 2));





    QPieSeries *series=new QPieSeries();
    series->setHoleSize(0.35);

    QPieSlice *slice= series->append(ch1,x);
    slice->setLabelVisible();
    slice->setLabelColor(QColor(Qt::white));
        slice->setBrush(QColor(189, 76, 224, 1));

    QPieSlice *slice1= series->append(ch2,x1);
    slice1->setLabelVisible();
    slice1->setLabelColor(QColor(Qt::white));
    slice1->setBrush(QColor(84, 16, 149, 1));

    QPieSlice *slice2= series->append(ch3,x2);
    slice2->setLabelVisible();

    slice2->setLabelColor(QColor(Qt::white));
    slice2->setBrush(QColor(119, 82, 254));




    QChart *chart=new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBrush backgroundBrush(QColor(187,93,87,0));
    chart->setBackgroundBrush(backgroundBrush);
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setFixedSize(ui->label_stat->size());
    chartview->setParent(ui->label_stat);
    ui->label_stat->setStyleSheet("background:transparent; color:white; ");
    ui->label_stat->show();

}


void MainWindow::on_bt_asc_clicked()
{
  QString text=  ui->combo_tri->currentText();
    if(text=="ID")
    {
    ui->tableViewE->setModel(e.tri("IDE"));

    }
    else {
    if(text=="DATE_EMBAUCHE")
    {
        ui->tableViewE->setModel(e.tri("DATE_EMB"));

    }
    else
    {
     if(text=="salaire")
     {
         ui->tableViewE->setModel(e.tri("SALAIRE"));

     }
        else
     {
         ui->tableViewE->setModel(e.afficher());

     }


    }
    }
}

void MainWindow::on_bt_desc_clicked()
{
    QString text=  ui->combo_tri->currentText();
      if(text=="ID")
      {
      ui->tableViewE->setModel(e.tri1("IDE"));

      }
      else {
      if(text=="DATE_EMBAUCHE")
      {
          ui->tableViewE->setModel(e.tri1("DATE_EMB"));

      }
      else
      {
       if(text=="salaire")
       {
           ui->tableViewE->setModel(e.tri1("SALAIRE"));

       }
          else
       {
           ui->tableViewE->setModel(e.afficher());

       }


      }
      }
}

void MainWindow::on_bt_chercher_clicked()
{
    QString text=ui->lineEdit_chercher->text();
    QString choix= ui->combo_chercher->currentText();
      if(choix=="ID")
      {
      ui->tableViewE->setModel(e.chercher("IDE",text));

      }
      else {
      if(choix=="NOM")
      {
          ui->tableViewE->setModel(e.chercher("NOM",text));

      }
      else
      {
       if(choix=="PRENOM")
       {
           ui->tableViewE->setModel(e.chercher("PRENOM",text));

       }
          else
       {
           ui->tableViewE->setModel(e.afficher());

       }


      }

  }

}

void MainWindow::on_envoyer_clicked()
{
       emailSender.sendEmail(ui->to->text(), ui->obj->text(), ui->body->text());
}

void MainWindow::on_m_log_out_clicked()
{
    /*ui->menu->hide();
    ui->gestion_client->hide();
    ui->login->show();*/
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_bt_login_clicked()
{
    QString email = ui->login_email->text();
       QString password = ui->login_mdp->text();

       QSqlQuery query;
       query.prepare("SELECT * FROM EMPLOYES WHERE MAIL = :email");
       query.bindValue(":email", email);

       if (query.exec() && query.next()) {

           QString storedPassword = query.value("MDP").toString();
           if (password == storedPassword) {

               query.prepare("SELECT ROLE FROM EMPLOYES WHERE MAIL = :email");
               query.bindValue(":email", email);

               if (query.exec() && query.next())
               e.setROLE ( query.value("ROLE").toString());
               ui->login_email->clear();
               ui->login_mdp->clear();
               //ui->login->hide();
               //ui->menu->show();
               ui->stackedWidget->setCurrentIndex(0);

           } else {
               // Password is incorrect
               QMessageBox::critical(this, "Error", "Incorrect password");
           }
       } else {
           // User record not found
           QMessageBox::critical(this, "Error", "Incorrect email");
       }

}
QString MainWindow::generateRandomCode(int length) {
    const QString characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString randomCode;

    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.length();
        randomCode.append(characters[index]);
    }

    return randomCode;
}
void MainWindow::on_oublier_clicked()
{
    QString email=ui->login_email->text();
    QString code = generateRandomCode(6); // Generate a 6-character code
    QString message = "Your verification code is: " + code;
    e.setmessage(code);
    emailSender.sendEmail(email, "Recuperation du mot de pass", message);


}

void MainWindow::on_done_clicked()
{
    QString email=ui->login_email->text();
QString code=ui->code->text();
if(code==e.getmessage())
{
    QSqlQuery query;
    query.prepare("SELECT MDP FROM EMPLOYES WHERE MAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {

        QString storedPassword = query.value("MDP").toString();
        QString message = QString("Votre mot de passe est : %1").arg(storedPassword);
        QMessageBox::information(nullptr, QObject::tr("Mot de passe"), message, QMessageBox::Cancel);
    }
}

}

void MainWindow::on_m_employe_clicked()
{
   QString ROLE=e.getROLE();

   if(ROLE == "RH" || ROLE == "ADMIN" || ROLE=="DEV")
   {
       /*ui->menu->hide();
       ui->login->hide();
       ui->gestion_client->show();*/
       ui->stackedWidget->setCurrentIndex(2);

   }
   else
   {
  QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion employe");
   }

}

void MainWindow::on_m_commande_clicked()
{
    QString ROLE=e.getROLE();

    if( ROLE == "ADMIN" )
    {
        /*ui->menu->hide();
        ui->login->hide();
        ui->gestion_client->show();*/
        ui->stackedWidget->setCurrentIndex(8);

    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion commande");
    }
}

void MainWindow::on_g_c_deconnecter_clicked()
{
    /*ui->gestion_client->hide();
    ui->menu->hide();
    ui->login->show();*/
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_g_c_menu_clicked()
{
    /*ui->gestion_client->hide();
    ui->login->hide();
    ui->menu->show();*/
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_m_fournisseur_clicked()
{
    QString ROLE=e.getROLE();

    if( ROLE == "ADMIN" )
    {
        /*ui->menu->hide();
        ui->login->hide();
        ui->gestion_client->show();*/
        ui->stackedWidget->setCurrentIndex(6);

    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion fournisseur");
    }
}

//////////patient//////////////
void MainWindow::on_Ajouter_clicked() {
    int IDP = ui->lineEdit_IDP->text().toInt();
    QString NOM = ui->lineEdit_NOM->text();
    QString PRENOM = ui->lineEdit_PRENOM->text();
    QRegularExpression regex("^[A-Za-zÀ-ÿéèçà]+([ '-][A-Za-zÀ-ÿéèçà]+)*$");
    QRegularExpressionValidator validator(regex, this);
    int pos = 0;

    // Vérification du nom
    if (validator.validate(NOM, pos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Erreur de validation", "Le nom ne doit contenir que des lettres.");
        return;
    }

    // Vérification du prénom
    if (validator.validate(PRENOM, pos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Erreur de validation", "Le prénom ne doit contenir que des lettres.");
        return;
    }
    QString MAIL = ui->lineEdit_MAIL->text();
    QString GENRE = ui->comboBox->currentText();
    int AGE = ui->lineEdit_AGE->text().toInt();

    bool ok;
    int TEL = ui->lineEdit_TELEPHONE->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur de Validation", "Le numéro de téléphone n'est pas valide.");
        return;
    }

    QString TELString = QString::number(TEL);
    // Validation de l'email avec QRegularExpression
    if (MAIL.isEmpty() || !MAIL.contains('@')) {
        QMessageBox::warning(this, "Erreur de Validation", "L'email doit contenir le caractère '@'.");
        return;
    }
    // Validation du numéro de téléphone
    if (TELString.length() != 8 ) {
        QMessageBox::warning(this, "Erreur de Validation", "Le numéro de téléphone (numtel) doit contenir exactement 8 chiffres.");
        return;
    }
    QString AGEString = QString::number(AGE);
    if (AGEString.isEmpty() || AGE<=0) {
        QMessageBox::warning(this, "Erreur de Validation", "L'age n'est pas valide.");
        return;
    }

    // Verify database connection
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database is not open.");
        return;
    }

    // Insert query with all required fields
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO PATIENT (IDP, Nom, Prenom, Mail, Genre, Age, Tel) "
                        "VALUES (:IDP, :Nom, :Prenom, :Mail, :Genre, :Age, :Tel)");

    insertQuery.bindValue(":IDP", QVariant(IDP));           // IDP as integer
    insertQuery.bindValue(":Nom", NOM);                     // Nom as string
    insertQuery.bindValue(":Prenom", PRENOM);               // Prenom as string
    insertQuery.bindValue(":Mail", MAIL);                   // Mail as string
    insertQuery.bindValue(":Genre", GENRE);                 // Genre as string
    insertQuery.bindValue(":Age", QVariant(AGE));           // Age as integer
    insertQuery.bindValue(":Tel", QVariant(TEL));           // Tel as integer

    if (insertQuery.exec()) {
        ui->tableView->setModel(pat.afficher());
        // Envoi d'email après ajout du patient
        //on_pb_notfier_clicked();  // Appel de la fonction pour envoyer un SMS
        on_btn_sendEmail_clicked();
        QMessageBox::information(this, "Success", "Record added successfully.");
    } else {
        qDebug() << "Error on inserting full record:" << insertQuery.lastError().text();
        QMessageBox::critical(this, "Error", insertQuery.lastError().text());
    }
}

void MainWindow::on_Supprimer_clicked()
{
    qDebug() << "Button clicked";
    int IDP =ui->lineEdit_2->text().toInt();
    bool tesst=pat.suprimer(IDP);

    if (tesst)
    {

        ui->tableView->setModel(pat.afficher());
        ui->lineEdit_2->clear();

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Suppression non effectuée\n",
                                          "Click Cancel to exit."),QMessageBox::Cancel);

}
/*void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // Récupérer l'IDP à partir de la ligne cliquée
    int row = index.row();  // Récupérer la ligne cliquée
    QModelIndex idpIndex = ui->tableView->model()->index(row, 0);  // La première colonne contient l'IDP (si c'est le cas)
    QModelIndex nomIndex = ui->tableView->model()->index(row, 1);  // La première colonne contient l'IDP (si c'est le cas)
    QModelIndex prIndex = ui->tableView->model()->index(row, 2);  // La première colonne contient l'IDP (si c'est le cas)
    QModelIndex mailIndex = ui->tableView->model()->index(row, 3);  // La première colonne contient l'IDP (si c'est le cas)
    QModelIndex ageIndex = ui->tableView->model()->index(row, 5);  // La première colonne contient l'IDP (si c'est le cas)
    QModelIndex telIndex = ui->tableView->model()->index(row, 6);  // La première colonne contient l'IDP (si c'est le cas)

    int IDP = ui->tableView->model()->data(idpIndex).toInt();
    QString NOM = ui->tableView->model()->data(nomIndex).toString();
    QString PRENOM = ui->tableView->model()->data(prIndex).toString();
    QString MAIL = ui->tableView->model()->data(mailIndex).toString();
    int AGE = ui->tableView->model()->data(ageIndex).toInt();
    int TEL = ui->tableView->model()->data(telIndex).toInt();

    QSqlQuery query;
    query.prepare("insert into patient(IDP,NOM,PRENOM,MAIL,GENRE,AGE,TEL)" "values(:IDP, :NOM, :PRENOM, :MAIL, :GENRE, :AGE, :TEL)");

    query.bindValue(":IDP",IDP);
    query.bindValue(":Nom",NOM);
    query.bindValue(":Prenom",PRENOM);
    query.bindValue(":Mail",MAIL);
    query.bindValue(":Age",AGE);
    query.bindValue(":Tel",TEL);
    if (query.exec() && query.next()) {
        ui->lineEdit_2->setText(query.value("IDP").toString());
        ui->lineEdit->setText(query.value("IDP").toString());
        ui->lineEdit_IDP->setText(query.value("IDP").toString());
        ui->lineEdit_NOM->setText(query.value("NOM").toString());
        ui->lineEdit_PRENOM->setText(query.value("PRENOM").toString());
        ui->lineEdit_MAIL->setText(query.value("MAIL").toString());
        ui->lineEdit_AGE->setText(query.value("AGE").toString());
        ui->lineEdit_TELEPHONE->setText(query.value("TEL").toString());





    }
    // Demander une confirmation avant la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer la suppression",
                                  "Voulez-vous vraiment supprimer ce patient ?",
                                  QMessageBox::Yes | QMessageBox::No);


    if (reply == QMessageBox::Yes) {
        // Appeler la méthode de suppression
        bool result = pat.suprimer(IDP);

        if (result) {
            // Rafraîchir la table après suppression
            ui->tableView->setModel(pat.afficher());
            QMessageBox::information(this, "Suppression réussie", "Le patient a été supprimé.");
        } else {
            QMessageBox::critical(this, "Erreur", "La suppression a échoué.");
        }
    }
}*/
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // Récupérer la ligne cliquée
    int row = index.row();

    // Accéder aux indices des colonnes
    QModelIndex idpIndex = ui->tableView->model()->index(row, 0);  // IDP dans la première colonne
    QModelIndex nomIndex = ui->tableView->model()->index(row, 1);  // NOM dans la deuxième colonne
    QModelIndex prIndex = ui->tableView->model()->index(row, 2);  // PRENOM dans la troisième colonne
    QModelIndex mailIndex = ui->tableView->model()->index(row, 3);  // MAIL dans la quatrième colonne
    QModelIndex genreIndex = ui->tableView->model()->index(row, 4);  // GENRE dans la cinquième colonne
    QModelIndex ageIndex = ui->tableView->model()->index(row, 5);  // AGE dans la sixième colonne
    QModelIndex telIndex = ui->tableView->model()->index(row, 6);  // TEL dans la septième colonne

    // Récupérer les valeurs des cellules sélectionnées
    int IDP = ui->tableView->model()->data(idpIndex).toInt();
    QString NOM = ui->tableView->model()->data(nomIndex).toString();
    QString PRENOM = ui->tableView->model()->data(prIndex).toString();
    QString MAIL = ui->tableView->model()->data(mailIndex).toString();
    QString GENRE = ui->tableView->model()->data(genreIndex).toString();
    int AGE = ui->tableView->model()->data(ageIndex).toInt();
    int TEL = ui->tableView->model()->data(telIndex).toInt();

    // Afficher les valeurs dans les QLineEdit
    ui->lineEdit_IDP->setText(QString::number(IDP));
    ui->lineEdit_2->setText(QString::number(IDP));
    ui->lineEdit_NOM->setText(NOM);
    ui->lineEdit_PRENOM->setText(PRENOM);
    ui->lineEdit_MAIL->setText(MAIL);
    ui->comboBox->setCurrentText(GENRE);  // Pour afficher l'élément sélectionné dans le ComboBox
    ui->lineEdit_AGE->setText(QString::number(AGE));
    ui->lineEdit_TELEPHONE->setText(QString::number(TEL));

    // Si vous ne voulez pas insérer ces données dans la base de données, il suffit de ne pas exécuter la requête d'insertion
}



void MainWindow::on_Afficher_clicked()
{
    ui->tableView->setModel(pat.afficher());

}





/*
void MainWindow::on_Modifier_clicked()
{
    // Récupération des valeurs saisies
    int IDP = ui->lineEdit_IDP->text().toInt();
    QString NOM = ui->lineEdit_NOM->text();
    QString PRENOM = ui->lineEdit_PRENOM->text();
    QString MAIL = ui->lineEdit_MAIL->text();
    QString GENRE = ui->comboBox->currentText();
    int AGE = ui->lineEdit_AGE->text().toInt();

    // Conversion de TEL
    bool ok;
    int TEL = ui->lineEdit_TELEPHONE->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur de Validation", "Le numéro de téléphone n'est pas valide.");
        return;
    }

    QString TELString = QString::number(TEL);
    // Validation de l'email avec QRegularExpression
    if (MAIL.isEmpty() || !MAIL.contains('@')) {
        QMessageBox::warning(this, "Erreur de Validation", "L'email doit contenir le caractère '@'.");
        return;
    }
    // Validation du numéro de téléphone
    if (TELString.length() != 8 ) {
        QMessageBox::warning(this, "Erreur de Validation", "Le numéro de téléphone (numtel) doit contenir exactement 8 chiffres.");
        return;
    }

    // Mise à jour des informations du patient dans la base de données
    Patient p;
    bool success = p.modifier(IDP, NOM, PRENOM, MAIL, GENRE, AGE, TEL);

    // Si la mise à jour est réussie, on met à jour la vue
    if (success) {
        // Nous pouvons soit rafraîchir toute la table (comme dans votre code original)
        // ui->tableView->setModel(p.afficher());

        // OU on peut simplement mettre à jour la ligne dans le modèle
        // Si vous avez un modèle comme QSqlTableModel, vous pouvez mettre à jour la ligne spécifique

        // Par exemple, mettre à jour la ligne correspondante dans la table :
        QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
        if (model) {
            // Recharger la ligne mise à jour de la base de données
            model->setQuery("SELECT * FROM patient"); // Recharger l'intégralité de la table ou utilisez un filtre pour ne charger qu'une seule ligne
            ui->tableView->setModel(model);
        }

        // Afficher un message de succès
        QMessageBox::information(this, "Succès", "Les informations du patient ont été mises à jour avec succès.");
    } else {
        // Afficher un message d'erreur en cas d'échec
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour des informations du patient.");
    }
}*/

void MainWindow::on_Rechercher_clicked() {
    int IDP = ui->lineEdit_IDP->text().toInt(); // Get the patient code from the line edit

    Patient p;

    // Call the search function to get the model (Assume it returns a QAbstractTableModel or subclass)
    auto model = p.rechercher(IDP); // Use std::unique_ptr

    if (model) {
        // Clear the previous model (If a model is already set in the table view)
        ui->tableView->setModel(nullptr); // Clear the current model from the table view

        // Set the new model to the table view
        ui->tableView->setModel(model.release()); // Transfer ownership of the model

        // Optionally, you can adjust the view settings here:
        ui->tableView->resizeColumnsToContents(); // Automatically resize columns based on content
        ui->tableView->resizeRowsToContents();    // Automatically resize rows based on content
    } else {
        QMessageBox::information(this, "Not Found", "No patient found with that IDP.");

        // Clear the table view (by setting a null model)
        //ui->tableView->setModel(nullptr); // No data to display, clear the view
    }
}



/////////////////////////////////

/*void MainWindow::on_btn_statistiques_clicked()
{
    Patient p;  // Create an instance of patient
    QMap<QString, double> statistiques = p.calculerStatistiquesMoyenT();  // Call the function on the instance

    // Check if the statistics are valid
    if (statistiques.isEmpty()) {
        qDebug() << "Erreur lors du calcul des statistiques.";
        return;
    }

    // Retrieve the percentages for eco-friendly and non-eco-friendly suppliers
    double ecoFriendlyPercentage = statistiques["Eco-friendly"];
    double nonEcoFriendlyPercentage = statistiques["Non-eco-friendly"];

    // Create a bar set for the percentages
    QBarSet *set = new QBarSet("Pourcentage");

    // Add the percentages for eco-friendly and non-eco-friendly suppliers
    *set << ecoFriendlyPercentage << nonEcoFriendlyPercentage;

    // Create categories for X-axis
    QStringList categories;
    categories << "Eco-friendly" << "Non-eco-friendly";

    // Create the bar series and chart
    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Pourcentage des fournisseurs selon le moyen de transport");

    // Create X-axis and add the categories
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create Y-axis for percentage values
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100);  // Y-axis will range from 0 to 100 (percentage)
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create chart view and set it to a fixed size
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(600, 400);  // Adjust the chart size if necessary

    // Show the chart in a pop-up window or as part of the layout
    QDialog *chartDialog = new QDialog(this);  // Create a dialog
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);  // Add layout to dialog
    layout->addWidget(chartView);  // Add the chart view to the layout
    chartDialog->setFixedSize(650, 450);  // Set dialog size to fit the chart
    chartDialog->exec();  // Show the dialog
}
*/
void MainWindow::on_exporter_clicked() {
    Patient p;
    p.exportToPDF();
}


void MainWindow::on_sortButton_clicked() {
    // Get the selected index from the comboBox
    int index = ui->comboBox_sort->currentIndex();

    Patient p;
    QSqlQueryModel *model = new QSqlQueryModel();

    if (index == 0) {  // "Tri selon MAIL"
        model->setQuery("SELECT * FROM patient ORDER BY MAIL ASC");
    } else if (index == 1) {  // "Tri selon AGE"
        model->setQuery("SELECT * FROM patient ORDER BY AGE DESC");
    }

    // Set headers as in your afficher function
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TEL"));

    // Display the sorted data in the table view
    ui->tableView->setModel(model);
}



void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    // Vérifier si le même élément a été cliqué deux fois
    if (lastClickedIndex.isValid() && lastClickedIndex == index) {
        // Si oui, afficher le formulaire de modification
        int IDP = index.sibling(index.row(), 0).data().toInt();  // Supposons que la première colonne contient l'IDP
        showModifyForm(IDP);
    }

    // Mettre à jour l'index du dernier clic
    lastClickedIndex = index;
}

void MainWindow::showModifyForm(int IDP) {
    // 1. Remplir les champs de modification avec les données existantes du patient
    QSqlQuery query;
    query.prepare("SELECT * FROM patient WHERE IDP = :IDP");
    query.bindValue(":IDP", IDP);

    if (query.exec() && query.next()) {
        ui->lineEdit_IDP->setText(query.value("IDP").toString());
        ui->lineEdit_NOM->setText(query.value("Nom").toString());
        ui->lineEdit_PRENOM->setText(query.value("Prenom").toString());
        ui->lineEdit_MAIL->setText(query.value("Mail").toString());
        ui->comboBox->setCurrentText(query.value("Genre").toString());
        ui->lineEdit_AGE->setText(query.value("Age").toString());
        ui->lineEdit_TELEPHONE->setText(query.value("Tel").toString());
        }

    // 2. Afficher les champs cachés
    ui->lineEdit_NOM->setVisible(true);
    ui->lineEdit_PRENOM->setVisible(true);
    ui->lineEdit_MAIL->setVisible(true);
    ui->comboBox->setVisible(true);
    ui->lineEdit_AGE->setVisible(true);
    ui->lineEdit_TELEPHONE->setVisible(true);
    ui->savebutton->setVisible(true);  // Afficher le bouton "Sauvegarder"
}

void MainWindow::on_saveButton_clicked() {
    // 3. Récupérer les nouvelles données et valider
    int IDP = ui->lineEdit_IDP->text().toInt();
    QString NOM = ui->lineEdit_NOM->text();
    QString PRENOM = ui->lineEdit_PRENOM->text();
    QRegularExpression regex("^[A-Za-zÀ-ÿéèçà]+([ '-][A-Za-zÀ-ÿéèçà]+)*$");
    QRegularExpressionValidator validator(regex, this);
    int pos = 0;

    // Vérification du nom
    if (validator.validate(NOM, pos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Erreur de validation", "Le nom ne doit contenir que des lettres.");
        return;
    }

    // Vérification du prénom
    if (validator.validate(PRENOM, pos) != QValidator::Acceptable) {
        QMessageBox::warning(this, "Erreur de validation", "Le prénom ne doit contenir que des lettres.");
        return;
    }
    QString MAIL = ui->lineEdit_MAIL->text();
    QString GENRE = ui->comboBox->currentText();
    int AGE = ui->lineEdit_AGE->text().toInt();
    int TEL = ui->lineEdit_TELEPHONE->text().toInt();

    if (MAIL.isEmpty() || !MAIL.contains('@')) {
        QMessageBox::warning(this, "Erreur", "L'email doit contenir le caractère '@'.");
        return;
    }

    if (TEL <= 0 || TEL > 99999999) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone est invalide.");
        return;
    }

    // 4. Mettre à jour le patient dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE patient SET Nom = :Nom, Prenom = :Prenom, Mail = :Mail, Genre = :Genre, Age = :Age, Tel = :Tel WHERE IDP = :IDP");
    query.bindValue(":Nom", NOM);
    query.bindValue(":Prenom", PRENOM);
    query.bindValue(":Mail", MAIL);
    query.bindValue(":Genre", GENRE);
    query.bindValue(":Age", AGE);
    query.bindValue(":Tel", TEL);
    query.bindValue(":IDP", IDP);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Les informations du patient ont été mises à jour.");
        ui->tableView->setModel(pat.afficher());  // Rafraîchir la table
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour.");
    }

    /*// Cacher les champs après la sauvegarde
    ui->lineEdit_NOM->setVisible(false);
    ui->lineEdit_PRENOM->setVisible(false);
    ui->lineEdit_MAIL->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->lineEdit_AGE->setVisible(false);
    ui->lineEdit_TELEPHONE->setVisible(false);*/
}

void MainWindow::on_Refresh_clicked()
{
    // Vider les champs QLineEdit
    ui->lineEdit_IDP->clear();
    ui->lineEdit_NOM->clear();
    ui->lineEdit_PRENOM->clear();
    ui->lineEdit_MAIL->clear();
    ui->lineEdit_AGE->clear();
    ui->lineEdit_TELEPHONE->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit->clear();



    // Réinitialiser le comboBox à sa première valeur
    ui->comboBox->setCurrentIndex(0); // Met l'index du comboBox à 0 (premier élément)

    // Facultatif: Réinitialiser d'autres widgets si nécessaire
    // Par exemple, pour réinitialiser des QRadioButton, QCheckBox, etc.
}

void MainWindow::on_pb_notfier_clicked()
{
    // Retrieve supplier ID from the input field
    int IDP = ui->lineEdit_IDP->text().toInt();
    QString NOM = ui->lineEdit_NOM->text();
    QString PRENOM = ui->lineEdit_PRENOM->text();

    // Get the expiration date from the DateEdit widget
    QString MAIL = ui->lineEdit_MAIL->text();
    QString GENRE = ui->comboBox->currentText();
    int AGE = ui->lineEdit_AGE->text().toInt();
    QString ageString = QString::number(AGE);  // Conversion de l'entier en QString
    int TEL = ui->lineEdit_TELEPHONE->text().toInt();
    QString telString = QString::number(TEL);  // Conversion de l'entier en QString


    // Create an instance of the sms class
    sms s;

    // Prepare the SMS content
    QString message = "NOUVEAUTE !!\nun nouveau patient etait ajoutee ,\n\n nom :" + NOM + "\n prenom :" + PRENOM + "\n mail : " + MAIL +
                      "\n genre : " + GENRE + "\n age : " + ageString + "\n telephone : " + telString +"\n Cordialement,\nSMARTPHARM";

    // Send the SMS (replace with the supplier's phone number)
    QString phoneNumber = "+21628596153"; // Replace with actual phone number
    s.sendSMS(phoneNumber, message);

    // Optional: Notify the user in the UI that the SMS was sent
    QMessageBox::information(this, tr("Notification"),
                             tr("Le SMS a été envoyé avec succès au patient."),
                             QMessageBox::Ok);
}


#include <QMessageBox>

void MainWindow::on_btn_sendEmail_clicked() {
    // Récupérer les informations saisies par l'utilisateur
    int IDP = ui->lineEdit_IDP->text().toInt();
    QString NOM = ui->lineEdit_NOM->text();
    QString PRENOM = ui->lineEdit_PRENOM->text();
    QString MAIL = ui->lineEdit_MAIL->text(); // Adresse email du destinataire
    QString GENRE = ui->comboBox->currentText();
    int AGE = ui->lineEdit_AGE->text().toInt();
    QString ageString = QString::number(AGE);  // Conversion de l'entier en QString
    int TEL = ui->lineEdit_TELEPHONE->text().toInt();
    QString telString = QString::number(TEL);  // Conversion de l'entier en QString

    // Vérifier si l'IDP est vide
    if (IDP == 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a patient IDP.");
        return;
    }

    // Vérifier si le champ email est vide ou non valide
    if (MAIL.isEmpty() || !MAIL.contains("@") || !MAIL.contains(".")) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid email address.");
        return;
    }

    // Composer l'email
    QString subject = "From SMARTPHARM";
    QString body = "\n\nUn nouveau patient a été ajouté :\n\n"
                   "Nom : " + NOM + "\nPrenom : " + PRENOM +
                   "\nMail : " + MAIL + "\nGenre : " + GENRE +
                   "\nAge : " + ageString + "\nTéléphone : " + telString +
                   "\n\nCordialement,\nSMARTPHARM";

    // Envoyer l'email
    mailer maill;
    int result = maill.sendEmail(MAIL, subject, body); // Envoyer à l'adresse MAIL

    if (result == 0) {
        QMessageBox::information(this, "Success", "Email sent successfully!");
    } else {
        QMessageBox::critical(this, "Failure", "Failed to send email. Check your configuration.");
    }
}
#include <QTimer>

void MainWindow::on_btn_statistiques_clicked()
{
    // Créer un nouveau QWidget pour afficher le graphique
    QWidget* widgetStatistiques = new QWidget(this);  // Créer le widget parent de type QWidget

    // Créer une requête SQL pour récupérer les genres des patients
    QSqlQuery query;
    query.prepare("SELECT Genre FROM PATIENT");

    // Exécuter la requête
    if (query.exec()) {
        // Variables pour compter les genres
        int maleCount = 0;
        int femaleCount = 0;
        int otherCount = 0;

        // Compter les genres dans les résultats
        while (query.next()) {
            QString GENRE = query.value(0).toString().trimmed();  // Récupérer le genre du patient et enlever les espaces
            GENRE = GENRE.toLower();  // Convertir en minuscules pour éviter les problèmes de casse

            // Comparaison avec des valeurs nettoyées
            if (GENRE == "homme") {
                maleCount++;
            } else if (GENRE == "femme") {
                femaleCount++;
            } else {
                otherCount++;
            }
        }

        // Total des patients pour les pourcentages
        int total = maleCount + femaleCount + otherCount;

        // Calcul des pourcentages
        float malePercentage = (total != 0) ? (maleCount * 100.0f) / total : 0.0f;
        float femalePercentage = (total != 0) ? (femaleCount * 100.0f) / total : 0.0f;
        float otherPercentage = (total != 0) ? (otherCount * 100.0f) / total : 0.0f;

        // Ajuster les pourcentages pour que la somme soit 100%
        float totalPercentage = malePercentage + femalePercentage + otherPercentage;
        if (totalPercentage != 100.0f && total != 0) {
            float correction = 100.0f - totalPercentage;
            malePercentage += correction;  // Appliquer la correction sur le plus grand secteur
        }

        // Création du graphique circulaire
        QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);

        // Ajouter les tranches (sections) pour chaque genre
        QPieSlice *maleSlice = series->append(QString("Hommes %1%").arg(QString::number(malePercentage, 'f', 2)), malePercentage);
        maleSlice->setLabelVisible();
        maleSlice->setLabelColor(QColor(Qt::white));
        maleSlice->setBrush(QColor(169, 169, 169));  // Gris clair

        QPieSlice *femaleSlice = series->append(QString("Femmes %1%").arg(QString::number(femalePercentage, 'f', 2)), femalePercentage);
        femaleSlice->setLabelVisible();
        femaleSlice->setLabelColor(QColor(Qt::white));
        femaleSlice->setBrush(QColor(144, 238, 144));  // Vert clair

        QPieSlice *otherSlice = series->append(QString("Autres %1%").arg(QString::number(otherPercentage, 'f', 2)), otherPercentage);
        otherSlice->setLabelVisible();
        otherSlice->setLabelColor(QColor(Qt::white));
        otherSlice->setBrush(QColor(119, 82, 254));  // Vous pouvez aussi ajuster cette couleur

        // Créer un graphique avec la série
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // Définir la couleur de fond du graphique en blanc
        QBrush backgroundBrush(QColor(222, 222, 222));  // Fond blanc
        chart->setBackgroundBrush(backgroundBrush);

        // Créer un QChartView pour afficher le graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setFixedSize(400, 400);  // Définir la taille du graphique
        chartView->setParent(widgetStatistiques);  // Le graphique sera un enfant de widgetStatistiques

        // Appliquer un style pour le widget
        widgetStatistiques->setStyleSheet("background:#d3d3d3; color:white;");
        widgetStatistiques->setGeometry(250, 150, 400, 400);  // Position et taille du widget dans la fenêtre principale
        widgetStatistiques->show();

        // Fermer automatiquement le graphique après 5 secondes
        QTimer::singleShot(6000, widgetStatistiques, &QWidget::close);
    } else {
        // En cas d'erreur lors de l'exécution de la requête
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des statistiques.");
    }
}




/*void MainWindow::on_btn_statistiques_clicked()
{
    // Créer une requête SQL pour récupérer tous les patients
    QSqlQuery query;
    query.prepare("SELECT Genre FROM PATIENT");

    // Exécuter la requête
    if (query.exec()) {
        // Variables pour compter les genres
        int maleCount = 0;
        int femaleCount = 0;
        int otherCount = 0;

        // Compter les genres dans les résultats
        while (query.next()) {
            QString GENRE = query.value(0).toString().trimmed();  // Récupérer le genre du patient et enlever les espaces
            GENRE = GENRE.toLower();  // Convertir en minuscules pour éviter les problèmes de casse

            // Comparaison avec des valeurs nettoyées
            if (GENRE == "homme") {
                maleCount++;
            } else if (GENRE == "femme") {
                femaleCount++;
            } else {
                otherCount++;
            }
        }

        // Afficher les statistiques dans une boîte de message
        QString statsMessage = QString("Statistiques par GENRE :\n"
                                       "Hommes : %1\n"
                                       "Femmes : %2\n"
                                       "Autres : %3")
                                   .arg(maleCount)
                                   .arg(femaleCount)
                                   .arg(otherCount);

        QMessageBox::information(this, "Statistiques des Genres", statsMessage);
    } else {
        // En cas d'erreur lors de l'exécution de la requête
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des statistiques.");
    }
}*/

#include <QTimer>
#include <QDateTime>
#include <QLabel>
void MainWindow::updateTime()
{
    // Récupère l'heure actuelle
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedTime = currentDateTime.toString("hh:mm:ss");  // Format 12 heures

    // Affiche l'heure dans le QLabel
    ui->label_time->setText(formattedTime);

    // Personnalisation du texte : couleur blanche, police Segoe UI, taille 40px, gras et italique
    ui->label_time->setStyleSheet("QLabel { "
                                  "color : white; "
                                  "font-family : 'Segoe UI'; "
                                  "font-size : 14px; "
                                  "font-weight : bold; "
                                  "font-style : italic; "
                                  "}");
}



void MainWindow::setupClock()
{
    // Crée un QTimer qui déclenche une mise à jour chaque seconde (1000 ms)
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);  // 1000 ms = 1 seconde

    // Initialiser l'affichage de l'heure au démarrage
    updateTime();
}


//fournisseur//////////

void MainWindow::showMap()
{
    try {
        // Create dialog
        QDialog *mapDialog = new QDialog(this);
        mapDialog->setWindowTitle("Supplier Locations Map");
        mapDialog->resize(800, 600);

        // Create custom map widget
        SimpleMapWidget *mapWidget = new SimpleMapWidget(mapDialog);

        // Create layout
        QVBoxLayout *mainLayout = new QVBoxLayout(mapDialog);
        mainLayout->addWidget(mapWidget);

        // Add legend
        QLabel *legendLabel = new QLabel("🔴 - Supplier Location");
        mainLayout->addWidget(legendLabel);

        // Get supplier data from database
        QSqlQuery query;
        query.prepare("SELECT NOM, LATITUDE, LONGITUDE FROM FOURNISSEUR");

        if (query.exec()) {
            while (query.next()) {
                QString name = query.value(0).toString();
                double lat = query.value(1).toDouble();
                double lon = query.value(2).toDouble();
                mapWidget->addLocation(name, lat, lon);
            }
        }

        // Add zoom controls
        QHBoxLayout *zoomLayout = new QHBoxLayout();
        QPushButton *zoomInBtn = new QPushButton("+");
        QPushButton *zoomOutBtn = new QPushButton("-");

        zoomLayout->addWidget(zoomInBtn);
        zoomLayout->addWidget(zoomOutBtn);
        zoomLayout->addStretch();

        mainLayout->addLayout(zoomLayout);

        // Show the dialog
        mapDialog->exec();

        // Cleanup
        delete mapDialog;
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("Map error: %1").arg(e.what()));
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "An unknown error occurred while showing the map");
    }
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    // 1. Get data from the clicked row:
    // Important: Check for valid index and data before converting
    if (!index.isValid()) return;


    bool latOk, lonOk;
    double latitude = index.siblingAtColumn(7).data().toDouble(&latOk);
    double longitude = index.siblingAtColumn(8).data().toDouble(&lonOk);

    if (!latOk || !lonOk) {
        qDebug() << "Error converting latitude/longitudeee";
        // Handle the error appropriately, e.g., display a message to the user
        QMessageBox::warning(this,"Error","Invalid latitude or longitude in database.");

        return;
    }




    // 2. Construct the Google Maps URL:
    // Use a QString to build the URL dynamically
    QString link = QString("https://www.google.com/maps/search/?api=1&query=%1,%2").arg(latitude).arg(longitude);

    // 3. Open in the Default Browser:
    // Use QDesktopServices to open the URL, which will use the system's default browser
    QDesktopServices::openUrl(QUrl(link));

}


void MainWindow::on_pushButton_showStats_clicked()
{
    int totalQty = ftmp.totalQuantity();
    double avgPrice = ftmp.averageDeliveryPrice();

    QMessageBox::information(this, "Statistics", QString("Total Quantity: %1\nAverage Delivery Price: %2").arg(totalQty).arg(avgPrice));

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
    if (nom.isEmpty() || mail.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs.");
        return; // Sortir de la fonction si des champs sont vides
    }

    /* Exemple de vérification d'un format d'email
       if (!emailRegex.exactMatch(mail)) {
           QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une adresse email valide.");
           return; // Sortir de la fonction si l'email est invalide
       }*/
    int currentRating = ui->spinBox->text().toInt();
    int LONGITUDE = ui->lineEdit_LONGITUDE->text().toInt();
    int LATITUDE = ui->lineEdit_LATITUDE->text().toInt();

    Fournisseur F(id, quantiter, nom, prenom, mail, prixLevrison, currentRating,LONGITUDE,LATITUDE);
    bool test = F.ajouter();

    if(test)
    {
        // Actualiser l'affichage
        model = ftmp.afficher(); // Update model with new data
        ui->tableView_2->setModel(model);
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
void MainWindow::on_lineEdit_search_textChanged(const QString &text)
{
    QSqlQueryModel *model = ftmp.rechercherParNom(text); // Assuming you search by name
    if (model) {
        ui->tableView_2->setModel(model);
    } else {
        // Handle error, perhaps display a message
        qDebug() << "Error searching";
    }

}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test = ftmp.supprimer(id);

    if(test)
    {
        // Actualiser l'affichage
        ui->tableView_2->setModel(ftmp.afficher());
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
    int currentRating = ui->spinBox->text().toInt();
    int LONGITUDE = ui->lineEdit_LONGITUDE->text().toInt();
    int LATITUDE = ui->lineEdit_LATITUDE->text().toInt();

    Fournisseur F(id, quantiter, nom, prenom, mail, prixLevrison, currentRating,LONGITUDE,LATITUDE);
    bool test = F.modifier();

    if(test)
    {
        // Actualiser l'affichage
        ui->tableView_2->setModel(ftmp.afficher());
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
    ui->lineEdit_mail->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prix->clear();
    ui->lineEdit_LATITUDE->clear();
    ui->lineEdit_LONGITUDE->clear();
    ui->lineEdit_id->clear();
    ui->lineEdit_quantiter->clear();
    ui->tableView_2->setModel(ftmp.afficher());
}
void MainWindow::on_radioButton_nom_clicked() {

    ui->tableView_2->setModel(ftmp.affichern());

}


void MainWindow::on_radioButton_etoile_clicked() {

    ui->tableView_2->setModel(ftmp.affichere());

}
void MainWindow::on_radioButton_deetoile_clicked() {

    ui->tableView_2->setModel(ftmp.afficherdn());

}
void MainWindow::on_radioButton_denom_clicked() {

    ui->tableView_2->setModel(ftmp.afficherde());

}

//add this include


QString MainWindow::generateHtmlFromData(QAbstractItemModel* model) {
    QString html;
    html += "<html><head><title>Supplier List</title></head><body>";
    html += "<h1>Supplier List</h1>";
    html += "<table border='1' cellspacing='0' cellpadding='5'>";
    html += "<tr><th>ID</th><th>Name</th><th>Quantity</th><th>Price</th><th>Rating</th></tr>";

    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            html += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";
    html += "</body></html>";
    return html;
}

void MainWindow::on_pushButton_generatePdf_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QAbstractItemModel* model = ui->tableView_2->model();
    doc.setHtml(generateHtmlFromData(model));
    doc.print(&printer);

    QMessageBox::information(this, "PDF Generated", "PDF saved successfully.");
}
void MainWindow::on_pushButton_showStats2_clicked()
{
    try {
        // Get data from database
        int totalQty = ftmp.totalQuantity();
        double avgPrice = ftmp.averageDeliveryPrice();

        // Create the pie chart
        QPieSeries *series = new QPieSeries();

        // Add slices with values and labels
        series->append("Total Quantity", totalQty);
        series->append("Avg Delivery Price", avgPrice);

        // Make slices more visible
        QPieSlice *slice1 = series->slices().at(0);
        slice1->setLabelVisible(true);
        slice1->setBrush(QColor(Qt::blue));

        QPieSlice *slice2 = series->slices().at(1);
        slice2->setLabelVisible(true);
        slice2->setBrush(QColor(Qt::red));

        // Create chart and set properties
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Supplier Statistics (Pie Chart)");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        // Create chart view
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Create and setup dialog
        QDialog *chartDialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(chartDialog);
        layout->addWidget(chartView);
        chartDialog->setLayout(layout);
        chartDialog->setWindowTitle("Statistics Pie Chart");
        chartDialog->resize(800, 600);

        // Show dialog
        chartDialog->exec();

        // Cleanup
        delete chartDialog;
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("An error occurred: %1").arg(e.what()));
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "An unknown error occurred");
    }
}

/*void MainWindow::arduino_init()
{
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort(this);  // Set parent to manage memory

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id &&
               serialPortInfo.productIdentifier() == arduino_uno_product_id)
            {
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
                break; // Stop searching once Arduino is found
            }
        }
    }

    if(arduino_is_available)
    {
        arduino->setPortName(arduino_port_name);
        if(arduino->open(QSerialPort::ReadOnly))
        {
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);

            connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readSerial);
        }
        else
        {
            QMessageBox::warning(this, "Arduino Connection", "Failed to open the Arduino port!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Arduino Connection", "Arduino not found!");
    }
}

void MainWindow::readSerial()
{
    if(!arduino->isReadable())
        return;

    serialBuffer.append(arduino->readAll());

    // Process each complete line
    while(serialBuffer.contains('\n'))
    {
        int newlineIndex = serialBuffer.indexOf('\n');
        QByteArray line = serialBuffer.left(newlineIndex);
        serialBuffer.remove(0, newlineIndex + 1);

        QString strLine = QString::fromUtf8(line).trimmed();
        qDebug() << "Received Line:" << strLine;  // Debugging

        if(strLine.startsWith("KEY:"))
        {
            QString key = strLine.mid(4); // Extract the key after "KEY:"
            QString currentText = ui->inputLabel->text();
            ui->inputLabel->setText(currentText + key);
        }
        else if(strLine == "CLEAR")
        {
            ui->inputLabel->clear();
        }
        else if(strLine.startsWith("ID:"))
        {
            QString id = strLine.mid(3); // Extract the ID after "ID:"
            ui->inputLabel->clear(); // Clear the input label after processing

            // Reset attempt count on successful input
            // Optionally, you can reset attemptCount here if needed

            // Query the database for delivery info
            QSqlQuery query;
            query.prepare("SELECT NOM, PRENOM, PRIXLEVRISON, QUANTITER FROM FOURNISSEUR WHERE IDF = :id");
            query.bindValue(":id", id.toInt());

            if(query.exec())
            {
                if(query.next())
                {
                    QString name = query.value("NOM").toString();
                    QString prenom = query.value("PRENOM").toString();
                    float price = query.value("PRIXLEVRISON").toFloat();
                    int quantity = query.value("QUANTITER").toInt();

                    QString status = (quantity > 0) ? "Dispo" : "Out of stock";

                    QString message = QString("ouvrir la porte pour:\n"
                                           "ID: %1\n"
                                           "fournisseur: %2 %3\n"
                                           "prix: %.2f\n"
                                           "quantité: %4\n"
                                           "status: %5")
                                .arg(id)
                                .arg(name)
                                .arg(prenom)
                                .arg(price)
                                .arg(quantity)
                                .arg(status);

                    QMessageBox::information(this, "ouverture du porte", message);
                }
                else
                {
                    QMessageBox::warning(this, "Error",
                        QString("No delivery found with ID: %1").arg(id));

                    // Increment attempt count and handle max attempts
                    attemptCount++;
                    if(attemptCount >= maxAttempts)
                    {
                        QMessageBox::critical(this, "Max Attempts Reached",
                            "You have reached the maximum number of attempts.");
                        // Optionally disable input or take other actions
                        arduino->close();
                    }
                }
            }
            else
            {
                QMessageBox::warning(this, "Database Error",
                    "Failed to execute query: " );
            }
        }
    }
}*/

//produit///////////////////////////////////////


// Add a product
void MainWindow::on_addButton_clicked()
{
    produits prod;
    prod.setcode(ui->lineCode->text().toInt());
    prod.setnom(ui->lineName->text());
    prod.setprix(ui->linePrice->text().toFloat());
    prod.setqte(ui->lineqte->text().toInt());
    prod.settype(ui->lineType->text());
    prod.setdesc(ui->lineDesc->text());
    prod.setdate_exp(ui->dateEdit->date());

    //QString imagePath = (!ui->imageLabel->pixmap().isNull()) ? "C:/Users/micro/OneDrive - ESPRIT/Documents" : "";
    //QString imagePath = (!ui->imageLabel->pixmap().isNull()) ? "C://Users//saidi//OneDrive//Documents//MediSoft//MediSoft//images//LogoApp.png" : "";
    //if (prod.ajouter(imagePath)) {
    refreshTable(); // Met à jour la table uniquement en cas de succès
    resetFields();

    //} else {
    // QMessageBox::warning(this, "Erreur", "Échec de l'ajout du produit.");
    //}
}

void MainWindow::resetFields()
{
    ui->lineCode->clear();
    ui->lineDesc->clear();
    ui->lineName->clear();
    ui->linePrice->clear();
    ui->lineqte->clear();
    ui->lineType->clear();
    ui->dateEdit->clear();
    ui->imageLabel->clear();
}

// Slot pour sélectionner et ajouter une image

void MainWindow::on_addImageButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this,
                                                     "Sélectionner une image",
                                                     "",
                                                     "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!imagePath.isEmpty()) {
        QPixmap pixmap(imagePath);
        ui->imageLabel->setPixmap(
            pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "Aucune image sélectionnée.";
    }
}

// Refresh the table
/*void MainWindow::refreshTable()
{
    produits prod;
    auto model = prod.afficher(); // Use std::unique_ptr

    if (model) {
        ui->tableWidget->setRowCount(model->rowCount());
        ui->tableWidget->setColumnCount(model->columnCount());

        // Populate the table widget with data
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int column = 0; column < model->columnCount(); ++column) {
                QTableWidgetItem *newItem = new QTableWidgetItem(
                    model->data(model->index(row, column)).toString());
                ui->tableWidget->setItem(row, column, newItem);
            }
        }
    } else {
        qDebug() << "Model is null, cannot refresh table.";
    }
}*/
void MainWindow::refreshTable()
{
    produits prod;
    auto model = prod.afficher(); // Use std::unique_ptr

    if (model && model->rowCount() > 0 && model->columnCount() > 0) {
        ui->tableWidget->clear();  // Clear the previous data

        ui->tableWidget->setRowCount(model->rowCount());
        ui->tableWidget->setColumnCount(model->columnCount());

        // Populate the table widget with data
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int column = 0; column < model->columnCount(); ++column) {
                QTableWidgetItem *newItem = new QTableWidgetItem(
                    model->data(model->index(row, column)).toString());
                ui->tableWidget->setItem(row, column, newItem);
            }
        }
    } else {
        qDebug() << "Model is null or empty, cannot refresh table.";
    }
}

// Update a product
void MainWindow::on_Modifier_clicked()
{
    int CODE = ui->lineCode->text().toInt();
    produits prod;
    auto model = prod.rechercher(CODE);

    if (model && model->rowCount() > 0) {
        // Populate the fields with data from each column by index
        ui->lineCode->setText(QString::number(CODE));
        ui->linePrice->setText(
            model->data(model->index(0, 1)).toString()); // Assuming price is the second column
        QString dateString = model->data(model->index(0, 2))
                                 .toString(); // Fetch the date string from your model
        QDate DATE_EXP = QDate::fromString(dateString, "yyyy-MM-dd"); // Convert the string to QDate

        // Check if the date is valid before setting it
        if (DATE_EXP.isValid()) {
            ui->dateEdit->setDate(DATE_EXP); // Set the date in the QDateEdit

        } else {
            // Handle invalid date error
            qDebug() << "Invalid date string:" << dateString;
        }

        // Set other fields based on model data
        ui->lineqte->setText(
            model->data(model->index(0, 3)).toString()); // Quantity is the third column
        ui->lineDesc->setText(
            model->data(model->index(0, 4)).toString()); // Description is the fourth column
        ui->lineName->setText(
            model->data(model->index(0, 5)).toString()); // Name is the fifth column
        ui->lineType->setText(
            model->data(model->index(0, 6)).toString()); // Type is the sixth column

        // Réinitialiser les champs
        resetFields();
    } else {
        QMessageBox::warning(this, "Not Found", "No product found with that code.");
    }
}

// Save updated product details
void MainWindow::on_sauvegarder_clicked()
{
    int CODE = ui->lineCode->text().toInt();
    QString NOM = ui->lineName->text();
    float PRIX = ui->linePrice->text().toFloat();
    int QUANTITEE = ui->lineqte->text().toInt();
    QString TYPE = ui->lineType->text();
    QString DESCRIPTION = ui->lineDesc->text();
    QDate DATE_EXP = ui->dateEdit->date();
    QString imagePath = "chemin/vers/l'image.png";
    QByteArray imageByteArray = imagePath.toUtf8();
    produits prod;

    // Call the update function with the code and all other parameters
    if (prod.modifier(CODE, PRIX, DATE_EXP, QUANTITEE, DESCRIPTION, NOM, TYPE, imageByteArray)) {
        QMessageBox::information(this, "Success", "Product updated successfully.");
        refreshTable();
        // Réinitialiser les champs
        resetFields();

    } else {
        QMessageBox::warning(this, "Update Failed", "Failed to update product.");
    }
}

// Delete a product
void MainWindow::on_deleteButton_clicked()
{
    int CODE = ui->lineCode->text().toInt();
    produits prod;
    if (prod.supprimer(CODE)) {
        QMessageBox::information(this, "Success", "Product deleted successfully!");
        refreshTable();
        // Réinitialiser les champs
        resetFields();

    } else {
        QMessageBox::warning(this, "Error", "Failed to delete product.");
    }
}

void MainWindow::on_searchButton_clicked()
{
    int CODE = ui->lineCode->text().toInt(); // Get the product code from the line edit
    produits prod;
    // Call the search function to get the model
    auto model = prod.rechercher(CODE);

    if (model) {
        // Clear previous contents of the table widget
        ui->tableWidget->clear();        // Clear previous contents
        ui->tableWidget->setRowCount(0); // Set the row count to zero

        // Set the column headers based on the model
        ui->tableWidget->setColumnCount(model->columnCount());
        for (int i = 0; i < model->columnCount(); ++i) {
            ui->tableWidget
                ->setHorizontalHeaderItem(i,
                                          new QTableWidgetItem(
                                              model->headerData(i, Qt::Horizontal).toString()));
        }

        // Populate the table widget with the results
        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget->insertRow(row); // Insert a new row
            for (int column = 0; column < model->columnCount(); ++column) {
                // Set the item in the table widget
                ui->tableWidget->setItem(row,
                                         column,
                                         new QTableWidgetItem(
                                             model->data(model->index(row, column)).toString()));
            }
        }

        // No need to manually delete model since we're using std::unique_ptr
    } else {
        QMessageBox::information(this, "Not Found", "No product found with that code.");
        ui->tableWidget->clear(); // Clear the table if nothing is found
    }
}

void MainWindow::trierProduits()
{
    QString critere = ui->trierLine->currentText(); // Récupération du critère sélectionné
    QString queryStr;

    // Construction de la requête SQL en fonction du critère sélectionné
    if (critere == "Prix") {
        queryStr = "SELECT * FROM produits ORDER BY prix ASC";
    } else if (critere == "Date") {
        queryStr = "SELECT * FROM produits ORDER BY date ASC";
    } else if (critere == "Code") {
        queryStr = "SELECT * FROM produits ORDER BY code ASC";
    } else {
        QMessageBox::warning(this, "Erreur", "Critère de tri non valide !");
        return;
    }

    QSqlQuery query(db);
    if (!query.exec(queryStr)) {
        QMessageBox::critical(this,
                              "Erreur",
                              "Erreur lors de l'exécution de la requête : "
                                  + query.lastError().text());
        return;
    }

    // Vidage du tableau avant de remplir
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Remplir le tableau avec les résultats
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Colonnes : code, prix, quantité, description, nom, type, date, image
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("code").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("prix").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("quantite").toString()));
        ui->tableWidget->setItem(row,
                                 3,
                                 new QTableWidgetItem(query.value("description").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("nom").toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("type").toString()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("date").toString()));

        // Gestion de l'image
        QByteArray imageData = query.value("image").toByteArray();
        if (!imageData.isEmpty()) {
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            QLabel *imageLabel = new QLabel();
            imageLabel->setPixmap(pixmap.scaled(50,
                                                50,
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation)); // Taille ajustable
            ui->tableWidget->setCellWidget(row, 7, imageLabel);
        } else {
            ui->tableWidget->setItem(row, 7, new QTableWidgetItem("Aucune image"));
        }

        row++;
    }
}

void MainWindow::on_statistique_clicked()
{
    // Créer un QSqlQuery pour récupérer les données
    QSqlQuery query;

    query.prepare("SELECT EXTRACT(MONTH FROM DATE_EXP) AS mois, COUNT(QUANTITEE) AS total "
                  "FROM PRODUITS "
                  "GROUP BY EXTRACT(MONTH FROM DATE_EXP) "
                  "ORDER BY mois ASC");

    // Vérifiez si la requête s'exécute correctement
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return;
    }

    // Créer un ensemble de barres pour stocker les données
    QBarSet *set = new QBarSet("produits");

    // Liste pour stocker les noms des mois
    QStringList months;

    // Parcourir les résultats de la requête
    while (query.next()) {
        int mois = query.value("mois").toInt();
        int total = query.value("total").toInt();

        // Ajouter les données au set
        *set << total;

        // Ajouter le mois correspondant à la liste
        switch (mois) {
        case 1:
            months << "Janvier";
            break;
        case 2:
            months << "Février";
            break;
        case 3:
            months << "Mars";
            break;
        case 4:
            months << "Avril";
            break;
        case 5:
            months << "Mai";
            break;
        case 6:
            months << "Juin";
            break;
        case 7:
            months << "Juillet";
            break;
        case 8:
            months << "Août";
            break;
        case 9:
            months << "Septembre";
            break;
        case 10:
            months << "Octobre";
            break;
        case 11:
            months << "Novembre";
            break;
        case 12:
            months << "Décembre";
            break;
        }
    }

    // Trouver la valeur maximale pour définir l'axe Y
    double maxValue = 0;
    for (int i = 0; i < set->count(); ++i) {
        double value = set->at(i);
        if (value > maxValue) {
            maxValue = value;
        }
    }

    // Créer une série de barres et y ajouter le set
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Créer le graphique et y ajouter la série
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Produits");

    // Créer l'axe Y basé sur la valeur maximale
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue + 5); // Ajouter une marge au-dessus de la valeur max
    axisY->setTitleText("Quantitées");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer l'axe X avec les noms des mois
    QCategoryAxis *axisX = new QCategoryAxis();
    for (int i = 0; i < months.size(); ++i) {
        axisX->append(months[i], i);
    }
    axisX->setTitleText("Mois");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer une nouvelle boîte de dialogue pour afficher le graphique
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("Statistiques des Produits");

    // Ajouter le graphique à la boîte de dialogue
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);

    // Ajuster la taille et afficher la boîte de dialogue
    chartDialog->resize(600, 400);
    chartDialog->exec();
}

void MainWindow::on_ListProduit_clicked()
{
    QDialog *productDialog = new QDialog(this);
    productDialog->setWindowTitle("Liste des Produits");

    QVBoxLayout *mainLayout = new QVBoxLayout(productDialog);
    QScrollArea *scrollArea = new QScrollArea(productDialog);
    QWidget *scrollWidget = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(scrollWidget);

    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);

    QSqlQuery query;
    query.prepare(
        "SELECT CODE, NOM, DESCRIPTION, PRIX, QUANTITEE, TYPE, DATE_EXP, IMGAGE FROM PRODUITS");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        return;
    }

    int row = 0;
    int col = 0;

    while (query.next()) {
        QString code = query.value("CODE").toString();
        QString nom = query.value("NOM").toString();
        QString description = query.value("DESCRIPTION").toString();
        float prix = query.value("PRIX").toFloat();
        int quantitee = query.value("QUANTITEE").toInt();
        QString type = query.value("TYPE").toString();
        QDate dateExp = query.value("DATE_EXP").toDate();
        QByteArray imageData = query.value("IMGAGE").toByteArray();

        QVBoxLayout *productLayout = new QVBoxLayout();

        // Afficher l'image (ou une image par défaut)
        QLabel *imageLabel = new QLabel();
        QPixmap pixmap;
        if (!imageData.isEmpty() && pixmap.loadFromData(imageData)) {
            imageLabel->setPixmap(
                pixmap.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imageLabel->setPixmap(
                QPixmap(":/images/no-image.png")
                    .scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
        imageLabel->setAlignment(Qt::AlignCenter);
        productLayout->addWidget(imageLabel);

        // Afficher les données sous l'image
        QLabel *infoLabel = new QLabel(QString("<b>%1</b><br>"
                                               "Prix : %2 DT<br>"
                                               "Quantité : %3<br>")
                                           .arg(nom)
                                           .arg(prix, 0, 'f', 2)
                                           .arg(quantitee));
        infoLabel->setWordWrap(true);
        productLayout->addWidget(infoLabel);

        // Ajouter le bouton "Plus"
        QPushButton *moreButton = new QPushButton("Plus");
        connect(moreButton, &QPushButton::clicked, [=]() {
            showProductDetails(code, nom, prix, description, quantitee, type, dateExp, imageData);
        });
        productLayout->addWidget(moreButton);

        QWidget *productWidget = new QWidget();
        productWidget->setLayout(productLayout);
        gridLayout->addWidget(productWidget, row, col);

        col++;
        if (col >= 3) {
            col = 0;
            row++;
        }
    }

    productDialog->resize(800, 600);
    productDialog->exec();
}

void MainWindow::showProductDetails(const QString &code,
                                    const QString &nom,
                                    float prix,
                                    const QString &description,
                                    int quantitee,
                                    const QString &type,
                                    const QDate &dateExp,
                                    const QByteArray &imageData)
{
    QDialog *detailsDialog = new QDialog(this);
    detailsDialog->setWindowTitle("Détails du Produit");

    QVBoxLayout *mainLayout = new QVBoxLayout(detailsDialog);

    // Afficher l'image
    QLabel *imageLabel = new QLabel();
    QPixmap pixmap;
    if (!imageData.isEmpty() && pixmap.loadFromData(imageData)) {
        imageLabel->setPixmap(
            pixmap.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setPixmap(QPixmap(":/images/no-image.png")
                                  .scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(imageLabel);

    // Afficher les informations du produit
    QLabel *infoLabel = new QLabel(QString("<b>Code : </b>%1<br>"
                                           "<b>Nom : </b>%2<br>"
                                           "<b>Prix : </b>%3 DT<br>"
                                           "<b>Type : </b>%4<br>"
                                           "<b>Description : </b>%5<br>"
                                           "<b>Date d'expiration : </b>%6<br>"
                                           "<b>Quantité : </b>%7")
                                       .arg(code)
                                       .arg(nom)
                                       .arg(prix, 0, 'f', 2)
                                       .arg(type)
                                       .arg(description)
                                       .arg(dateExp.toString("dd/MM/yyyy"))
                                       .arg(quantitee));
    infoLabel->setWordWrap(true);
    mainLayout->addWidget(infoLabel);

    detailsDialog->resize(400, 500);
    detailsDialog->exec();
}

//////////////////////////AI/////////////////////////////////////
void MainWindow::on_AiDoctorButton_clicked()
{
    // Ouvrir la fenêtre de chat et afficher le bouton Fermer Ai
    afficherChat();
    initialiserArbre();
}

void MainWindow::initialiserArbre()
{
    // Initialiser la base de données
    QSqlQuery query("SELECT code, type FROM produits");

    racine = nullptr; // Réinitialiser la racine avant de reconstruire l'arbre

    // Parcours de tous les produits dans la base de données
    while (query.next()) {
        QString code = query.value(0).toString();
        QString type = query.value(1).toString();

        // Afficher les données récupérées pour débogage
        qDebug() << "Données récupérées -> Code:" << code << ", Type:" << type;

        // Créer un nouvel objet ProduitAI
        ProduitAI *nouveauProduit = new ProduitAI(code, type);

        // Remplir le tableau 'tab' pour ce produit
        QStringList types = type.split(",");
        nouveauProduit->tab = types.toVector();

        // Afficher le contenu du tableau pour débogage
        qDebug() << "Tab rempli pour le produit avec Code:" << code << ", Type:" << type;
        for (const QString &t : nouveauProduit->tab) {
            qDebug() << "  " << t;
        }

        // Ajouter ce produit à l'arbre
        if (!racine) {
            // Si l'arbre est vide, définir la racine
            racine = nouveauProduit;
        } else {
            // Ajouter ce produit à l'arbre en le comparant à partir de la racine
            ajouterProduit(racine, nouveauProduit);
        }
    }

    // Affichage final pour confirmer l'arbre
    qDebug() << "Construction de l'arbre terminée.";
    afficherArbre(racine);
}

void MainWindow::afficherArbre(ProduitAI *racine)
{
    // Affichage de l'arbre à partir de la racine
    if (racine == nullptr) {
        qDebug() << "L'arbre est vide.";
        return;
    }

    // Afficher l'arbre de manière récursive
    afficherArbreRecursif(racine, 0); // Appeler la fonction récursive pour l'affichage
}

void MainWindow::afficherArbreRecursif(ProduitAI *noeud, int profondeur)
{
    if (!noeud)
        return;

    QString indentation = QString("  ").repeated(
        profondeur); // Ajoute des espaces en fonction de la profondeur
    qDebug() << indentation << "Produit : Code:" << noeud->getCode()
             << ", Type:" << noeud->getType();

    // Afficher les enfants à gauche (NON) et à droite (OUI)
    if (noeud->getNON()) {
        qDebug() << indentation << "-> NON :";
        afficherArbreRecursif(noeud->getNON(), profondeur + 1);
    }
    if (noeud->getOUI()) {
        qDebug() << indentation << "-> OUI :";
        afficherArbreRecursif(noeud->getOUI(), profondeur + 1);
    }
}
void MainWindow::on_FermerAiButton_clicked()
{
    qDebug() << "Fermeture de la fenêtre de chat";

    // Masquer la fenêtre de chat sans la fermer
    if (chatWindow) {
        chatWindow->hide(); // Masquer la fenêtre
    }

    // Supprimer les éléments créés pour le chatbot (labels, line edits, boutons)
    if (aiLabel) {
        delete aiLabel; // Supprimer le label
        aiLabel = nullptr;
    }

    if (aiReponseLineEdit) {
        delete aiReponseLineEdit; // Supprimer le line edit
        aiReponseLineEdit = nullptr;
    }

    if (fermerAiButton) {
        delete fermerAiButton; // Supprimer le bouton Fermer Ai
        fermerAiButton = nullptr;
    }

    // Supprimer l'arbre si nécessaire
    supprimerArbre();
}

/*void MainWindow::on_FermerAiButton_clicked()
{
    qDebug() << "Fermeture de la fenêtre de chat";

    // Fermer la fenêtre de chat
    if (chatWindow) {
        chatWindow->close();  // Fermer la fenêtre du chatbot
        delete chatWindow;    // Supprimer l'objet chatWindow
        chatWindow = nullptr; // Réinitialiser le pointeur
    }

    // Supprimer les éléments créés pour le chatbot (labels, line edits, boutons)
    if (aiLabel) {
        delete aiLabel; // Supprimer le label
        aiLabel = nullptr;
    }

    if (aiReponseLineEdit) {
        delete aiReponseLineEdit; // Supprimer le line edit
        aiReponseLineEdit = nullptr;
    }

    if (fermerAiButton) {
        delete fermerAiButton; // Supprimer le bouton Fermer Ai
        fermerAiButton = nullptr;
    }

    // Supprimer l'arbre si nécessaire
    supprimerArbre();
}
*/
void MainWindow::supprimerArbre()
{
    // Fonction pour supprimer l'arbre en réinitialisant la racine
    if (racine) {
        delete racine;    // Supprimer la racine
        racine = nullptr; // Réinitialiser la racine
        qDebug() << "Arbre supprimé.";
    }
}

void MainWindow::ajouterProduit(ProduitAI *racine, ProduitAI *nouveauProduit)
{
    // Comparer les tableaux 'tab' pour calculer nbr
    int nbr = nouveauProduit->comparerTab(racine);

    // Si nbr > 0, insérer à OUI, sinon insérer à NON
    if (nbr > 0) {
        // Ajouter à OUI (fils droit)
        if (!racine->getOUI()) {
            racine->OUI = nouveauProduit;
            qDebug() << "Produit ajouté à OUI : Code:" << nouveauProduit->code
                     << ", Type:" << nouveauProduit->tab.join(",");
        } else {
            // Si le fils OUI existe déjà, appeler récursivement pour ajouter à OUI
            ajouterProduit(racine->getOUI(), nouveauProduit);
        }
    } else {
        // Ajouter à NON (fils gauche)
        if (!racine->getNON()) {
            racine->NON = nouveauProduit;
            qDebug() << "Produit ajouté à NON : Code:" << nouveauProduit->code
                     << ", Type:" << nouveauProduit->tab.join(",");
        } else {
            // Si le fils NON existe déjà, appeler récursivement pour ajouter à NON
            ajouterProduit(racine->getNON(), nouveauProduit);
        }
    }
}

void MainWindow::afficherChat()
{
    // Créer la fenêtre de chat si elle n'existe pas déjà
    if (!chatWindow) {
        chatWindow = new QTextEdit(this); // Remplacer QWidget par QTextEdit pour afficher du texte
        chatWindow->setWindowTitle("Chatbot");

        chatWindow->setReadOnly(true); // Ne pas permettre la modification par l'utilisateur

        // Rendre le QTextEdit en mode lecture seule (si vous ne voulez pas que l'utilisateur tape dedans)
        chatWindow->setReadOnly(true);

        // Créer le QLineEdit pour saisir la réponse
        aiReponseLineEdit = new QLineEdit(chatWindow);
        aiReponseLineEdit->move(200, 600);  // Position du QLineEdit dans la fenêtre
        aiReponseLineEdit->resize(500, 80); // Taille du QLineEdit

        connect(aiReponseLineEdit, &QLineEdit::returnPressed, this, &MainWindow::onAiReponseSubmit);

        // Créer le bouton Fermer Ai
        fermerAiButton = new QPushButton("Fermer Ai", chatWindow);
        fermerAiButton->move(20, 600); // Position du bouton dans la fenêtre
        connect(fermerAiButton, &QPushButton::clicked, this, &MainWindow::on_FermerAiButton_clicked);

        // Afficher la fenêtre de chat
        chatWindow->resize(800, 800); // Taille de la fenêtre du chatbot
        chatWindow->show();

        // Créer une liste de messages à afficher
        QStringList messages = {"Chatbot : Salut !",
                                "Chatbot : J'espère que vous allez bien.",
                                "Chatbot : Comment puis-je vous aider ?"};

        // Afficher les messages un par un
        afficherMessages(messages, 0);
    }
}

void MainWindow::afficherMessages(const QStringList &messages, int index)
{
    if (index < messages.size()) {
        // Ajouter le message dans le QTextEdit
        chatWindow->append(messages[index]);

        // Planifier le message suivant après 2 secondes
        QTimer::singleShot(2000, [this, messages, index]() {
            afficherMessages(messages, index + 1); // Afficher le prochain message
        });
    }
}

/*void MainWindow::onAiReponseSubmit() {
    // Récupérer la réponse de l'utilisateur
    QString reponse = aiReponseLineEdit->text();

    // Ajouter la réponse de l'utilisateur dans la fenêtre de chat
    chatWindow->append("Moi : " + reponse);

    // Effacer le champ de saisie pour la prochaine réponse
    aiReponseLineEdit->clear();

    // Créer l'objet ProduitAI avec la réponse de l'utilisateur
    ProduitAI* produitAI = new ProduitAI("0", reponse);  // Le code produit est "0" au début

    // Diviser la réponse de l'utilisateur en une liste de types
    QStringList types = reponse.split(",");  // Adapté si les types sont séparés par une virgule
    produitAI->tab = types.toVector();

    // Initialisation des variables
    ProduitAI* produitCourant = racine;  // Commencer à la racine de l'arbre
    bool foundQuestion = false;  // Flag pour savoir si une question a été posée

    // Comparaison avec l'arbre
    while (produitCourant) {
        int nbr = produitAI->comparerTab(produitCourant);  // Comparer la réponse de l'utilisateur avec l'arbre

        if (nbr > 0) {
            // Si le type existe à droite (OUI), aller à droite
            if (produitCourant->getOUI()) {
                produitCourant = produitCourant->getOUI();
            } else {
                break;
            }
        } else {
            // Si le type existe à gauche (NON), aller à gauche
            if (produitCourant->getNON()) {
                produitCourant = produitCourant->getNON();
            } else {
                break;
            }
        }

        // Si un type existe dans l'arbre mais pas dans l'objet, poser une question
        if (!foundQuestion) {
            // Question : est-ce que l'utilisateur a ce type ?
            for (const QString& t : produitCourant->tab) {
                if (!types.contains(t)) {
                    chatWindow->append("Chatbot : Est-ce que vous avez le type " + t + " ?");
                    foundQuestion = true;
                    return;  // Attendre la réponse avant de continuer
                }
            }
        }
    }

    // Si la comparaison est terminée, afficher le code du produit
    chatWindow->append("Chatbot : Le produit trouvé a le code : " + produitAI->getCode());

    // Revenir à la position en bas du chat
    chatWindow->verticalScrollBar()->setValue(chatWindow->verticalScrollBar()->maximum());
}*/

void MainWindow::onAiReponseSubmit()
{
    // Récupérer la réponse de l'utilisateur
    QString reponse = aiReponseLineEdit->text();

    // Ajouter la réponse de l'utilisateur dans la fenêtre de chat
    chatWindow->append("Moi : " + reponse);

    // Effacer le champ de saisie pour la prochaine réponse
    aiReponseLineEdit->clear();

    // Créer l'objet ProduitAI avec la réponse de l'utilisateur
    ProduitAI *produitAI = new ProduitAI("0", reponse); // Le code produit est "0" au début

    // Diviser la réponse de l'utilisateur en une liste de types
    QStringList types = reponse.split(","); // Adapté si les types sont séparés par une virgule
    produitAI->tab = types.toVector();

    // Initialisation des variables
    ProduitAI *produitCourant = racine; // Commencer à la racine de l'arbre
    bool foundQuestion = false;         // Flag pour savoir si une question a été posée
    int questionsPosées = 0;            // Compteur pour le nombre de questions posées
    QSet<QString> typesPosés;           // Ensemble pour garder trace des types déjà posés

    // Comparaison avec l'arbre
    while (produitCourant) {
        int nbr = produitAI->comparerTab(
            produitCourant); // Comparer la réponse de l'utilisateur avec l'arbre

        if (nbr > 0) {
            // Si le type existe à droite (OUI), aller à droite
            if (produitCourant->getOUI()) {
                produitCourant = produitCourant->getOUI();
            } else {
                break;
            }
        } else {
            // Si le type existe à gauche (NON), aller à gauche
            if (produitCourant->getNON()) {
                produitCourant = produitCourant->getNON();
            } else {
                break;
            }
        }

        // Si un type existe dans l'arbre mais pas dans l'objet, poser une question
        if (!foundQuestion && questionsPosées < 3) {
            // Vérifier les types manquants dans l'arbre
            for (const QString &t : produitCourant->tab) {
                if (!types.contains(t) && !typesPosés.contains(t)) {
                    // Poser la question si le type est manquant et non posé précédemment
                    chatWindow->append("Chatbot : Est-ce que vous avez le type " + t + " ?");
                    typesPosés.insert(
                        t); // Ajouter le type à l'ensemble pour éviter de le poser à nouveau
                    questionsPosées++; // Incrémenter le compteur de questions posées
                    return;            // Attendre la réponse avant de continuer
                }
            }
        }
    }

    // Une fois les trois questions posées, afficher le produit trouvé et son code
    chatWindow->append("Chatbot : Le produit trouvé a le code : " + produitAI->getCode());

    // Revenir à la position en bas du chat
    chatWindow->verticalScrollBar()->setValue(chatWindow->verticalScrollBar()->maximum());
}

///////////////////////////////////////////////////////////////////////////////////////

/*void MainWindow::onVentilateurOn()
{
    qDebug() << "onVentilateurOn appelé"; // Afficher un message de débogage

    // Vérifier si l'alerte n'a pas encore été affichée
    if (!ventilateurAllume) {
        // Afficher l'alerte
        QMessageBox::information(this, "Alerte", "Le ventilateur est allumé.");

        // Marquer que l'alerte a été affichée
        ventilateurAllume = true;
        qDebug() << "Ventilateur allumé - Alerte affichée";
    } else {
        qDebug() << "L'alerte a déjà été affichée";
    }
}

/*void MainWindow::onVentilateurOff()
{
    // Optionnel : si vous voulez afficher une alerte lorsque le ventilateur est éteint, vous pouvez le faire ici
    // QMessageBox::information(this, "Alerte", "Le ventilateur est éteint.");

    // Réinitialiser la variable pour permettre à l'alerte de se réafficher quand le ventilateur est rallumé
    ventilateurAllume = false;
    qDebug() << "Ventilateur éteint - Variable réinitialisée";
}

/*void MainWindow::readSerialData()
{
    QByteArray data = serialPort->readAll();
    QTextStream stream(data);
    QString line = stream.readLine();

    if (!line.isEmpty()) {
        // Debugging: show the incoming line in the console
        qDebug() << "Données reçues : " << line;

        // Split the line into parts by ","
        QStringList parts = line.split(',');

        // Déclaration des variables de suivi pour les alertes
        static bool alertTempHighDisplayed = false; // Alerte température élevée, persistante
        static bool alertTempLowDisplayed = false;  // Alerte température basse, persistante

        for (const QString &part : parts) {
            if (part.startsWith("Température actuelle:")) {
                // Extraire la valeur de température
                QString temperatureValue = part.split(":")[1].trimmed();
                // Mettre à jour la variable membre
                temperature = temperatureValue;

                // Convertir la valeur de température en float pour la comparaison
                float temp = temperature.toFloat();

                // Mise à jour de l'étiquette de température
                ui->labelTemp->setText("Température : " + temperature);

                // Afficher la température pour le débogage
                qDebug() << "Température actuelle : " << temp;

                // Vérifier la température et agir en conséquence
                if (temp > 25.0) {
                    // Vérifier si l'alerte de température élevée a déjà été affichée
                    if (!alertTempHighDisplayed) {
                        // Température dépasse 25°C: Afficher l'alerte avec le bouton "Refroidissement"
                        QMessageBox *alertBox = new QMessageBox(this);
                        alertBox->setIcon(QMessageBox::Warning);
                        alertBox->setText("Température élevée ! Risque sur produit 5");
                        alertBox->setInformativeText(
                            "Appuyez sur 'Refroidissement' pour démarrer le ventilateur.");
                        alertBox->setStandardButtons(QMessageBox::Ok);
                        alertBox->button(QMessageBox::Ok)->setText("Refroidissement");

                        // Connecter le bouton "Refroidissement" au démarrage du ventilateur
                        connect(alertBox->button(QMessageBox::Ok),
                                &QPushButton::clicked,
                                this,
                                [this]() {
                                    if (serialPort->isOpen()) {
                                        serialPort->write("TEMP_HIGH");
                                        qDebug() << "Température élevée ! Envoi de la commande "
                                                    "pour démarrer le ventilateur";
                                    }

                                    // Mettre à jour l'état du ventilateur
                                    fanStatus = "ON";
                                    //ui->labelFanState->setText("Ventilateur : " + fanStatus);
                                });

                        alertBox->exec(); // Afficher la boîte de dialogue

                        // Marquer l'alerte comme affichée
                        alertTempHighDisplayed = true;

                        // Mettre à jour l'état du ventilateur
                        fanStatus = "ON";
                        //  ui->labelFanState->setText("Ventilateur : " + fanStatus);
                    }
                }
                /*else if (temp < 25.0) {
                    // Vérifier si l'alerte de température normale a déjà été affichée
                    if (!alertTempLowDisplayed) {
                        // Température inférieure ou égale à 25°C : Afficher l'alerte
                        QMessageBox::information(this, "Température normale", "Température normale. Le ventilateur est éteint.");

                        // Marquer l'alerte comme affichée
                        alertTempLowDisplayed = true;

                        // Envoyer la commande pour arrêter le ventilateur
                        if (serialPort->isOpen()) {
                            serialPort->write("STOP_FAN\n");
                            qDebug() << "Température normale ! Envoi de la commande pour arrêter le ventilateur";
                        }

                        // Mettre à jour l'état du ventilateur
                        fanStatus = "OFF";
                        ui->labelFanState->setText("Ventilateur : " + fanStatus);
                    }
                } else {
                    // Réinitialiser les alertes si la température est entre 22 et 25°C
                    alertTempHighDisplayed = false;
                    alertTempLowDisplayed = false;
                }
            } else if (part.startsWith("Ventilateur:")) {
                // Extraire l'état du ventilateur si nécessaire pour d'autres traitements
                QString fanStatusValue = part.split(":")[1].trimmed();
                fanStatus = fanStatusValue;
                // Mettre à jour l'étiquette du ventilateur
                //ui->labelFanState->setText("Ventilateur : " + fanStatus);
            }
        }
    }
}
*/
/*void MainWindow::updateUI()
{
    if (!temperature.isEmpty() && !fanStatus.isEmpty()) {
        // Mise à jour des labels dans l'interface
        ui->labelTemp->setText("Température : " + temperature);
        // ui->labelFanState->setText("Ventilateur : " + fanStatus);
    }
}*/
///////////////////////////////////////////////////////

/////////////////////////////////////////////////////////

//commandes ////////////////////


bool MainWindow::isDatabaseEmpty() {
    QSqlQuery query("SELECT COUNT(*) FROM COMMANDES");
    if (query.next()) {
        return query.value(0).toInt() == 0;
    }
    return false;

}

bool MainWindow::doesIdcExist(int idc) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE IDC = :idc");
    query.bindValue(":idc", idc);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}





bool MainWindow::validateInput()
{
    int idc = ui->idc->text().toInt();
    int quant = ui->quant->text().toInt();
    QDate dates = ui->date->date();
    float prix_pr = ui->prix->text().toFloat();
    int idf = ui->idf->text().toInt();

    if (idc <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une valeur valide pour 'IDC'.");
        return false;
    }

    if (quant <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une valeur valide pour 'QUANT'.");
        return false;
    }

    if (prix_pr <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une valeur valide pour 'PRIX_PR'.");
        return false;
    }

    if (idf <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer une valeur valide pour 'IDF'.");
        return false;
    }

    if (quant <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "La quantité doit être positive.");
        return false;
    }
    if (prix_pr <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "Le prix doit être positif.");
        return false;
    }


    return true;
}
void MainWindow::generateQRCode(int idc, int quant, QDate dates, float prix_pr, int idf)
{

    QString commandeData = QString("IDC: %1\nQuantité: %2\nDate: %3\nPrix: %4\nIDF: %5")
                               .arg(idc)
                               .arg(quant)
                               .arg(dates.toString("yyyy-MM-dd"))
                               .arg(prix_pr, 0, 'f', 2)
                               .arg(idf);

    // Générer un QR Code avec la méthode encodeData
    QImage qrImage = QZXing::encodeData(commandeData);

    // Sauvegarder le QR code dans un fichier
    qrImage.save("commande_" + QString::number(idc) + ".png");

    // Afficher le QR Code dans le QLabel
    QPixmap pixmap = QPixmap::fromImage(qrImage);
    ui->qrCodeLabel->setPixmap(pixmap);
    ui->qrCodeLabel->setScaledContents(true);  // Ajuste l'image à la taille du QLabel
}

void MainWindow::on_afficher_clicked()
{
    /*QSoundEffect* soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl("click.wav"));  // Chemin vers le fichier son dans les ressources
    soundEffect->setVolume(0.5);  // Facultatif : ajuster le volume
    soundEffect->play();  // Joue le son*/


    // Vérifiez si la base de données est vide
    if (isDatabaseEmpty()) {
        QMessageBox::warning(this, "Alerte", "La base de données est vide.");
        return;
    }

    // Préparez et exécutez la requête SQL
    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDES");

    if (query.exec()) {
        // Créer un modèle pour afficher les données dans un QTableView
        QStandardItemModel *model = new QStandardItemModel(this);

        // Définir les en-têtes de colonne pour le tableau
        model->setHorizontalHeaderLabels(QStringList() << "IDC" << "Quantité" << "Date" << "Prix" << "ID Fournisseur");

        int row = 0;
        // Parcourir les résultats de la requête et remplir le modèle
        while (query.next()) {
            int idc = query.value(0).toInt();
            int quant = query.value(1).toInt();
            QDate date = query.value(2).toDate();
            float prix = query.value(3).toFloat();
            int idf = query.value(4).toInt();

            // Insérer les données dans le modèle pour chaque ligne
            model->setItem(row, 0, new QStandardItem(QString::number(idc)));
            model->setItem(row, 1, new QStandardItem(QString::number(quant)));
            model->setItem(row, 2, new QStandardItem(date.toString("yyyy-MM-dd")));
            model->setItem(row, 3, new QStandardItem(QString::number(prix, 'f', 2)));
            model->setItem(row, 4, new QStandardItem(QString::number(idf)));

            ++row;
        }

        // Affecter le modèle au QTableView pour afficher les données
        ui->tableView_3->setModel(model);
    } else {
        // Si la requête échoue, afficher l'erreur
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'exécution de la requête.");
        qDebug() << "Erreur SQL: " << query.lastError().text();
    }
    ajouterHistorique("Affichage", "Toutes les commandes ont été affichées.");
}

void MainWindow::on_recherche_textChanged(const QString &text)
{
    Commandes commande;
    QStandardItemModel* model = commande.rechercherParIdc(text);

    // Si aucun résultat n'est trouvé, afficher une alerte
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Recherche", "Aucune commande trouvée pour l'IDC donné.");
    }

    ui->tableView_3->setModel(model);  // Met à jour la vue avec le modèle de recherche
}

void MainWindow::on_statButton_clicked() {

    // Exemple de fonction pour générer un graphique
    QBarSet *set = new QBarSet("Exemple");
    *set << 1 << 2 << 3 << 4 << 5;

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();
    ajouterHistorique("Statistiques", "Les statistiques ont été affichées.");
}



void MainWindow::on_ajouter_2_clicked()
{
    // Récupérer la valeur de IDC avant la vérification
    int idc = ui->idc->text().toInt();

    // Vérifier si l'IDC existe déjà
    if (doesIdcExist(idc)) {
        QMessageBox::warning(this, "Alerte", "L'IDC existe déjà dans la base de données.");
        return;
    }

    // Valider les autres entrées
    if (!validateInput()) {
        return;
    }

    int quant = ui->quant->text().toInt();
    QDate dates = ui->date->date();
    float prix_pr = ui->prix->text().toFloat();
    int idf = ui->idf->text().toInt();

    // Créer l'objet Commandes et ajouter la commande
    Commandes commande(idc, quant, dates, prix_pr, idf);
    bool ajoutReussi = commande.ajouter();

    if (ajoutReussi) {
        QMessageBox::information(this, "Ajout réussi", "Commande ajoutée avec succès !");

        // Générer le QR Code pour cette commande
        generateQRCode(idc, quant, dates, prix_pr, idf);

        // Réinitialiser les champs
        ui->idc->clear();
        ui->quant->clear();
        ui->date->setDate(QDate::currentDate());
        ui->prix->clear();
        ui->idf->clear();
    } else {
        QMessageBox::critical(this, "Erreur d'ajout", "Échec de l'ajout de la commande.");
    }
    if (ajoutReussi) {
        ajouterHistorique("Ajout", QString("Commande ajoutée avec IDC = %1").arg(idc));
    }
}


void MainWindow::on_supprimer_clicked()
{
    int idc = ui->idc->text().toInt();
    if (idc <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de commande valide.");
        return;
    }

    Commandes commande;
    bool suppressionReussie = commande.supprimer(idc);
    if (suppressionReussie) {
        QMessageBox::information(this, "Suppression réussie", "Commande supprimée avec succès !");
        ui->tableView_3->setModel(commande.afficher());
    } else {
        QMessageBox::critical(this, "Erreur de suppression", "Échec de la suppression de la commande.");
    }
    if (suppressionReussie) {
        ajouterHistorique("Suppression", QString("Commande supprimée avec IDC = %1").arg(idc));
    }
}

void MainWindow::on_update_clicked()
{
    if (!validateInput()) {
        return;
    }

    // Récupérer les valeurs des champs
    int idc = ui->idc->text().toInt();
    int quant = ui->quant->text().toInt();
    QDate dates = ui->date->date();
    float prix_pr = ui->prix->text().toFloat();
    int idf = ui->idf->text().toInt();

    // Créer une chaîne avec toutes les informations de la commande
    QString commandeData = QString("IDC: %1\nQuantité: %2\nDate: %3\nPrix: %4\nIDF: %5")
                               .arg(idc)
                               .arg(quant)
                               .arg(dates.toString("yyyy-MM-dd"))
                               .arg(prix_pr, 0, 'f', 2)
                               .arg(idf);

    // Générer le QR code avec toutes les informations
    //QImage qrImage = QZXing::encodeData(commandeData, QZXing::EncoderFormat_QR_CODE, QSize(200, 200));
    QZXing qzxing;
    QImage qrImage = qzxing.encodeData("Texte du QR Code", QZXing::EncoderFormat_QR_CODE);

    // Sauvegarder le QR code dans un fichier
    qrImage.save("commande_" + QString::number(idc) + ".png");

    // Créer l'objet Commandes
    Commandes commande(idc, quant, dates, prix_pr, idf);
    bool modificationReussie = commande.modifier();

    if (modificationReussie) {
        QMessageBox::information(this, "Modification réussie", "Commande modifiée avec succès !");

        // Rafraîchir la table avec la commande mise à jour
        ui->tableView_3->setModel(commande.afficher());

        // Rafraîchir l'affichage du QR code dans le QLabel
        QPixmap pixmap = QPixmap::fromImage(qrImage);
        ui->qrCodeLabel->setPixmap(pixmap);
        ui->qrCodeLabel->setScaledContents(true);

        // Réinitialiser les champs
        ui->idc->clear();
        ui->quant->clear();
        ui->date->setDate(QDate::currentDate());
        ui->prix->clear();
        ui->idf->clear();
    } else {
        QMessageBox::critical(this, "Erreur de modification", "Échec de la modification de la commande.");
    }        if (modificationReussie) {
        ajouterHistorique("Modification", QString("Commande modifiée avec IDC = %1").arg(idc));}

}




void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    // Vérifiez si la colonne cliquée est celle de l'IDC (ici, supposons que c'est la première colonne)
    if (index.column() == 0) {
        int idc = index.data().toInt();  // Récupérer l'IDC de la cellule sélectionnée

        // Récupérer la commande par IDC
        Commandes commande = commande.getCommandeByIdc(idc);

        if (!commande.isValidCommande()) {
            QMessageBox::warning(this, "Erreur", "Commande non valide ou introuvable.");
            return;
        }

        // Générer et afficher le QR Code
        generateQRCode(idc, commande.getQuant(), commande.getDates(), commande.getPrix(), commande.getIdf());
    }
}




void MainWindow::on_pdf_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", QString(), "Fichiers PDF (*.pdf)");
    if (filename.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun fichier sélectionné pour l'exportation en PDF.");
        return;
    }

    // Vérifiez si le modèle de la table est valide
    QAbstractItemModel *model = ui->tableView_3->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée disponible dans la table pour exporter en PDF.");
        return;
    }

    QTextDocument doc;
    QTextCursor cursor(&doc);

    // Insère le titre
    QTextBlockFormat titleFormat;
    titleFormat.setAlignment(Qt::AlignCenter);
    QTextCharFormat titleCharFormat;
    titleCharFormat.setFontPointSize(16);
    titleCharFormat.setFontWeight(QFont::Bold);

    cursor.insertBlock(titleFormat);
    cursor.setCharFormat(titleCharFormat);
    cursor.insertText("Tableau des commandes");
    cursor.insertBlock();

    // Crée le tableau
    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(4);
    tableFormat.setAlignment(Qt::AlignHCenter);

    QTextTable *table = cursor.insertTable(model->rowCount() + 1, model->columnCount(), tableFormat);

    // Ajout des en-têtes de colonnes
    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(Qt::lightGray);

    for (int col = 0; col < model->columnCount(); ++col) {
        QVariant headerData = model->headerData(col, Qt::Horizontal);
        if (!headerData.isValid()) continue;

        QTextTableCell cell = table->cellAt(0, col);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.setCharFormat(headerFormat);
        cellCursor.insertText(headerData.toString());
    }

    // Ajout des données
    QTextCharFormat cellFormat;
    cellFormat.setFontPointSize(10);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            if (!index.isValid()) continue;

            QVariant data = model->data(index);
            QTextTableCell cell = table->cellAt(row + 1, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.setCharFormat(cellFormat);
            cellCursor.insertText(data.toString());
        }
    }

    // Configuration de l'imprimante
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    // Impression du document
    doc.print(&printer);

    // Confirmation
    QMessageBox::information(this, "Exportation PDF", "Le tableau complet a été exporté avec succès en format PDF !");
    ajouterHistorique("PDF", "Un PDF des commandes a été généré.");
}


void MainWindow::on_filtrer_clicked() {
    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDES ORDER BY IDC ASC");

    if (query.exec()) {
        qDebug() << "Requête de tri exécutée avec succès.";
        QStandardItemModel* model = new QStandardItemModel(this);
        model->setHorizontalHeaderLabels(QStringList() << "IDC" << "Quant" << "Date" << "Prix_PR" << "IDF");

        int row = 0;
        while (query.next()) {
            model->setItem(row, 0, new QStandardItem(query.value(0).toString()));  // IDC
            model->setItem(row, 1, new QStandardItem(query.value(1).toString()));  // Quant
            model->setItem(row, 2, new QStandardItem(query.value(2).toDate().toString("yyyy-MM-dd")));  // Date
            model->setItem(row, 3, new QStandardItem(QString::number(query.value(3).toFloat(), 'f', 2)));  // Prix_PR
            model->setItem(row, 4, new QStandardItem(query.value(4).toString()));  // IDF
            ++row;
        }

        if (row == 0) {
            QMessageBox::information(this, "Résultat", "Aucune commande trouvée pour le tri.");
        }

        ui->tableView->setModel(model);  // Met à jour la vue
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Impossible d'exécuter la requête de tri : " + query.lastError().text());
        qDebug() << "Erreur SQL :" << query.lastError().text();
    }
    ajouterHistorique("Affichage", "Toutes les commandes ont été trier.");
}
void MainWindow::showStatistics()
{
    // Préparer les données pour les statistiques
    QSqlQuery query;
    query.prepare("SELECT TYPE, COUNT(*) FROM COMMANDES GROUP BY TYPE");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }

    // Créer un QBarSet pour stocker les données
    QBarSeries *series = new QBarSeries();
    QStringList categories;

    while (query.next()) {
        QString type = query.value(0).toString();    // TYPE
        int count = query.value(1).toInt();          // COUNT(*)

        QBarSet *set = new QBarSet(type);
        *set << count;
        series->append(set);

        categories << type; // Ajouter les types comme catégories
    }

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes par type");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Ajouter un axe des catégories (axe X)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories); // Ajouter les catégories à l'axe X
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Ajouter un axe des valeurs (axe Y)
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100); // Définir une plage appropriée pour l'axe Y
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer un QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600); // Ajuster la taille du graphique
    chartView->show(); // Afficher le graphique

    ajouterHistorique("Statistiques", "Les statistiques ont été affichées.");
}




void MainWindow::on_logout_clicked()
{
    // Afficher un message de confirmation avant la déconnexion
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Déconnexion",
                                  "Êtes-vous sûr de vouloir vous déconnecter ?",
                                  QMessageBox::Yes | QMessageBox::No);

    // Vérifier la réponse de l'utilisateur
    if (reply == QMessageBox::Yes) {
        // Action de déconnexion ici, par exemple fermer l'application
        QApplication::quit();
    } else {
        // L'utilisateur a choisi "Non", donc on fait rien
        return;
    }
}


void MainWindow::ajouterHistorique(const QString &action, const QString &description)
{
    // 1. Obtenir la date et l'heure actuelles
    QString dateTime = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");

    // 2. Formater la ligne d'historique
    QString historiqueEntry = dateTime + " - " + action + ": " + description + "\n";

    // 3. Écrire dans un fichier texte
    QFile file("historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << historiqueEntry;
        file.close();
    }

    // 4. Mettre à jour le QLabel de l'interface (supposons que c'est `ui->labelHistorique`)
    QString existingText = ui->labelHistorique->text();
    ui->labelHistorique->setText(existingText + historiqueEntry);
}





void MainWindow::chargerHistorique()
{
    if (!historiqueEfface) {
        // Charger l'historique depuis le fichier texte
        QFile file("historique.txt");

        // Vérifier si le fichier est ouvert
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString historiqueTexte;

            // Lire tout le contenu du fichier et l'ajouter à historiqueTexte
            while (!in.atEnd()) {
                QString line = in.readLine();
                historiqueTexte.append(line + "\n"); // Ajoute chaque ligne au texte
            }

            // Mettre à jour le texte du label avec l'historique chargé
            ui->labelHistorique->setText(historiqueTexte);
            file.close(); // Fermer le fichier après lecture
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
        }
    } else {
        // Si l'historique a été effacé, vider le texte du label
        ui->labelHistorique->clear();
    }
}


void MainWindow::on_supprimerHistorique_clicked()
{
    // Afficher une boîte de confirmation avant de supprimer
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Supprimer l'historique",
                                                              "Êtes-vous sûr de vouloir supprimer tout l'historique ?", QMessageBox::Yes | QMessageBox::No);

    // Si l'utilisateur confirme
    if (reply == QMessageBox::Yes) {
        // Vider le fichier historique.txt
        QFile file("historique.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            file.close(); // Ferme le fichier, ce qui efface son contenu
        }

        // Marquer que l'historique a été effacé
        historiqueEfface = true;

        // Vider le texte du label
        ui->labelHistorique->clear();
    }
}

void MainWindow::on_resetHistoriqueButton_clicked()
{
    // Réinitialiser l'état de l'historique
    historiqueEfface = false;

    // Recharger l'historique depuis le fichier texte dans le label
    chargerHistorique();
}

void MainWindow::on_btnAjouter_clicked()
{
    // Récupération des valeurs entrées par l'utilisateur
    int idCommande = ui->idc->text().toInt();
    int quantiteDemandee = ui->quant->text().toInt();

    // Vérification de la connexion à la base de données
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur de connexion", "La connexion à la base de données est fermée.");
        return;
    }

    // Connexion à la base de données et préparation de la requête
    QSqlQuery query;
    query.prepare("SELECT QUANT, PRIX_PR FROM COMMANDES WHERE IDC = :IDC");
    query.bindValue(":IDC", idCommande);

    if (query.exec()) {
        if (query.next()) {
            int quantiteDisponible = query.value(0).toInt();
            float prix = query.value(1).toFloat();

            // Vérification de la quantité
            if (quantiteDisponible >= quantiteDemandee) {
                // Alerte pour afficher que la quantité est disponible avec le prix
                QString message = QString("La quantité demandée est disponible.\nPrix pour cette quantité: %1").arg(prix * quantiteDemandee);
                QMessageBox::information(this, "Quantité Disponible", message);
            } else {
                // Alerte si la quantité demandée est supérieure à celle en stock
                QString message = QString("La quantité demandée est supérieure à la quantité disponible (%1 en stock).").arg(quantiteDisponible);
                QMessageBox::warning(this, "Stock Insuffisant", message);
            }
        } else {
            QMessageBox::information(this, "Aucune donnée", "Aucune commande trouvée pour cet ID.");
        }
    } else {
        // Afficher l'erreur SQL
        QMessageBox::critical(this, "Erreur", query.lastError().text());
    }
}

void MainWindow::on_btnAfficherRetours_clicked()
{
    // Vérifier si la connexion à la base de données est ouverte
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur de connexion", "La connexion à la base de données est fermée.");
        return;
    }

    // Calculer la date limite : il y a un an
    QDate dateLimite = QDate::currentDate().addYears(-1);

    // Requête SQL pour récupérer les commandes dont la date est supérieure à un an
    QSqlQuery query;
    query.prepare("SELECT IDC, DATES, QUANT FROM COMMANDES WHERE DATES < :dateLimite");
    query.bindValue(":dateLimite", dateLimite);

    if (!query.exec()) {
        // Afficher l'erreur SQL
        QMessageBox::critical(this, "Erreur", query.lastError().text());
        return;
    }

    // Préparer l'affichage des résultats
    QString resultat = "Commandes de retour (plus d'un an) :\n";
    while (query.next()) {
        int idCommande = query.value(0).toInt();
        QString dateCommande = query.value(1).toDate().toString("dd/MM/yyyy");
        int quantite = query.value(2).toInt();

        // Ajouter chaque ligne au résultat
        resultat += QString("ID: %1 | Date: %2 | Quantité: %3\n")
                        .arg(idCommande)
                        .arg(dateCommande)
                        .arg(quantite);
    }

    // Vérifier si aucune commande n'a été trouvée
    if (resultat == "Commandes de retour (plus d'un an) :\n") {
        resultat = "Aucune commande n'est plus vieille d'un an.";
    }

    // Afficher les résultats dans le QLabel
    ui->labelRetours->setText(resultat);
}

/*void MainWindow::initialiserPortSerie() {
    serialPort = new QSerialPort(this);
    serialPort->setPortName("COM3"); // Remplacez par votre port
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::gererDonneesArduino);
        qDebug() << "Port série connecté.";
    } else {
        qDebug() << "Erreur lors de l'ouverture du port série: " << serialPort->errorString();
    }
}

void MainWindow::gererDonneesArduino() {
    QByteArray data = serialPort->readAll();
    QString code = QString::fromUtf8(data).trimmed();

    Commandes commandes;
    if (commandes.verifierCode(code)) {
        serialPort->write("1"); // Code valide : Ouvrir le servo
        qDebug() << "Code valide, servo activé.";
    } else {
        serialPort->write("0"); // Code invalide : Refuser
        qDebug() << "Code invalide.";
    }
}*/
