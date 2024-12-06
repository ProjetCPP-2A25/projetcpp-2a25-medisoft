#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlQuery>
#include <QStringList>
#include <QTextEdit>
#include <QLineEdit>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "produitai.h"
#include "ventilateur.h"



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_addButton_clicked(); // Slot for handling add button clicks
    void on_addImageButton_clicked();
    void on_deleteButton_clicked();
    void on_Modifier_clicked();
    void on_sauvegarder_clicked();
    void on_searchButton_clicked();
    void on_trierLine_changed();
    void trierProduits();
    void on_statistique_clicked()   ;
    void readSerialData();
    void updateUI();

///////////////////////AI///////////////////////////////////
    void ajouterProduitAI(const QString &code, const QString &type); // Ajouter un objet ProduitAI
    void onAiDoctorClicked();
    void onAiReponseSubmit();
    void on_AiDoctorButton_clicked();
    void on_FermerAiButton_clicked();
    void afficherChat();
    void initialiserArbre();
    // Déclaration de la fonction afficherArbre pour afficher l'arbre de produits
    void afficherArbre(ProduitAI* racine);
    void afficherArbreRecursif(ProduitAI* noeud, int profondeur);

 /////////////////////////////////////////////////////////

private:
    Ui::MainWindow *ui;
    /////AI////////////////////
    QPushButton *AiDoctorButton;      // Le bouton AiDoctor
    QTextEdit *chatDisplay;           // Pour afficher le chat
    //ProduitAI* racine;                // Racine de l'arbre des produits AI
    QList<ProduitAI*> produitsAI;     // Liste pour stocker tous les objets ProduitAI
    void ajouterProduit(ProduitAI* parent, ProduitAI* enfant);

    bool isChatOpen = false;           // État pour vérifier si le chat est ouvert
    QTextEdit* chatWindow = nullptr;   // Pointeur vers la fenêtre du chat
    QPushButton* fermerAiButton = nullptr;  // Pointeur pour le bouton Fermer Ai

    ProduitAI* racine = nullptr;       // Pointeur vers la racine de l'arbre
    void fermerChat();                 // Fonction pour fermer le chat
    void supprimerArbre();
    void afficherMessages(const QStringList& messages, int index) ;

    /////////////////////////////
    QLabel* aiLabel = nullptr;        // Label pour afficher le message initial
    QLineEdit* aiReponseLineEdit = nullptr; // Champs pour la saisie de la réponse
    QSqlDatabase db; // Déclaration de la base de données
    void on_ListProduit_clicked();
    void showProductDetails(const QString &code, const QString &nom, float prix, const QString &description,
                            int quantitee, const QString &type, const QDate &dateExp, const QByteArray &imageData);
    //int Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, Q5 = 0; // Quantités à acheter pour les produits 1 à 5
    //QString code1, code2, code3, code4, code5; // Codes des produits correspondants


    // Helper functions
    void refreshTable(); // Function to refresh the table after adding
    void resetFields();

    //////arduino//////////////////////
    void onVentilateurOn();
    void onVentilateurOff();
    Ventilateur *ventilateur;
    bool ventilateurAllume = false;  // Variable pour suivre l'état du ventilateur
    //QSerialPort *serialPort;
    QTimer *timer;

    QString temperature;
    QString fanStatus;

    void readData();     // Slot pour lire les données envoyées par Arduino
    void startFan();
    QSerialPort *serialPort;
    //////////////////////////////////////
};

#endif // MAINWINDOW_H
