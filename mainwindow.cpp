#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commandes.h"
#include "connection.h"
#include <QZXing.h>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QPainter>
#include <QFileDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTableCell>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSoundEffect>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    c(),
    historiqueEfface(false)
{
    ui->setupUi(this);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked);
    connect(ui->supprimerHistoriqueButton, &QPushButton::clicked, this, &MainWindow::on_supprimerHistorique_clicked);


    chargerHistorique();
}

MainWindow::~MainWindow()
{
    delete ui;

}
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
    QSoundEffect* soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl("click.wav"));  // Chemin vers le fichier son dans les ressources
    soundEffect->setVolume(0.5);  // Facultatif : ajuster le volume
    soundEffect->play();  // Joue le son


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
        ui->tableView->setModel(model);
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

    ui->tableView->setModel(model);  // Met à jour la vue avec le modèle de recherche
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



void MainWindow::on_ajouter_clicked()
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
        ui->tableView->setModel(commande.afficher());
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
    QImage qrImage = QZXing::encodeData(commandeData, QZXing::EncoderFormat_QR_CODE, QSize(200, 200));

    // Sauvegarder le QR code dans un fichier
    qrImage.save("commande_" + QString::number(idc) + ".png");

    // Créer l'objet Commandes
    Commandes commande(idc, quant, dates, prix_pr, idf);
    bool modificationReussie = commande.modifier();

    if (modificationReussie) {
        QMessageBox::information(this, "Modification réussie", "Commande modifiée avec succès !");

        // Rafraîchir la table avec la commande mise à jour
        ui->tableView->setModel(commande.afficher());

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




void MainWindow::on_tableView_clicked(const QModelIndex &index)
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
    QAbstractItemModel *model = ui->tableView->model();
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
    int idCommande = ui->lineEditId->text().toInt();
    int quantiteDemandee = ui->lineEditQuantite->text().toInt();

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

void MainWindow::initialiserPortSerie() {
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
}
