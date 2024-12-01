#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commandes.h"
#include "connection.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QZXing.h>
#include <QPixmap>
#include <QLabel>
#include <QModelIndex>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QSerialPort>

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
    void on_ajouter_clicked();
    void on_afficher_clicked();
    void on_statButton_clicked();
    void on_supprimer_clicked();
    void on_update_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pdf_clicked();
    void on_recherche_textChanged(const QString &text);
    void on_filtrer_clicked();
    void on_logout_clicked();
    bool isDatabaseEmpty();

    bool doesIdcExist(int idc);

    bool validateInput();
    void showStatistics();

    // Gestion de l'historique
    void ajouterHistorique(const QString& action, const QString& description);
     void chargerHistorique();
    void on_supprimerHistorique_clicked();
     void on_resetHistoriqueButton_clicked();
    void on_btnAjouter_clicked();
     void on_btnAfficherRetours_clicked();
    void  initialiserPortSerie();
     void gererDonneesArduino();
private:
    Ui::MainWindow *ui;
    Commandes c;
    int idc;
    QSerialPort* serialPort;
    bool historiqueEfface;
};

#endif // MAINWINDOW_H
