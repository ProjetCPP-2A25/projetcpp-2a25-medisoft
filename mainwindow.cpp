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
//using namespace  QtCharts;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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

    connect(ui->g_c_deconnecter_2, &QPushButton::clicked, this, [=]() {
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
/*connect(ui->Ajouter, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
connect(ui->Supprimer, &QPushButton::clicked, this, &MainWindow::on_Supprimer_clicked);
connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::on_tableView_doubleClicked);
connect(ui->Afficher, &QPushButton::clicked, this, &MainWindow::on_Afficher_clicked);
//connect(ui->savebutton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
connect(ui->Rechercher, &QPushButton::clicked, this, &MainWindow::on_Rechercher_clicked);
connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
connect(ui->savebutton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);

connect(ui->btn_statistiques, &QPushButton::clicked, this, &MainWindow::on_btn_statistiques_clicked);
connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);
connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::on_Refresh_clicked);
connect(ui->pb_notfier, &QPushButton::clicked, this, &MainWindow::on_pb_notfier_clicked);
//connect(ui->btn_sendEmail, &QPushButton::clicked, this, &MainWindow::on_btn_sendEmail_clicked);*/



setupClock();


ui->tableView->setModel(pat.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

//////employee////////
#include <QProcess>
#include <QDebug>

void MainWindow::on_m_patient_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

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
        ui->stackedWidget->setCurrentIndex(0);

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
        ui->stackedWidget->setCurrentIndex(0);

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
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    // Récupérer l'IDP à partir de la ligne cliquée
    int row = index.row();  // Récupérer la ligne cliquée
    QModelIndex idpIndex = ui->tableView->model()->index(row, 0);  // La première colonne contient l'IDP (si c'est le cas)
    int IDP = ui->tableView->model()->data(idpIndex).toInt();  // Récupérer l'IDP de cette ligne
    QSqlQuery query;
    query.prepare("SELECT * FROM patient WHERE IDP = :IDP");
    query.bindValue(":IDP", IDP);
    if (query.exec() && query.next()) {
        ui->lineEdit_2->setText(query.value("IDP").toString());
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
/*
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
        ui->tableView->setModel(nullptr); // No data to display, clear the view
    }
}
*/
void MainWindow::on_Rechercher_clicked() {
    int IDP = ui->lineEdit->text().toInt(); // Get the patient code from the line edit

    // Validate the IDP input
    if (IDP <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid patient ID.");
        return; // Don't proceed further if ID is invalid
    }

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
        ui->lineEdit->clear();

    } else {
        QMessageBox::information(this, "Not Found", "No patient found with that IDP.");

        // Clear the table view (by setting a null model)
       // ui->tableView->setModel(nullptr); // No data to display, clear the view
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




