#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commandes.h"
#include "connection.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QZXing.h>
#include <QPixmap>
#include <QLabel>
#include <QModelIndex>  // Nécessaire pour utiliser QModelIndex

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Génération du QR Code pour une commande
    void generateQRCode(int idc, int quant, QDate dates, float prix_pr, int idf);

    // Gestion des boutons
    void on_ajouter_clicked(); // Ajouter une commande
    void on_afficher_clicked(); // Afficher les commandes
    void on_statButton_clicked();
    void on_supprimer_clicked(); // Supprimer une commande
    void on_update_clicked(); // Mettre à jour une commande
    void on_tableView_clicked(const QModelIndex &index); // Sélectionner une commande dans la table
    void on_pdf_clicked(); // Exporter les commandes en PDF
    void on_recherche_textChanged(const QString &text); // Rechercher des commandes
    void on_filtrer_clicked(); // Filtrer les commandes
    void on_logout_clicked(); // Déconnexion
    bool isDatabaseEmpty();

    bool doesIdcExist(int idc);
    // Validation des données
    bool validateInput(); // Validation des champs avant ajout ou modification
    bool validateEmail(const QString& email); // Validation d'un email (optionnel si requis)
    void showStatistics();
private:
    Ui::MainWindow *ui; // Interface utilisateur associée
    Commandes c; // Objet Commandes pour les opérations CRUD
    int idc; // Variable pour stocker l'ID de commande sélectionné
};

#endif // MAINWINDOW_H
