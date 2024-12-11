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
    QPushButton *pb_notfier;
    QPushButton *btn_sendEmail;
    QLabel *label_time;
    QWidget *widget_statistiques;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(918, 639);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        Ajouter = new QPushButton(centralWidget);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(50, 450, 91, 31));
        Ajouter->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Segoe UI\";\n"
"font: 700 11pt \"Segoe UI\";\n"
"\n"
""));
        lineEdit_IDP = new QLineEdit(centralWidget);
        lineEdit_IDP->setObjectName("lineEdit_IDP");
        lineEdit_IDP->setGeometry(QRect(150, 150, 131, 31));
        lineEdit_IDP->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_NOM = new QLineEdit(centralWidget);
        lineEdit_NOM->setObjectName("lineEdit_NOM");
        lineEdit_NOM->setGeometry(QRect(150, 190, 131, 31));
        lineEdit_NOM->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_PRENOM = new QLineEdit(centralWidget);
        lineEdit_PRENOM->setObjectName("lineEdit_PRENOM");
        lineEdit_PRENOM->setGeometry(QRect(150, 230, 131, 31));
        lineEdit_PRENOM->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_MAIL = new QLineEdit(centralWidget);
        lineEdit_MAIL->setObjectName("lineEdit_MAIL");
        lineEdit_MAIL->setGeometry(QRect(150, 270, 131, 31));
        lineEdit_MAIL->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_AGE = new QLineEdit(centralWidget);
        lineEdit_AGE->setObjectName("lineEdit_AGE");
        lineEdit_AGE->setGeometry(QRect(150, 350, 131, 31));
        lineEdit_AGE->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_TELEPHONE = new QLineEdit(centralWidget);
        lineEdit_TELEPHONE->setObjectName("lineEdit_TELEPHONE");
        lineEdit_TELEPHONE->setGeometry(QRect(150, 390, 131, 31));
        lineEdit_TELEPHONE->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        Afficher = new QPushButton(centralWidget);
        Afficher->setObjectName("Afficher");
        Afficher->setGeometry(QRect(190, 450, 91, 31));
        Afficher->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 11pt \"Segoe UI\";"));
        Supprimer = new QPushButton(centralWidget);
        Supprimer->setObjectName("Supprimer");
        Supprimer->setGeometry(QRect(530, 110, 111, 31));
        Supprimer->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        IDP = new QLabel(centralWidget);
        IDP->setObjectName("IDP");
        IDP->setGeometry(QRect(50, 150, 51, 31));
        IDP->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);\n"
"font: 11pt \"Segoe UI\";\n"
""));
        NOM = new QLabel(centralWidget);
        NOM->setObjectName("NOM");
        NOM->setGeometry(QRect(50, 200, 61, 21));
        NOM->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        PRENOM = new QLabel(centralWidget);
        PRENOM->setObjectName("PRENOM");
        PRENOM->setGeometry(QRect(50, 230, 81, 31));
        PRENOM->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        MAIL = new QLabel(centralWidget);
        MAIL->setObjectName("MAIL");
        MAIL->setGeometry(QRect(50, 280, 49, 16));
        MAIL->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        GENRE = new QLabel(centralWidget);
        GENRE->setObjectName("GENRE");
        GENRE->setGeometry(QRect(50, 320, 49, 16));
        GENRE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        AGE = new QLabel(centralWidget);
        AGE->setObjectName("AGE");
        AGE->setGeometry(QRect(50, 350, 61, 41));
        AGE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        TELEPHONE = new QLabel(centralWidget);
        TELEPHONE->setObjectName("TELEPHONE");
        TELEPHONE->setGeometry(QRect(50, 400, 91, 21));
        TELEPHONE->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(207, 207, 207);"));
        ajout_pat = new QLabel(centralWidget);
        ajout_pat->setObjectName("ajout_pat");
        ajout_pat->setGeometry(QRect(60, 90, 241, 61));
        ajout_pat->setStyleSheet(QString::fromUtf8("color:   rgb(179, 255, 165);\n"
"font: 700 14pt \"Segoe UI\";\n"
"background-color: rgb(207, 207, 207);"));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 271, 461));
        label->setStyleSheet(QString::fromUtf8("color:  rgb(179, 255, 165);\n"
"background-color: rgb(207, 207, 207);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 80, 391, 451));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(510, 250, 371, 271));
        tableView->setStyleSheet(QString::fromUtf8("font: 700 italic 9pt \"Segoe UI\";"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 310, 131, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(820, 0, 91, 101));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/medisoftt.png);"));
        Rechercher = new QPushButton(centralWidget);
        Rechercher->setObjectName("Rechercher");
        Rechercher->setGeometry(QRect(530, 180, 111, 31));
        Rechercher->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        comboBox_sort = new QComboBox(centralWidget);
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->setObjectName("comboBox_sort");
        comboBox_sort->setGeometry(QRect(770, 140, 69, 22));
        comboBox_sort->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));
        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName("sortButton");
        sortButton->setGeometry(QRect(750, 110, 111, 31));
        sortButton->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        exporter = new QPushButton(centralWidget);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(840, 210, 41, 41));
        exporter->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";\n"
"border-image: url(:/pdff/pdf.PNG);"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(550, 210, 71, 22));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(550, 140, 71, 22));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);"));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(750, 170, 111, 31));
        saveButton->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));
        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(40, 500, 31, 31));
        refreshButton->setStyleSheet(QString::fromUtf8("background-image: url(:/refr/refreshhh.PNG);\n"
"border-image: url(:/refr/refreshhh.PNG);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-20, 0, 981, 581));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/ress/pharmacie.PNG);"));
        btn_statistiques = new QPushButton(centralWidget);
        btn_statistiques->setObjectName("btn_statistiques");
        btn_statistiques->setGeometry(QRect(780, 540, 31, 31));
        btn_statistiques->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";\n"
"border-image: url(:/statt/stat.PNG);"));
        pb_notfier = new QPushButton(centralWidget);
        pb_notfier->setObjectName("pb_notfier");
        pb_notfier->setGeometry(QRect(820, 540, 31, 31));
        pb_notfier->setStyleSheet(QString::fromUtf8("border-image: url(:/notiff/notif.PNG);"));
        btn_sendEmail = new QPushButton(centralWidget);
        btn_sendEmail->setObjectName("btn_sendEmail");
        btn_sendEmail->setGeometry(QRect(860, 30, 20, 20));
        btn_sendEmail->setStyleSheet(QString::fromUtf8("border-image: url(:/maiiil/Mail - Copie.PNG);"));
        label_time = new QLabel(centralWidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(660, 70, 141, 61));
        label_time->setStyleSheet(QString::fromUtf8("background-color: rgb(207, 207, 207);\n"
"font: 700 italic 9pt \"Segoe UI\";"));
        widget_statistiques = new QWidget(centralWidget);
        widget_statistiques->setObjectName("widget_statistiques");
        widget_statistiques->setGeometry(QRect(510, 250, 351, 281));
        widget_statistiques->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralWidget);
        label_3->raise();
        label->raise();
        pb_notfier->raise();
        btn_sendEmail->raise();
        label_2->raise();
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
        label_time->raise();
        widget_statistiques->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 918, 22));
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
        TELEPHONE->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Telephone</span></p></body></html>", nullptr));
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
        exporter->setText(QString());
        saveButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        refreshButton->setText(QString());
        label_3->setText(QString());
        btn_statistiques->setText(QString());
        pb_notfier->setText(QString());
        btn_sendEmail->setText(QString());
        label_time->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
