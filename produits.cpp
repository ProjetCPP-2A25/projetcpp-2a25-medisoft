#include "produits.h"
#include <QBuffer>
#include <QByteArray> // Pour l'image
#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
// Default constructor
produits::produits()
    : CODE(0)
    , PRIX(0.0)
    , DATE_EXP(QDate(2000, 1, 1))
    , QUANTITEE(0)
    , DESCRIPTION("")
    , NOM("")
    , TYPE("")
    , IMAGE()
{}

// Parameterized constructor
produits::produits(int codeP,
                   float prixP,
                   QDate date_expP,
                   int qteP,
                   QString descP,
                   QString nomP,
                   QString typeP,
                   const QString &imagePath)
    : CODE(codeP)
    , PRIX(prixP)
    , DATE_EXP(date_expP)
    , QUANTITEE(qteP)
    , DESCRIPTION(descP)
    , NOM(nomP)
    , TYPE(typeP)
{
    // Charger l'image et la convertir en QByteArray
    QImage image(imagePath);
    if (!image.isNull()) {
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "PNG");
        IMAGE = byteArray; // Attribuer les données de l'image
    } else {
        qDebug() << "Image non valide : " << imagePath;
        IMAGE.clear();
    }
}

// Create

bool produits::ajouter(const QString &imagePath)
{
    QSqlQuery query;

    // Vérifiez que la base de données est bien ouverte
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database is not open!";
        return false;
    }

    // Si le chemin de l'image est vide, ne pas convertir l'image
    QByteArray imageData;
    if (!imagePath.isEmpty()) {
        imageData = imageToByteArray(imagePath);
        if (imageData.isEmpty()) {
            qDebug() << "Failed to load image data.";
            return false;
        }
    }

    // Préparer la requête d'insertion
    query.prepare(
        "INSERT INTO produits (CODE, NOM, PRIX, QUANTITEE, TYPE, DESCRIPTION, DATE_EXP, IMGAGE) "
        "VALUES (:code, :nom, :prix, :qte, :type, :desc, :date_exp, :image)");

    // Liaison des valeurs
    query.bindValue(":code", CODE);
    query.bindValue(":nom", NOM);
    query.bindValue(":prix", PRIX);
    query.bindValue(":qte", QUANTITEE);
    query.bindValue(":type", TYPE);
    query.bindValue(":desc", DESCRIPTION);
    query.bindValue(":date_exp", DATE_EXP);
    query.bindValue(":image", imageData); // Lier l'image (peut être vide)

    // Exécution de la requête et vérification d'erreur
    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }

    return true;
}

QByteArray produits::imageToByteArray(const QString &imagePath)
{
    // Charger l'image depuis le chemin
    QImage image(imagePath);
    if (image.isNull()) {
        qDebug() << "Image not valid: " << imagePath;
        return QByteArray();
    }

    // Convertir l'image en QByteArray
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    if (!image.save(&buffer,
                    "PNG")) { // Vous pouvez remplacer "PNG" par le format souhaité (ex. "JPG").
        qDebug() << "Failed to save image to QByteArray.";
        return QByteArray();
    }

    return byteArray;
}

// Read
/*std::unique_ptr<QSqlQueryModel> produits::afficher()
{
    auto model = std::make_unique<QSqlQueryModel>();
    model->setQuery("SELECT * FROM produits");

    if (model->lastError().isValid()) {
        qDebug() << "Query execution failed:" << model->lastError().text();
        return nullptr;
    }
    return model; // Use smart pointer for ownership management
}*/
std::unique_ptr<QSqlQueryModel> produits::afficher()
{
    auto model = std::make_unique<QSqlQueryModel>();

    // Exécution de la requête SQL
    model->setQuery("SELECT * FROM produits");

    // Vérification des erreurs de la requête SQL
    if (model->lastError().isValid()) {
        qDebug() << "Query execution failed:" << model->lastError().text();
        return nullptr;  // Retourner nullptr si la requête échoue
    }

    // Si la requête réussit, retourner le modèle
    return model;
}


/*void produits::afficherImage(QLabel* label, int codeP) {
    QByteArray imageData = getImageFromDatabase(codeP);

    if (!imageData.isEmpty()) {
        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        // Affichage de l'image dans le label
        label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        label->clear();  // Efface l'image si aucune image n'est trouvée
        label->setText("Aucune image disponible");  // Optionnel : message par défaut
    }
}*/

void produits::afficherImage(QLabel *label, int codeP)
{
    QByteArray imageData = getImageFromDatabase(codeP);

    if (!imageData.isEmpty()) {
        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        label->setPixmap(
            pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        label->clear(); // Efface l'image si aucune image n'est trouvée
    }
}

QByteArray produits::getImageFromDatabase(int codeP)
{
    QSqlQuery query;
    query.prepare("SELECT IMAGE FROM produits WHERE CODE = :code");
    query.bindValue(":code", codeP);

    if (!query.exec()) {
        qDebug() << "Database query failed:" << query.lastError();
        return QByteArray(); // Retourne un QByteArray vide en cas d'échec
    }

    if (query.next()) {
        return query.value("IMAGE").toByteArray(); // Récupère l'image sous forme de QByteArray
    }

    return QByteArray(); // Retourne un QByteArray vide si aucune image n'est trouvée
}

// Update

bool produits::modifier(int codeP,
                        float prixP,
                        const QDate &dateP,
                        int qteP,
                        const QString &descP,
                        const QString &nomP,
                        const QString &typeP,
                        const QByteArray &imageP)
{
    QSqlQuery query;

    query.prepare("UPDATE produits SET PRIX = :prix, DATE_EXP = :date_exp, QUANTITEE = :qte, "
                  "DESCRIPTION = :desc, NOM = :nom, TYPE = :type, IMAGE = :image "
                  "WHERE CODE = :code");

    query.bindValue(":code", codeP);
    query.bindValue(":prix", prixP);
    query.bindValue(":date_exp", dateP);
    query.bindValue(":qte", qteP);
    query.bindValue(":desc", descP);
    query.bindValue(":nom", nomP);
    query.bindValue(":type", typeP);
    query.bindValue(":image", imageP); // Lier l'image

    if (!query.exec()) {
        qDebug() << "Update failed:" << query.lastError().text();
        return false;
    }
    return true;
}

// Delete
bool produits::supprimer(int codeP)
{
    QSqlQuery query;
    query.prepare("DELETE FROM produits WHERE code = :code");
    query.bindValue(":code", codeP);

    if (!query.exec()) {
        qDebug() << "Delete failed:" << query.lastError().text();
        return false; // Execute the delete
    }
    return true; // Successfully deleted
}

// Search
std::unique_ptr<QSqlQueryModel> produits::rechercher(int codeP)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM produits WHERE code = :code");
    query.bindValue(":code", codeP);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    auto model = std::make_unique<QSqlQueryModel>(); // Using smart pointer
    model->setQuery(query);
    return model; // Return the model
}

std::unique_ptr<QSqlQueryModel> produits::trier(const QString &critere, const QString &ordre)
{
    auto model = std::make_unique<QSqlQueryModel>();
    QSqlQuery query;

    // Formez la requête de tri en fonction du critère et de l'ordre
    QString queryString = QString("SELECT * FROM produits ORDER BY %1 %2").arg(critere, ordre);

    // Exécutez la requête
    query.prepare(queryString);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête de tri:" << query.lastError().text();
        return nullptr; // Renvoie un pointeur nul si la requête échoue
    }

    return model; // Retourne le modèle rempli avec les données triées
}

std::unique_ptr<QSqlQueryModel> produits::afficher2()
{
    std::unique_ptr<QSqlQueryModel> model(new QSqlQueryModel);
    QSqlQuery query("SELECT * FROM produits"); // Changez selon votre table
    model->setQuery(query);
    return model;
}
