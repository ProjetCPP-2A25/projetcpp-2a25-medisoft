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
    QPushButton *Ajouter;
    QLineEdit *lineEdit_IDP;
    QLineEdit *lineEdit_NOM;
    QLineEdit *lineEdit_PRENOM;
    QLineEdit *lineEdit_MAIL;
    QLineEdit *lineEdit_AGE;
    QLineEdit *lineEdit_TELEPHONE;
    QPushButton *Afficher;
    QPushButton *Supprimer;
    QLabel *IDP;
    QLabel *NOM;
    QLabel *PRENOM;
    QLabel *MAIL;
    QLabel *GENRE;
    QLabel *AGE;
    QLabel *TELEPHONE;
    QLabel *ajout_pat;
    QLabel *label;
    QLabel *label_2;
    QTableView *tableView;
    QComboBox *comboBox;
    QLabel *label_4;
    QPushButton *Rechercher;
    QComboBox *comboBox_sort;
    QPushButton *sortButton;
    QPushButton *exporter;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *saveButton;
    QPushButton *refreshButton;
    QLabel *label_3;
    QPushButton *btn_statistiques;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(955, 628);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        Ajouter = new QPushButton(centralWidget);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(50, 400, 91, 31));
        Ajouter->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Segoe UI\";\n"
"font: 700 11pt \"Segoe UI\";\n"
"\n"
""));
        lineEdit_IDP = new QLineEdit(centralWidget);
        lineEdit_IDP->setObjectName("lineEdit_IDP");
        lineEdit_IDP->setGeometry(QRect(150, 110, 131, 31));
        lineEdit_IDP->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_NOM = new QLineEdit(centralWidget);
        lineEdit_NOM->setObjectName("lineEdit_NOM");
        lineEdit_NOM->setGeometry(QRect(150, 150, 131, 31));
        lineEdit_NOM->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_PRENOM = new QLineEdit(centralWidget);
        lineEdit_PRENOM->setObjectName("lineEdit_PRENOM");
        lineEdit_PRENOM->setGeometry(QRect(150, 190, 131, 31));
        lineEdit_PRENOM->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_MAIL = new QLineEdit(centralWidget);
        lineEdit_MAIL->setObjectName("lineEdit_MAIL");
        lineEdit_MAIL->setGeometry(QRect(150, 230, 131, 31));
        lineEdit_MAIL->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_AGE = new QLineEdit(centralWidget);
        lineEdit_AGE->setObjectName("lineEdit_AGE");
        lineEdit_AGE->setGeometry(QRect(150, 310, 131, 31));
        lineEdit_AGE->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_TELEPHONE = new QLineEdit(centralWidget);
        lineEdit_TELEPHONE->setObjectName("lineEdit_TELEPHONE");
        lineEdit_TELEPHONE->setGeometry(QRect(150, 350, 131, 31));
        lineEdit_TELEPHONE->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        Afficher = new QPushButton(centralWidget);
        Afficher->setObjectName("Afficher");
        Afficher->setGeometry(QRect(180, 400, 91, 31));
        Afficher->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 11pt \"Segoe UI\";"));
        Supprimer = new QPushButton(centralWidget);
        Supprimer->setObjectName("Supprimer");
        Supprimer->setGeometry(QRect(530, 70, 111, 31));
        Supprimer->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        IDP = new QLabel(centralWidget);
        IDP->setObjectName("IDP");
        IDP->setGeometry(QRect(60, 110, 51, 31));
        IDP->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);\n"
"font: 11pt \"Segoe UI\";\n"
""));
        NOM = new QLabel(centralWidget);
        NOM->setObjectName("NOM");
        NOM->setGeometry(QRect(60, 160, 61, 21));
        NOM->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        PRENOM = new QLabel(centralWidget);
        PRENOM->setObjectName("PRENOM");
        PRENOM->setGeometry(QRect(60, 190, 81, 31));
        PRENOM->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        MAIL = new QLabel(centralWidget);
        MAIL->setObjectName("MAIL");
        MAIL->setGeometry(QRect(60, 240, 49, 16));
        MAIL->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        GENRE = new QLabel(centralWidget);
        GENRE->setObjectName("GENRE");
        GENRE->setGeometry(QRect(60, 280, 49, 16));
        GENRE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        AGE = new QLabel(centralWidget);
        AGE->setObjectName("AGE");
        AGE->setGeometry(QRect(60, 310, 61, 41));
        AGE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        TELEPHONE = new QLabel(centralWidget);
        TELEPHONE->setObjectName("TELEPHONE");
        TELEPHONE->setGeometry(QRect(60, 360, 41, 21));
        TELEPHONE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        ajout_pat = new QLabel(centralWidget);
        ajout_pat->setObjectName("ajout_pat");
        ajout_pat->setGeometry(QRect(60, 40, 241, 61));
        ajout_pat->setStyleSheet(QString::fromUtf8("color:   rgb(179, 255, 165);\n"
"font: 700 14pt \"Segoe UI\";\n"
"background-color: rgb(207, 207, 207);"));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 271, 461));
        label->setStyleSheet(QString::fromUtf8("color:  rgb(179, 255, 165);\n"
"background-color: rgb(207, 207, 207);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 20, 431, 461));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(510, 190, 411, 261));
        tableView->setStyleSheet(QString::fromUtf8(""));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 270, 131, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(850, 480, 101, 111));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/medisoftt.png);"));
        Rechercher = new QPushButton(centralWidget);
        Rechercher->setObjectName("Rechercher");
        Rechercher->setGeometry(QRect(530, 130, 111, 31));
        Rechercher->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        comboBox_sort = new QComboBox(centralWidget);
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->setObjectName("comboBox_sort");
        comboBox_sort->setGeometry(QRect(810, 60, 69, 22));
        comboBox_sort->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));
        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName("sortButton");
        sortButton->setGeometry(QRect(790, 30, 111, 31));
        sortButton->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        exporter = new QPushButton(centralWidget);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(790, 90, 111, 31));
        exporter->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(550, 160, 71, 22));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(550, 100, 71, 22));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(530, 30, 111, 31));
        saveButton->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(40, 440, 31, 31));
        refreshButton->setStyleSheet(QString::fromUtf8("background-image: url(:/refr/refreshhh.PNG);\n"
"border-image: url(:/refr/refreshhh.PNG);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 961, 561));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/ress/pharmacie.PNG);"));
        btn_statistiques = new QPushButton(centralWidget);
        btn_statistiques->setObjectName("btn_statistiques");
        btn_statistiques->setGeometry(QRect(810, 170, 111, 21));
        MainWindow->setCentralWidget(centralWidget);
        label_3->raise();
        label_2->raise();
        label->raise();
        Ajouter->raise();
        lineEdit_IDP->raise();
        lineEdit_NOM->raise();
        lineEdit_PRENOM->raise();
        lineEdit_MAIL->raise();
        lineEdit_AGE->raise();
        lineEdit_TELEPHONE->raise();
        Afficher->raise();
        Supprimer->raise();
        IDP->raise();
        NOM->raise();
        PRENOM->raise();
        MAIL->raise();
        GENRE->raise();
        AGE->raise();
        TELEPHONE->raise();
        ajout_pat->raise();
        tableView->raise();
        comboBox->raise();
        label_4->raise();
        Rechercher->raise();
        comboBox_sort->raise();
        sortButton->raise();
        exporter->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        saveButton->raise();
        refreshButton->raise();
        btn_statistiques->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 955, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        MainWindow->insertToolBarBreak(toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        lineEdit_IDP->setText(QString());
        Afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        Supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        IDP->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">IDP</span></p></body></html>", nullptr));
        NOM->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Nom</span></p></body></html>", nullptr));
        PRENOM->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Prenom</span></p></body></html>", nullptr));
        MAIL->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Mail</span></p></body></html>", nullptr));
        GENRE->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Genre</span></p></body></html>", nullptr));
        AGE->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Age</span></p></body></html>", nullptr));
        TELEPHONE->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Tel</span></p></body></html>", nullptr));
        ajout_pat->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; color:#ffffff; vertical-align:super;\">AJOUTER PATIENTS</span></p></body></html>", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "homme", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "femme", nullptr));

        label_4->setText(QString());
#if QT_CONFIG(tooltip)
        Rechercher->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Rechercher</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Rechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        comboBox_sort->setItemText(0, QCoreApplication::translate("MainWindow", "MAIL", nullptr));
        comboBox_sort->setItemText(1, QCoreApplication::translate("MainWindow", "AGE", nullptr));

        sortButton->setText(QCoreApplication::translate("MainWindow", "TRIER SELON :", nullptr));
        exporter->setText(QCoreApplication::translate("MainWindow", "exporter-pdf", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        refreshButton->setText(QString());
        label_3->setText(QString());
        btn_statistiques->setText(QCoreApplication::translate("MainWindow", "stat", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
