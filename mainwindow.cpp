#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ventilateur.h"

#include "produitai.h"
#include "produits.h"
//#include "listproduit.h"
#include <QSpinBox> // Inclure QSpinBox pour utiliser le widget de saisie de nombre
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

//#include "xlsxdocument.h"
//#include "xlsxformat.h"

#include <QBarSet>
#include <QDebug>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QIntValidator>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QScrollBar>
#include <QSqlError>
#include <QString>
#include <QTimer>
//#include <QXlsx>
#include <QCoreApplication>
//#include <QSerialPort>
//#include <QSerialPortInfo>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
//using namespace QtCharts;

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,timer(new QTimer(this)) // Initialisation correcte

     //ventilateur(new Ventilateur())

{
    ui->setupUi(this);
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
}

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
