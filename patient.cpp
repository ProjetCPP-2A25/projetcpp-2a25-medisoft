#include "patient.h"
#include "connection.h"
#include <QMessageBox>
#include <QObject>
//#include "ui_parient.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Patient::Patient(int id,QString n,QString p,QString m,QString g,int a,int t)
{
    this->IDP=id;
    this->NOM=n;
    this->PRENOM=p;
    this->MAIL=m;
    this->GENRE=g;
    this->AGE=a;
    this->TEL=t;
}

bool Patient::ajouter()
{

    QSqlQuery query;
    QString res =QString::number(IDP);

    query.prepare("insert into patient(IDP,NOM,PRENOM,MAIL,GENRE,AGE,TEL)" "values(:IDP, :NOM, :PRENOM, :MAIL, :GENRE, :AGE, :TEL)");

    query.bindValue(":IDP",res);
    query.bindValue(":Nom",NOM);
    query.bindValue(":Prenom",PRENOM);
    query.bindValue(":Mail",MAIL);
    query.bindValue(":Genre",GENRE);
    query.bindValue(":Age",AGE);
    query.bindValue(":Tel",TEL);

    qDebug() << "Attempting to insert with values - IDP:" << res
             << "Nom:" << NOM
             << "Prenom:" << PRENOM
             << "Mail:" << MAIL
             << "Genre:" << GENRE
             << "Age:" << AGE
             << "Tel:" << TEL;
    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text();  // Debugging line to show SQL error
        return false;
    }


    return query.exec();

}





QSqlQueryModel * Patient::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from patient");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("GENRE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TEL"));

    return model;
}

bool Patient::suprimer(int IDP)
{
    QSqlQuery query;
    QString res = QString::number(IDP);
    query.prepare("DELETE FROM patient WHERE IDP = :IDP");
    query.bindValue(":IDP", res);
    return query.exec();
}


/*bool Patient::suprimer(int IDP)
{
    QSqlQuery query;
    QString res=QString::number(IDP);
    query.prepare("delete from patient where IDP= :IDP");
    query.bindValue(":IDP",res);
    return query.exec();
}*/

bool Patient::modifier(int id, const QString& n, const QString& p, const QString& m, const QString& g, int a, int t)
{
    QSqlQuery query;
    QString updateQuery = "UPDATE patient SET ";

    bool first = true;

    // Construction de la requête
    if (!n.isEmpty()) {
        updateQuery += "NOM = :NOM";
        first = false;
    }
    if (!p.isEmpty()) {
        if (!first) updateQuery += ", ";
        updateQuery += "PRENOM = :PRENOM";
        first = false;
    }
    if (!m.isEmpty()) {
        if (!first) updateQuery += ", ";
        updateQuery += "MAIL = :MAIL";
        first = false;
    }
    if (!g.isEmpty()) {
        if (!first) updateQuery += ", ";
        updateQuery += "GENRE = :GENRE";
        first = false;
    }
    if (a != -1) {  // Use -1 as a flag to indicate no update for AGE
        if (!first) updateQuery += ", ";
        updateQuery += "AGE = :AGE";
    }
    if (t != -1) {  // Use -1 as a flag to indicate no update for TEL
        if (!first) updateQuery += ", ";
        updateQuery += "TEL = :TEL";
    }

    updateQuery += " WHERE IDP = :IDP";
    query.prepare(updateQuery);

    // Liaison des valeurs à la requête
    query.bindValue(":IDP", id);  // IDP est l'ID passé en paramètre à la méthode
    if (!n.isEmpty()) query.bindValue(":NOM", n);  // Utilisation du paramètre 'n' pour NOM
    if (!p.isEmpty()) query.bindValue(":PRENOM", p);  // Utilisation du paramètre 'p' pour PRENOM
    if (!m.isEmpty()) query.bindValue(":MAIL", m);  // Utilisation du paramètre 'm' pour MAIL
    if (!g.isEmpty()) query.bindValue(":GENRE", g);  // Utilisation du paramètre 'g' pour GENRE
    if (a != -1) query.bindValue(":AGE", a);  // Utilisation du paramètre 'a' pour AGE
    if (t != -1) query.bindValue(":TEL", QString::number(t));  // Convertir 'TEL' en QString si c'est un entier

    return query.exec();  // Exécution de la requête
}
/*
std::unique_ptr<QSqlQueryModel> Patient::rechercher(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM patients WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    auto model = std::make_unique<QSqlQueryModel>(); // Using smart pointer
    model->setQuery(query);
    return model; // Return the model
}
*/
std::unique_ptr<QSqlQueryModel> Patient::rechercher(int IDP) {
    QSqlQuery query;

    // Prepare the SQL query to select a patient by IDP
    query.prepare("SELECT * FROM patient WHERE IDP = :IDP");
    query.bindValue(":IDP", IDP);

    // Debugging: Log the IDP being searched for
    qDebug() << "Executing query for patient with IDP:" << IDP;

    // Execute the query and handle failure
    if (!query.exec()) {
        qDebug() << "Query execution failed for IDP:" << IDP << "Error:" << query.lastError().text();
        return nullptr;  // Return nullptr if the query fails
    }

    // If no rows are returned, log and return nullptr
    if (!query.first()) {
        qDebug() << "No patient found with IDP:" << IDP;
        return nullptr;  // No results found
    }

    // Create the QSqlQueryModel and set the query result
    auto model = std::make_unique<QSqlQueryModel>();
    model->setQuery(query);

    // Debugging: Confirm that a patient was found
    qDebug() << "Patient found with IDP:" << IDP;

    return model;  // Return the populated model
}

/*QMap<QString, double> Patient::calculerStatistiquesMoyenT()
{
    QMap<QString, double> statistiques;

    QSqlQuery query;

    // Query to get the count of eco-friendly suppliers (G or g)
    query.prepare("SELECT COUNT(*) FROM PATIENT WHERE LOWER(moyenT) = 'g'");
    if (!query.exec()) {
        qDebug() << "Échec de la requête SQL pour les patients :" << query.lastError();
        return statistiques;  // Return empty map if query fails
    }

    query.next();
    int ecoFriendlyCount = query.value(0).toInt();

    // Query to get the count of non-eco-friendly suppliers (R or r)
    query.prepare("SELECT COUNT(*) FROM Patient WHERE LOWER(moyenT) = 'r'");
    if (!query.exec()) {
        qDebug() << "Échec de la requête SQL pour les patients :" << query.lastError();
        return statistiques;  // Return empty map if query fails
    }

    query.next();
    int nonEcoFriendlyCount = query.value(0).toInt();

    // Query to get the total number of suppliers
    query.prepare("SELECT COUNT(*) FROM patient");
    if (!query.exec()) {
        qDebug() << "Échec de la requête SQL pour le nombre total de patients :" << query.lastError();
        return statistiques;  // Return empty map if query fails
    }

    query.next();
    int totalCount = query.value(0).toInt();

    // Calculate percentages for eco-friendly and non-eco-friendly suppliers
    double ecoFriendlyPercentage = (double)ecoFriendlyCount / totalCount * 100;
    double nonEcoFriendlyPercentage = (double)nonEcoFriendlyCount / totalCount * 100;

    // Store the results in the map
    statistiques["Eco-friendly"] = ecoFriendlyPercentage;
    statistiques["Non-eco-friendly"] = nonEcoFriendlyPercentage;

    return statistiques;  // Return the map with percentages
}

*/

#include <QFileDialog>  // <-- Include this
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include <QFontMetrics>
#include <QFileInfo>
#include <QStringList>
void Patient::exportToPDF() {
    // Fetch patient data from database
    QSqlQuery query;
    query.prepare("SELECT IDP, NOM, PRENOM, MAIL, GENRE, AGE, TEL FROM patient");
    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        QMessageBox::warning(nullptr, "Error", "Failed to retrieve patient data.");
        return;
    }

    // Create a file dialog to choose the location and name for the PDF
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return; // If the user cancels the save dialog, do nothing
    }

    // Create the PDF writer
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    // Create a painter to draw the content onto the PDF
    QPainter painter(&writer);
    if (!painter.isActive()) {
        qDebug() << "Failed to create painter.";
        return;
    }

    // Set fonts and line height
    QFont font("Times New Roman", 10);
    QFont headerFont("Times New Roman", 12, QFont::Bold);
    painter.setFont(headerFont);

    int margin = 30;       // Margins around the page
    int x = margin;        // Starting X position
    int y = margin + 50;   // Starting Y position (leave room for title)
    int lineHeight = 40;   // Line height for better spacing
    int tableRowHeight = 60; // Row height for table
    int tableColPadding = 10; // Padding inside table cells

    // Load the image
    QImage logoImage("/mnt/data/medisoftt.png");  // Replace with the path to the image if needed
    if (!logoImage.isNull()) {
        // Draw the image at the top-right corner
        int imgWidth = 100;  // Set the desired width of the image
        int imgHeight = 100; // Set the desired height of the image
        int imgX = writer.width() - margin - imgWidth;  // Calculate X position for top-right corner
        int imgY = margin;  // Set Y position at the top
        painter.drawImage(imgX, imgY, logoImage.scaled(imgWidth, imgHeight));  // Draw the image
    }

    // Draw title
    painter.drawText(x, y, "LISTE DES PATIENTS");
    y += lineHeight * 2; // Leave space after the title

    // Column headers
    QStringList headers = {"IDP", "NOM", "PRENOM", "MAIL", "GENRE", "AGE", "TEL"};

    // Adjust the column widths:
    int idpColWidth = 150;  // Wider IDP column
    int emailColWidth = 700;  // Even wider Email column
    int categoryColWidth = 300; // Slightly wider Category column
    int otherColWidth = 300;  // Other columns remain narrower

    // Draw table headers
    int colX = x;
    painter.setFont(headerFont);
    // Draw IDP column with updated width
    painter.drawRect(colX, y, idpColWidth, tableRowHeight);
    painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[0]);
    colX += idpColWidth;

    // Draw Email column with updated width
    painter.drawRect(colX, y, emailColWidth, tableRowHeight);
    painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[3]);
    colX += emailColWidth;

    // Draw the rest of the headers with adjusted widths
    for (int i = 1; i < headers.size(); ++i) {
        if (i != 3) {  // Skip 'MAIL' as it's already handled
            int colWidth = (i == 4) ? categoryColWidth : otherColWidth;
            painter.drawRect(colX, y, colWidth, tableRowHeight);
            painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[i]);
            colX += colWidth;
        }
    }

    y += tableRowHeight; // Move down after the header row

    // Draw the patient data
    painter.setFont(font); // Switch to regular font for data
    while (query.next()) {
        int IDP = query.value("IDP").toInt();
        QString NOM = query.value("NOM").toString();
        QString PRENOM = query.value("PRENOM").toString();
        QString MAIL = query.value("MAIL").toString();
        QString GENRE = query.value("GENRE").toString();
        int AGE = query.value("AGE").toInt();
        int TEL = query.value("TEL").toInt();

        colX = x; // Reset column X position for each row
        QStringList rowData = {
            QString::number(IDP),
            NOM,
            PRENOM,
            MAIL,
            GENRE,
            QString::number(AGE),
            QString::number(TEL),
        };

        // Draw each cell in the row
        // Draw IDP column with updated width
        painter.drawRect(colX, y, idpColWidth, tableRowHeight);
        painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, rowData[0]);
        colX += idpColWidth;

        // Draw Email column with updated width
        painter.drawRect(colX, y, emailColWidth, tableRowHeight);
        painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, rowData[3]);
        colX += emailColWidth;

        // Draw other columns with their respective widths
        for (int i = 1; i < rowData.size(); ++i) {
            if (i != 3) {  // Skip 'MAIL' as it's already handled
                int colWidth = (i == 4) ? categoryColWidth : otherColWidth;
                painter.drawRect(colX, y, colWidth, tableRowHeight);
                painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, rowData[i]);
                colX += colWidth;
            }
        }

        y += tableRowHeight; // Move down after each row

        // If content exceeds the page height, create a new page
        if (y > writer.height() - margin - tableRowHeight) {
            writer.newPage();
            y = margin + 50; // Reset Y position for new page

            // Redraw headers on new page
            colX = x;
            painter.setFont(headerFont);
            painter.drawRect(colX, y, idpColWidth, tableRowHeight);
            painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[0]);
            colX += idpColWidth;
            painter.drawRect(colX, y, emailColWidth, tableRowHeight);
            painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[3]);
            colX += emailColWidth;
            for (int i = 1; i < headers.size(); ++i) {
                if (i != 3) {  // Skip 'MAIL' as it's already handled
                    int colWidth = (i == 4) ? categoryColWidth : otherColWidth;
                    painter.drawRect(colX, y, colWidth, tableRowHeight);
                    painter.drawText(colX + tableColPadding, y + tableRowHeight - 15, headers[i]);
                    colX += colWidth;
                }
            }
            y += tableRowHeight; // Move down after the header row
        }
    }

    painter.end(); // Finalize the painting

    // Show success message
    QMessageBox::information(nullptr, "Export Complete", "Patient data has been successfully exported to PDF.");
}
