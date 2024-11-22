#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPageSize>
#include <QMap>
//#include "GraphView.h"
#include <QQuickWidget>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QDialog>


void MainWindow::on_pushButton_showMap_clicked() {
    QMap<QString, QPointF> locationData;

    QSqlQuery query("SELECT NOM, LATITUDE, LONGITUDE FROM FOURNISSEUR");
    while (query.next()) {
        QString name = query.value(0).toString(); // Supplier name
        double latitude = query.value(1).toDouble(); // Latitude
        double longitude = query.value(2).toDouble(); // Longitude
        locationData[name] = QPointF(latitude, longitude);
    }

    // Ensure the QMap is converted to QVariantMap
    QVariantMap variantMap;
    for (const QString &key : locationData.keys()) {
        QPointF point = locationData[key];
        variantMap[key] = QVariant::fromValue(QVariantMap{{"x", point.x()}, {"y", point.y()}});
    }

    QQuickWidget *mapWidget = new QQuickWidget();
    mapWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    mapWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    QQmlContext *context = mapWidget->rootContext();
    context->setContextProperty("locationData", variantMap);

    QDialog *mapDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(mapDialog);
    layout->addWidget(mapWidget);
    mapDialog->setLayout(layout);

    mapDialog->setWindowTitle("Map View");
    mapDialog->resize(800, 600);
    mapDialog->exec();
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
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

            ui->tabWidget->setCurrentIndex(1); // Set to tab 2 at startup
            connect(ui->tableView, &QTableView::clicked, this, &MainWindow::on_tableView_clicked); // Connect the signal


              connect(ui->radioButton_nom, &QPushButton::clicked, this, &MainWindow::on_radioButton_nom_clicked);
              connect(ui->radioButton_etoile, &QPushButton::clicked, this, &MainWindow::on_radioButton_etoile_clicked);
              connect(ui->pushButton_showMap, &QPushButton::clicked, this, &MainWindow::on_pushButton_showMap_clicked);
              connect(ui->on_pushButton_showStats1, &QPushButton::clicked, this, &MainWindow::on_pushButton_showStats1_clicked);



    // Afficher la liste des fournisseurs au démarrage
    //ui->tableView->setModel(ftmp.afficher());
     //ui->tableView->setSortingEnabled(true);

}
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // 1. Get data from the clicked row:
    // Important: Check for valid index and data before converting
    if (!index.isValid()) return;


    bool latOk, lonOk;
    double latitude = index.siblingAtColumn(7).data().toDouble(&latOk);
    double longitude = index.siblingAtColumn(8).data().toDouble(&lonOk);

    if (!latOk || !lonOk) {
        qDebug() << "Error converting latitude/longitude";
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

MainWindow::~MainWindow()
{
    delete ui;
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
                ui->tableView->setModel(model);
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
         ui->tableView->setModel(model);
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
    int currentRating = ui->spinBox->text().toInt();
    int LONGITUDE = ui->lineEdit_LONGITUDE->text().toInt();
    int LATITUDE = ui->lineEdit_LATITUDE->text().toInt();

    Fournisseur F(id, quantiter, nom, prenom, mail, prixLevrison, currentRating,LONGITUDE,LATITUDE);
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
void MainWindow::on_radioButton_nom_clicked() {

            ui->tableView->setModel(ftmp.affichern());

    }


void MainWindow::on_radioButton_etoile_clicked() {

            ui->tableView->setModel(ftmp.affichere());

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
    QAbstractItemModel* model = ui->tableView->model();
    doc.setHtml(generateHtmlFromData(model));
    doc.print(&printer);

    QMessageBox::information(this, "PDF Generated", "PDF saved successfully.");
}
void MainWindow::on_pushButton_showStats1_clicked()
{
    // 1. Fetch Data (example using your existing functions):
    int totalQty = ftmp.totalQuantity();
    double avgPrice = ftmp.averageDeliveryPrice();


    // 2. Create Chart:
    QChart *chart = new QChart();
    chart->setTitle("Supplier Statistics");

    // 3. Create Series (BarSeries for bar chart)
    QBarSeries *series = new QBarSeries();

    // 4. Create Sets (data points for the bars):
    QBarSet *quantitySet = new QBarSet("Total Quantity");
    *quantitySet << totalQty;  // Add data to the set

    QBarSet *priceSet = new QBarSet("Average Delivery Price");
    *priceSet << avgPrice;

    series->append(quantitySet);
    series->append(priceSet);

    chart->addSeries(series);


    // 5. Create Axes (optional but recommended for clarity):
    QStringList categories;
    categories << ""; // Placeholder category (you might have actual categories)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);




    // 6. Display the Chart in a ChartView:
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // For smoother rendering



    // Display in a dialog (recommended):
    QDialog *chartDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);
    chartDialog->setWindowTitle("Statistics Chart");
    chartDialog->resize(800, 600);  // Adjust size as needed
    chartDialog->exec();

    // Memory cleanup (important!):
    delete chartDialog; // Delete the dialog to avoid memory leaks

}
