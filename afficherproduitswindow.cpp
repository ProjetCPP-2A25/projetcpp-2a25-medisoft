/*#include "AfficherProduitsWindow.h"
#include <QHeaderView>
#include <QVBoxLayout>

AfficherProduitsWindow::AfficherProduitsWindow(LesProduits* produits, QWidget* parent)
    : QWidget(parent), lesProduits(produits) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Créer et configurer la table
    tableProduits = new QTableWidget(this);
    tableProduits->setColumnCount(6);  // Code, Nom, Type, Prix, Quantité, Image
    tableProduits->setHorizontalHeaderLabels({"Code", "Nom", "Type", "Prix", "Quantité", "Image"});
    tableProduits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableProduits->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(tableProduits);
    setupTable();
    remplirTable();
}

void AfficherProduitsWindow::setupTable() {
    tableProduits->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableProduits->setSelectionMode(QAbstractItemView::SingleSelection);
}

void AfficherProduitsWindow::remplirTable() {
    const int taille = lesProduits->GetTaille();
    tableProduits->setRowCount(taille);

    for (int i = 0; i < taille; ++i) {
        const Produits& produit = lesProduits->GetProduit(i);

        tableProduits->setItem(i, 0, new QTableWidgetItem(QString::number(produit.GetCode())));
        tableProduits->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(produit.GetNom())));
        tableProduits->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(produit.GetType())));
        tableProduits->setItem(i, 3, new QTableWidgetItem(QString::number(produit.GetPrix())));
        tableProduits->setItem(i, 4, new QTableWidgetItem(QString::number(produit.GetQuantite())));

        // Affichage de l'image si nécessaire
        QTableWidgetItem* imageItem = new QTableWidgetItem();
        imageItem->setIcon(QIcon(":/images/" + QString::fromStdString(produit.GetNom()) + ".png"));
        tableProduits->setItem(i, 5, imageItem);
    }
}*/
