/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gestion_client;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *le_idd;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLabel *label_4;
    QPushButton *modifier;
    QLineEdit *le_mail;
    QLabel *label_5;
    QLineEdit *le_salaire;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *le_tel;
    QPushButton *bt_supprimer;
    QPushButton *refresh;
    QPushButton *ajouter;
    QDateEdit *dateE;
    QTableView *tableViewE;
    QLabel *background;
    QLabel *label_9;
    QComboBox *role;
    QComboBox *combo_ide;
    QLineEdit *lineEdit_chercher;
    QComboBox *combo_tri;
    QComboBox *combo_chercher;
    QPushButton *PDF;
    QLabel *label_stat;
    QPushButton *bt_desc;
    QPushButton *bt_asc;
    QPushButton *bt_chercher;
    QLabel *label_8;
    QLineEdit *to;
    QLabel *label_10;
    QLineEdit *obj;
    QLabel *label_11;
    QLineEdit *body;
    QPushButton *envoyer;
    QPushButton *g_c_deconnecter;
    QPushButton *g_c_menu;
    QGroupBox *login;
    QLabel *bg;
    QPushButton *bt_login;
    QLineEdit *login_email;
    QLineEdit *login_mdp;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *oublier;
    QLabel *label_14;
    QPushButton *done;
    QLineEdit *code;
    QGroupBox *menu;
    QLabel *bg_menu;
    QPushButton *m_employe;
    QPushButton *m_commande;
    QPushButton *m_patient;
    QPushButton *m_fournisseur;
    QPushButton *m_produit;
    QPushButton *m_log_out;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(2097, 1367);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        gestion_client = new QGroupBox(centralWidget);
        gestion_client->setObjectName("gestion_client");
        gestion_client->setGeometry(QRect(10, 10, 1920, 1080));
        label = new QLabel(gestion_client);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 71, 16));
        label_2 = new QLabel(gestion_client);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 71, 16));
        label_3 = new QLabel(gestion_client);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 116, 71, 20));
        le_idd = new QLineEdit(gestion_client);
        le_idd->setObjectName("le_idd");
        le_idd->setGeometry(QRect(140, 40, 113, 20));
        le_nom = new QLineEdit(gestion_client);
        le_nom->setObjectName("le_nom");
        le_nom->setGeometry(QRect(140, 80, 113, 20));
        le_prenom = new QLineEdit(gestion_client);
        le_prenom->setObjectName("le_prenom");
        le_prenom->setGeometry(QRect(140, 120, 113, 20));
        label_4 = new QLabel(gestion_client);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 71, 20));
        modifier = new QPushButton(gestion_client);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(430, 140, 75, 23));
        le_mail = new QLineEdit(gestion_client);
        le_mail->setObjectName("le_mail");
        le_mail->setGeometry(QRect(140, 160, 113, 20));
        label_5 = new QLabel(gestion_client);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 200, 111, 20));
        le_salaire = new QLineEdit(gestion_client);
        le_salaire->setObjectName("le_salaire");
        le_salaire->setGeometry(QRect(140, 240, 113, 20));
        label_6 = new QLabel(gestion_client);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 240, 111, 20));
        label_7 = new QLabel(gestion_client);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 280, 111, 20));
        le_tel = new QLineEdit(gestion_client);
        le_tel->setObjectName("le_tel");
        le_tel->setGeometry(QRect(140, 280, 113, 20));
        bt_supprimer = new QPushButton(gestion_client);
        bt_supprimer->setObjectName("bt_supprimer");
        bt_supprimer->setGeometry(QRect(430, 180, 75, 23));
        refresh = new QPushButton(gestion_client);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(430, 100, 75, 23));
        ajouter = new QPushButton(gestion_client);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(430, 50, 75, 23));
        dateE = new QDateEdit(gestion_client);
        dateE->setObjectName("dateE");
        dateE->setGeometry(QRect(140, 200, 110, 22));
        tableViewE = new QTableView(gestion_client);
        tableViewE->setObjectName("tableViewE");
        tableViewE->setGeometry(QRect(540, 70, 521, 321));
        background = new QLabel(gestion_client);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1171, 731));
        background->setStyleSheet(QString::fromUtf8("background-color:red;"));
        label_9 = new QLabel(gestion_client);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 320, 56, 16));
        role = new QComboBox(gestion_client);
        role->addItem(QString());
        role->addItem(QString());
        role->addItem(QString());
        role->setObjectName("role");
        role->setGeometry(QRect(140, 310, 121, 31));
        combo_ide = new QComboBox(gestion_client);
        combo_ide->setObjectName("combo_ide");
        combo_ide->setGeometry(QRect(432, 230, 81, 22));
        lineEdit_chercher = new QLineEdit(gestion_client);
        lineEdit_chercher->setObjectName("lineEdit_chercher");
        lineEdit_chercher->setGeometry(QRect(532, 410, 121, 31));
        combo_tri = new QComboBox(gestion_client);
        combo_tri->addItem(QString());
        combo_tri->addItem(QString());
        combo_tri->addItem(QString());
        combo_tri->addItem(QString());
        combo_tri->setObjectName("combo_tri");
        combo_tri->setGeometry(QRect(860, 410, 161, 31));
        combo_chercher = new QComboBox(gestion_client);
        combo_chercher->addItem(QString());
        combo_chercher->addItem(QString());
        combo_chercher->addItem(QString());
        combo_chercher->addItem(QString());
        combo_chercher->setObjectName("combo_chercher");
        combo_chercher->setGeometry(QRect(680, 410, 131, 31));
        PDF = new QPushButton(gestion_client);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(560, 30, 93, 28));
        label_stat = new QLabel(gestion_client);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(10, 360, 511, 331));
        bt_desc = new QPushButton(gestion_client);
        bt_desc->setObjectName("bt_desc");
        bt_desc->setGeometry(QRect(950, 460, 75, 23));
        bt_asc = new QPushButton(gestion_client);
        bt_asc->setObjectName("bt_asc");
        bt_asc->setGeometry(QRect(870, 460, 75, 23));
        bt_chercher = new QPushButton(gestion_client);
        bt_chercher->setObjectName("bt_chercher");
        bt_chercher->setGeometry(QRect(550, 460, 111, 31));
        label_8 = new QLabel(gestion_client);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(570, 560, 56, 16));
        to = new QLineEdit(gestion_client);
        to->setObjectName("to");
        to->setGeometry(QRect(680, 560, 113, 22));
        label_10 = new QLabel(gestion_client);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(560, 600, 56, 16));
        obj = new QLineEdit(gestion_client);
        obj->setObjectName("obj");
        obj->setGeometry(QRect(680, 600, 113, 22));
        label_11 = new QLabel(gestion_client);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(560, 650, 56, 16));
        body = new QLineEdit(gestion_client);
        body->setObjectName("body");
        body->setGeometry(QRect(680, 650, 113, 22));
        envoyer = new QPushButton(gestion_client);
        envoyer->setObjectName("envoyer");
        envoyer->setGeometry(QRect(870, 620, 93, 28));
        g_c_deconnecter = new QPushButton(gestion_client);
        g_c_deconnecter->setObjectName("g_c_deconnecter");
        g_c_deconnecter->setGeometry(QRect(914, 0, 131, 23));
        g_c_menu = new QPushButton(gestion_client);
        g_c_menu->setObjectName("g_c_menu");
        g_c_menu->setGeometry(QRect(770, 0, 131, 23));
        background->raise();
        dateE->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        le_idd->raise();
        le_mail->raise();
        le_nom->raise();
        le_prenom->raise();
        le_salaire->raise();
        le_tel->raise();
        modifier->raise();
        bt_supprimer->raise();
        refresh->raise();
        ajouter->raise();
        tableViewE->raise();
        label_9->raise();
        role->raise();
        combo_ide->raise();
        lineEdit_chercher->raise();
        combo_tri->raise();
        combo_chercher->raise();
        PDF->raise();
        label_stat->raise();
        bt_desc->raise();
        bt_asc->raise();
        bt_chercher->raise();
        label_8->raise();
        to->raise();
        label_10->raise();
        obj->raise();
        label_11->raise();
        body->raise();
        envoyer->raise();
        g_c_deconnecter->raise();
        g_c_menu->raise();
        login = new QGroupBox(centralWidget);
        login->setObjectName("login");
        login->setGeometry(QRect(0, 0, 1920, 1080));
        bg = new QLabel(login);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1920, 1080));
        bg->setStyleSheet(QString::fromUtf8("background-color:red;"));
        bt_login = new QPushButton(login);
        bt_login->setObjectName("bt_login");
        bt_login->setGeometry(QRect(490, 480, 141, 51));
        login_email = new QLineEdit(login);
        login_email->setObjectName("login_email");
        login_email->setGeometry(QRect(490, 250, 301, 51));
        login_mdp = new QLineEdit(login);
        login_mdp->setObjectName("login_mdp");
        login_mdp->setGeometry(QRect(490, 390, 301, 61));
        label_12 = new QLabel(login);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(490, 180, 301, 51));
        label_12->setStyleSheet(QString::fromUtf8("color:white;"));
        label_13 = new QLabel(login);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(490, 320, 301, 51));
        label_13->setStyleSheet(QString::fromUtf8("color:white;"));
        oublier = new QPushButton(login);
        oublier->setObjectName("oublier");
        oublier->setGeometry(QRect(930, 270, 131, 51));
        label_14 = new QLabel(login);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(920, 230, 211, 16));
        label_14->setStyleSheet(QString::fromUtf8("color:white;"));
        done = new QPushButton(login);
        done->setObjectName("done");
        done->setGeometry(QRect(940, 420, 93, 28));
        code = new QLineEdit(login);
        code->setObjectName("code");
        code->setGeometry(QRect(902, 360, 181, 41));
        menu = new QGroupBox(centralWidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 1920, 1080));
        bg_menu = new QLabel(menu);
        bg_menu->setObjectName("bg_menu");
        bg_menu->setGeometry(QRect(0, 0, 1920, 1080));
        bg_menu->setStyleSheet(QString::fromUtf8("background-color:red;"));
        m_employe = new QPushButton(menu);
        m_employe->setObjectName("m_employe");
        m_employe->setGeometry(QRect(1080, 230, 251, 61));
        m_commande = new QPushButton(menu);
        m_commande->setObjectName("m_commande");
        m_commande->setGeometry(QRect(1080, 320, 251, 61));
        m_patient = new QPushButton(menu);
        m_patient->setObjectName("m_patient");
        m_patient->setGeometry(QRect(1080, 510, 251, 61));
        m_fournisseur = new QPushButton(menu);
        m_fournisseur->setObjectName("m_fournisseur");
        m_fournisseur->setGeometry(QRect(1080, 420, 251, 61));
        m_produit = new QPushButton(menu);
        m_produit->setObjectName("m_produit");
        m_produit->setGeometry(QRect(1080, 600, 251, 61));
        m_log_out = new QPushButton(menu);
        m_log_out->setObjectName("m_log_out");
        m_log_out->setGeometry(QRect(1630, 80, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        login->raise();
        menu->raise();
        gestion_client->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 2097, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        gestion_client->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "ide", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "mail", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "date d'embauche", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " salaire", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", " telephone", nullptr));
        bt_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        refresh->setText(QCoreApplication::translate("MainWindow", "refresh", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        background->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Role", nullptr));
        role->setItemText(0, QCoreApplication::translate("MainWindow", "RH", nullptr));
        role->setItemText(1, QCoreApplication::translate("MainWindow", "DEV", nullptr));
        role->setItemText(2, QCoreApplication::translate("MainWindow", "SECURITE", nullptr));

        combo_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Trier selon:", nullptr));
        combo_tri->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        combo_tri->setItemText(2, QCoreApplication::translate("MainWindow", "DATE_EMBAUCHE", nullptr));
        combo_tri->setItemText(3, QCoreApplication::translate("MainWindow", "salaire", nullptr));

        combo_chercher->setItemText(0, QCoreApplication::translate("MainWindow", "Chercher:", nullptr));
        combo_chercher->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        combo_chercher->setItemText(2, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        combo_chercher->setItemText(3, QCoreApplication::translate("MainWindow", "PRENOM", nullptr));

        PDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_stat->setText(QString());
        bt_desc->setText(QCoreApplication::translate("MainWindow", "DESC", nullptr));
        bt_asc->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        bt_chercher->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "object", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "body", nullptr));
        envoyer->setText(QCoreApplication::translate("MainWindow", "envoyer", nullptr));
        g_c_deconnecter->setText(QCoreApplication::translate("MainWindow", "DECONNECTER", nullptr));
        g_c_menu->setText(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        login->setTitle(QString());
        bg->setText(QString());
        bt_login->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        login_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "entrez votre email", nullptr));
        login_mdp->setPlaceholderText(QCoreApplication::translate("MainWindow", "entrez votre mot de passe", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "EMAIL", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        oublier->setText(QCoreApplication::translate("MainWindow", "send code", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Mot de pass oublier ?", nullptr));
        done->setText(QCoreApplication::translate("MainWindow", "confirmer", nullptr));
        code->setText(QString());
        menu->setTitle(QString());
        bg_menu->setText(QString());
        m_employe->setText(QCoreApplication::translate("MainWindow", "EMPLOYE", nullptr));
        m_commande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        m_patient->setText(QCoreApplication::translate("MainWindow", "PATIENT", nullptr));
        m_fournisseur->setText(QCoreApplication::translate("MainWindow", "FOURNISSEUR", nullptr));
        m_produit->setText(QCoreApplication::translate("MainWindow", "PRODUIT", nullptr));
        m_log_out->setText(QCoreApplication::translate("MainWindow", "LOG OUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
