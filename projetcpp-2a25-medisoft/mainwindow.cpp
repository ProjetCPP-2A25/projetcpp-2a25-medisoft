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
using namespace  QtCharts;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableViewE->setModel(e.afficher());
remplir_combo_idemploye();


QIntValidator *intValidator = new QIntValidator(0, 9999, this);
ui->le_idd->setValidator(intValidator);

QRegExpValidator *charValidator = new QRegExpValidator(QRegExp("^[A-Za-z]+$"), this);
ui->le_nom->setValidator(charValidator);
ui->le_prenom->setValidator(charValidator);
GESTION_EMPLOYE_STATISTIQUE();

ui->login_mdp->setEchoMode(QLineEdit::Password);
ui->menu->hide();
ui->gestion_client->hide();
ui->login->show();



if (A.connect_arduino() == 0) {

          QMessageBox::information(this, "Arduino connecté sur le port:" , A.getarduino_port_name());

      } else {
          qDebug() << "";
          QMessageBox::warning(this,  "","Échec de la connexion à l'Arduino.");

      }
      connect(A.get_serial(), &QSerialPort::readyRead, this, &MainWindow::fonction_rfid);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fonction_rfid()
{
    QByteArray data = A.read_from_arduino();
    QString uid = QString::fromUtf8(data).trimmed(); // Convertir les données en chaîne

        if (uid != "/")
        {
            A.code += uid;
        }
        else
        {
            qDebug() << "UID reçu:" << A.code;

            A.code.remove("/");
            QSqlQuery query;
            query.prepare("SELECT (IDE)   FROM EMPLOYES  WHERE RFID = :code");
            query.bindValue(":code", A.code);
            if (query.exec() && query.next())
            {
                QString id = query.value(0).toString();
            QSqlQuery q;
            q.prepare("UPDATE EMPLOYES SET PRESENCE='Present' WHERE IDE=:id");
            q.bindValue(":id",id);
            q.exec();

                        QMessageBox::information(this, "Succès", "L'UID existe !");
                        A.code = "";

                    }
                    else
                    {
                    // UID does not exist
                        QMessageBox::warning(this, "Erreur", "L'UID n'existe pas !");
                        A.code = "";
                        qDebug() << "UID reçu:" << A.code;

                    }

                }





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
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
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
    ui->menu->hide();
    ui->gestion_client->hide();
    ui->login->show();
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
               ui->login->hide();
               ui->menu->show();
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
       ui->menu->hide();
       ui->login->hide();
       ui->gestion_client->show();
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
        ui->menu->hide();
        ui->login->hide();
        ui->gestion_client->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion commande");
    }
}

void MainWindow::on_g_c_deconnecter_clicked()
{
    ui->gestion_client->hide();
    ui->menu->hide();
    ui->login->show();
}

void MainWindow::on_g_c_menu_clicked()
{
    ui->gestion_client->hide();
    ui->login->hide();
    ui->menu->show();
}

void MainWindow::on_m_fournisseur_clicked()
{
    QString ROLE=e.getROLE();

    if( ROLE == "ADMIN" )
    {
        ui->menu->hide();
        ui->login->hide();
        ui->gestion_client->show();
    }
    else
    {
   QMessageBox::critical(this, "Error", "tu n'as pas l'accès à la gestion fournisseur");
    }
}

void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Quit", "Are you sure you want to quit?",
                                     QMessageBox::Yes | QMessageBox::No);

       // Check the user's response
       if (reply == QMessageBox::Yes) {
           // If Yes is clicked, close the application
           qApp->quit();
           QSqlQuery query;
           query.prepare("UPDATE   EMPLOYES  SET PRESENCE='Absent' ");
           query.exec();
       }
}
