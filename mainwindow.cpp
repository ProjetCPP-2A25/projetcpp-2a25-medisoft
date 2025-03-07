#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPageSize>
#include <QMap>
//#include "GraphView.h"



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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    arduino_init();
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
            connect(ui->tableView, &QTableView::doubleClicked, this, &MainWindow::on_tableView_clicked); // Connect the signal


              connect(ui->radioButton_nom, &QPushButton::clicked, this, &MainWindow::on_radioButton_nom_clicked);
              connect(ui->radioButton_etoile, &QPushButton::clicked, this, &MainWindow::on_radioButton_deetoile_clicked);

              connect(ui->radioButton_nom_2, &QPushButton::clicked, this, &MainWindow::on_radioButton_denom_clicked);
              connect(ui->radioButton_nom_3, &QPushButton::clicked, this, &MainWindow::on_radioButton_etoile_clicked);
              connect(ui->pushButton_showMap, &QPushButton::clicked, this, &MainWindow::showMap);

              connect(ui->on_pushButton_showStats1, &QPushButton::clicked, this, &MainWindow::on_pushButton_showStats2_clicked);
   connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readSerial);


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
    if(arduino->isOpen())
           arduino->close();
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
    ui->lineEdit_mail->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prix->clear();
         ui->lineEdit_LATITUDE->clear();
          ui->lineEdit_LONGITUDE->clear();
           ui->lineEdit_id->clear();
            ui->lineEdit_quantiter->clear();
    ui->tableView->setModel(ftmp.afficher());
}
void MainWindow::on_radioButton_nom_clicked() {

            ui->tableView->setModel(ftmp.affichern());

    }


void MainWindow::on_radioButton_etoile_clicked() {

            ui->tableView->setModel(ftmp.affichere());

}
void MainWindow::on_radioButton_deetoile_clicked() {

            ui->tableView->setModel(ftmp.afficherdn());

    }
void MainWindow::on_radioButton_denom_clicked() {

            ui->tableView->setModel(ftmp.afficherde());

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

void MainWindow::arduino_init()
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
}
