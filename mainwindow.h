#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include <QMainWindow>
#include <email.h>
#include <QSqlTableModel>
#include "patient.h"
#include <QMainWindow>
#include "fournisseur.h"
#include <QMessageBox>
#include <QDebug>
//#include <QWebEngineView>
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include <QDesktopServices>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
//#include <QQuickWidget>
#include <QQmlContext>
#include <QPainter>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QUrl>
#include <QPdfWriter>
//produit
#include <QLineEdit>
#include <QPushButton>
//#include <QSerialPort>
//#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QStringList>
#include <QTextEdit>
#include "produitai.h"
//#include "ventilateur.h"

//commandes
#include "commandes.h"
#include "connection.h"
#include <QZXing.h>
#include <QPixmap>
#include <QModelIndex>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
//#include <QSerialPort>
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







    void on_ajouter_clicked();

    void on_refresh_clicked();

    void on_bt_supprimer_clicked();

    void on_modifier_clicked();
    void remplir_combo_idemploye();

    void on_tableViewE_clicked(const QModelIndex &index);




    void on_PDF_clicked();
    void GESTION_EMPLOYE_STATISTIQUE();

    void on_bt_asc_clicked();

    void on_bt_desc_clicked();

    void on_bt_chercher_clicked();

    void on_envoyer_clicked();

    void on_m_log_out_clicked();

    void on_bt_login_clicked();

    void on_oublier_clicked();
    QString generateRandomCode(int length) ;

    void on_done_clicked();

    void on_m_employe_clicked();

    void on_m_commande_clicked();

    void on_g_c_deconnecter_clicked();

    void on_g_c_menu_clicked();

    void on_m_fournisseur_clicked();
    void on_m_patient_clicked();
    void on_m_produit_clicked();

    //patient
    void on_Ajouter_clicked();
    void on_Supprimer_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_Afficher_clicked();
    void on_modifierr_clicked();
    void on_Rechercher_clicked();
    void on_exporter_clicked();
    void on_sortButton_clicked();
    void on_saveButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);  // Nouveau slot pour gérer le clic sur la table
    void on_Refresh_clicked();
    void on_btn_statistiques_clicked();
    void on_pb_notfier_clicked();
    void on_btn_sendEmail_clicked();
    void updateTime();
    void setupClock();
    //fournisseur
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_actualiser_clicked();
    void on_pushButton_showStats_clicked();
    void on_pushButton_generatePdf_clicked();
    void on_tableView_2_clicked(const QModelIndex &index);
    void on_lineEdit_search_textChanged(const QString &text);
    void on_radioButton_etoile_clicked();
    void on_radioButton_deetoile_clicked();
    void on_radioButton_denom_clicked();
    void on_radioButton_nom_clicked();
    QString generateHtmlFromData(QAbstractItemModel* model);
    void showMap();
    void on_pushButton_showStats2_clicked();
    //void readSerial();
//produit
    void on_addButton_clicked(); // Slot for handling add button clicks
    void on_addImageButton_clicked();
    void on_deleteButton_clicked();
    void on_Modifier_clicked();
    void on_sauvegarder_clicked();
    void on_searchButton_clicked();
    void on_trierLine_changed();
    void trierProduits();
    void on_statistique_clicked();
    void readSerialData();
    void updateUI();
    //void onExportButtonClicked();

    ///////////////////////AI///////////////////////////////////
    void ajouterProduitAI(const QString &code, const QString &type); // Ajouter un objet ProduitAI
    void onAiDoctorClicked();
    void onAiReponseSubmit();
    void on_AiDoctorButton_clicked();
    void on_FermerAiButton_clicked();
    void afficherChat();
    void initialiserArbre();
    // Déclaration de la fonction afficherArbre pour afficher l'arbre de produits
    void afficherArbre(ProduitAI *racine);
    void afficherArbreRecursif(ProduitAI *noeud, int profondeur);

    /////////////////////////////////////////////////////////
//commandes ///////////
    // Génération du QR Code pour une commande
    void generateQRCode(int idc, int quant, QDate dates, float prix_pr, int idf);

    // Gestion des boutons
    void on_ajouter_2_clicked();
    void on_afficher_clicked();
    void on_statButton_clicked();
    void on_supprimer_clicked();
    void on_tableView_3_clicked(const QModelIndex &index);
    void on_update_clicked();
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
     Employee e;
     mailerr emailSender;
     Patient pat;
     QModelIndex lastClickedIndex;  // Stocker l'index de la dernière ligne cliquée
     void showModifyForm(int IDP);
     Fournisseur ftmp; // Instance temporaire pour les opérations CRUD
     QSqlQueryModel* model; // Declare a persistent model
     //QSerialPort *arduino;
     //static const quint16 arduino_uno_vendor_id = 9025;
     //static const quint16 arduino_uno_product_id = 67;
     //QString arduino_port_name;
     //bool arduino_is_available;
     //void arduino_init();
     int attemptCount = 0;
     int maxAttempts = 3;
     // Buffer for incoming serial data
     //QByteArray serialBuffer;
//produit
     /////AI////////////////////
     QPushButton *AiDoctorButton; // Le bouton AiDoctor
     QTextEdit *chatDisplay;      // Pour afficher le chat
     //ProduitAI* racine;                // Racine de l'arbre des produits AI
     QList<ProduitAI *> produitsAI; // Liste pour stocker tous les objets ProduitAI
     void ajouterProduit(ProduitAI *parent, ProduitAI *enfant);
     QTimer *timer; // Déclarez la variable ici

     bool isChatOpen = false;               // État pour vérifier si le chat est ouvert
     QTextEdit *chatWindow = nullptr;       // Pointeur vers la fenêtre du chat
     QPushButton *fermerAiButton = nullptr; // Pointeur pour le bouton Fermer Ai

     ProduitAI *racine = nullptr; // Pointeur vers la racine de l'arbre
     void fermerChat();           // Fonction pour fermer le chat
     void supprimerArbre();
     void afficherMessages(const QStringList &messages, int index);

     /////////////////////////////
     QLabel *aiLabel = nullptr;              // Label pour afficher le message initial
     QLineEdit *aiReponseLineEdit = nullptr; // Champs pour la saisie de la réponse
     QSqlDatabase db;                        // Déclaration de la base de données
     void on_ListProduit_clicked();
     void showProductDetails(const QString &code,
                             const QString &nom,
                             float prix,
                             const QString &description,
                             int quantitee,
                             const QString &type,
                             const QDate &dateExp,
                             const QByteArray &imageData);
     //int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, Q5 = 0; // Quantités à acheter pour les produits 1 à 5
     //QString code1, code2, code3, code4, code5; // Codes des produits correspondants

     // Helper functions
     void refreshTable(); // Function to refresh the table after adding
     void resetFields();

     //////arduino//////////////////////
     /*void onVentilateurOn();
    void onVentilateurOff();
    Ventilateur *ventilateur;
    bool ventilateurAllume = false; // Variable pour suivre l'état du ventilateur
    //QSerialPort *serialPort;
    QTimer *timer;

    QString temperature;
    QString fanStatus;

    void readData(); // Slot pour lire les données envoyées par Arduino
    void startFan();
    QSerialPort *serialPort;*/
     //////////////////////////////////////
//comanndes ///////////////
     Commandes c;
     int idc;
     //QSerialPort* serialPort;
     bool historiqueEfface;
};

//fournisseur
class SimpleMapWidget : public QWidget
{
    Q_OBJECT
public:
    SimpleMapWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setMinimumSize(400, 400);
    }

    void addLocation(const QString &name, double lat, double lon) {
        locations.append({name, lat, lon});
        update();
    }

    void clearLocations() {
        locations.clear();
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // Draw background
        painter.fillRect(rect(), Qt::white);

        // Draw grid
        painter.setPen(QPen(Qt::lightGray, 1, Qt::DashLine));
        int gridSize = 50;
        for(int x = 0; x < width(); x += gridSize) {
            painter.drawLine(x, 0, x, height());
        }
        for(int y = 0; y < height(); y += gridSize) {
            painter.drawLine(0, y, width(), y);
        }

        // Calculate bounds
        if (locations.isEmpty()) return;

        double minLat = locations[0].lat, maxLat = locations[0].lat;
        double minLon = locations[0].lon, maxLon = locations[0].lon;

        for (const auto &loc : locations) {
            minLat = qMin(minLat, loc.lat);
            maxLat = qMax(maxLat, loc.lat);
            minLon = qMin(minLon, loc.lon);
            maxLon = qMax(maxLon, loc.lon);
        }

        /* Add margin
        double latMargin = (maxLat - minLat) * 0.1;
        double lonMargin = (maxLon - minLon) * 0.1;
        minLat -= latMargin;
        maxLat += latMargin;
        minLon -= lonMargin;
        maxLon += lonMargin;*/
        for (int i = 1; i < locations.size(); ++i) {
            int x1 = (locations[i-1].lon - minLon) / (maxLon - minLon) * (width() - 40) + 20;
            int y1 = height() - ((locations[i-1].lat - minLat) / (maxLat - minLat) * (height() - 40) + 20);
            int x2 = (locations[i].lon - minLon) / (maxLon - minLon) * (width() - 40) + 20;
            int y2 = height() - ((locations[i].lat - minLat) / (maxLat - minLat) * (height() - 40) + 20);

            painter.setPen(QPen(Qt::blue, 2));
            painter.drawLine(QPoint(x1, y1), QPoint(x2, y2));
        }

        // Draw locations
        painter.setPen(QPen(Qt::black, 2));
        for (const auto &loc : locations) {
            // Convert coordinates to pixel positions
            int x = (loc.lon - minLon) / (maxLon - minLon) * (width() - 40) + 20;
            int y = height() - ((loc.lat - minLat) / (maxLat - minLat) * (height() - 40) + 20);

            // Draw point
            painter.setBrush(Qt::red);
            painter.drawEllipse(QPoint(x, y), 5, 5);

            // Draw label
            painter.drawText(x + 8, y + 4, loc.name);
        }

        // Draw compass
        painter.setPen(Qt::black);
        painter.setBrush(Qt::white);
        QPoint compassCenter(50, 50);
        painter.drawEllipse(compassCenter, 20, 20);
        painter.drawLine(compassCenter + QPoint(0, -15), compassCenter + QPoint(0, 15));
        painter.drawLine(compassCenter + QPoint(-15, 0), compassCenter + QPoint(15, 0));
        painter.drawText(compassCenter + QPoint(-5, -8), "N");
        painter.drawText(compassCenter + QPoint(-5, 15), "S");
        painter.drawText(compassCenter + QPoint(-15, 5), "W");
        painter.drawText(compassCenter + QPoint(8, 5), "E");
    }

private:
    struct Location {
        QString name;
        double lat;
        double lon;
    };
    QVector<Location> locations;

};
#endif // MAINWINDOW_H

