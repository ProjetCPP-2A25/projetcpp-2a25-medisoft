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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QPushButton *afficher;
    QPushButton *ajouter;
    QLineEdit *lineEdit_11;
    QLineEdit *quant;
    QLabel *label_6;
    QLineEdit *idf;
    QLineEdit *recherche;
    QLineEdit *prix;
    QLineEdit *lineEdit_13;
    QPushButton *logout;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLineEdit *lineEdit_14;
    QLabel *label_10;
    QPushButton *filtrer;
    QLabel *musique;
    QLabel *label_4;
    QLineEdit *lineEdit_9;
    QTextBrowser *textBrowser;
    QPushButton *statButton;
    QPushButton *pdf;
    QLineEdit *idc;
    QPushButton *pushButton_10;
    QLabel *label_7;
    QLabel *label_12;
    QDateEdit *date;
    QTableView *tableView;
    QPushButton *update;
    QPushButton *supprimer;
    QLabel *qrCodeLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1303, 766);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 500, 21, 21));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../images/393883823_3566576113658158_9212498078691773248_n.png")));
        label_2->setScaledContents(true);
        afficher = new QPushButton(centralWidget);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(640, 520, 161, 41));
        afficher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        ajouter = new QPushButton(centralWidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(270, 520, 161, 41));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(centralWidget);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(20, 280, 151, 41));
        lineEdit_11->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"padding: 5px;\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"   \n"
"    border-radius: 5px;\n"
"  \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        quant = new QLineEdit(centralWidget);
        quant->setObjectName("quant");
        quant->setGeometry(QRect(180, 200, 161, 41));
        quant->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    \n"
"	font: 700 9pt \"Segoe UI\";\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(800, 100, 31, 21));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/426963771_940106313792500_9064911174535547542_n.png")));
        label_6->setScaledContents(true);
        idf = new QLineEdit(centralWidget);
        idf->setObjectName("idf");
        idf->setGeometry(QRect(180, 420, 161, 41));
        idf->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    \n"
"	font: 700 9pt \"Segoe UI\";\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        recherche = new QLineEdit(centralWidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(530, 90, 251, 41));
        recherche->setStyleSheet(QString::fromUtf8("  background-color: rgba(255, 255, 255, 0.5); \n"
"padding: 5px;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"color: #fff;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    font-size: 14px;\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        recherche->setCursorPosition(0);
        prix = new QLineEdit(centralWidget);
        prix->setObjectName("prix");
        prix->setGeometry(QRect(180, 340, 161, 41));
        prix->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    \n"
"	font: 700 9pt \"Segoe UI\";\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        lineEdit_13 = new QLineEdit(centralWidget);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(30, 420, 121, 31));
        lineEdit_13->setStyleSheet(QString::fromUtf8(" background-color: transparent; \n"
"padding: 5px;\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"   \n"
"    border-radius: 5px;\n"
"   \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        logout = new QPushButton(centralWidget);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(20, 580, 141, 51));
        logout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(20, 200, 131, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 11pt \"Segoe UI\";\n"
"background-color: transparent;\n"
"padding: 5px;\n"
"    \n"
"    border-radius: 5px;\n"
""));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 540, 56, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/423903620_1378110712823805_3453213355354231890_n.png")));
        label_5->setScaledContents(true);
        lineEdit_14 = new QLineEdit(centralWidget);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(20, 350, 121, 31));
        lineEdit_14->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"padding: 5px;\n"
"font: 75 9pt \"MS Shell Dlg 2\";\n"
"    border-radius: 5px;\n"
" \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(540, 100, 31, 21));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pk.png")));
        label_10->setScaledContents(true);
        filtrer = new QPushButton(centralWidget);
        filtrer->setObjectName("filtrer");
        filtrer->setGeometry(QRect(790, 90, 141, 41));
        filtrer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        filtrer->setFlat(false);
        musique = new QLabel(centralWidget);
        musique->setObjectName("musique");
        musique->setGeometry(QRect(1210, 580, 61, 41));
        musique->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0.5); \n"
"\n"
"padding: 5px;\n"
"\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 5px;\n"
"    font-size: 14px;\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
""));
        musique->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/360_F_301439209_vpF837oCGM1lp0cnC7stzCBn3th0dQ6O.jpg")));
        musique->setScaledContents(true);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(970, 100, 41, 31));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pdf.png")));
        label_4->setScaledContents(true);
        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(30, 130, 131, 41));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 20pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"padding: 5px;\n"
"   \n"
"    border-radius: 5px;\n"
"   \n"
"font: 700 11pt \"Segoe UI\";"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 120, 331, 371));
        textBrowser->setStyleSheet(QString::fromUtf8(""));
        statButton = new QPushButton(centralWidget);
        statButton->setObjectName("statButton");
        statButton->setGeometry(QRect(1050, 520, 171, 41));
        statButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        pdf = new QPushButton(centralWidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(960, 90, 141, 51));
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        idc = new QLineEdit(centralWidget);
        idc->setObjectName("idc");
        idc->setGeometry(QRect(180, 130, 161, 41));
        idc->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    \n"
"	font: 700 9pt \"Segoe UI\";\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(10, 40, 371, 61));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 700 16pt \"Segoe UI\";\n"
"    border: none;\n"
""));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(770, 530, 31, 21));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/426721553_3308243649479444_9142994978690348616_n.png")));
        label_7->setScaledContents(true);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(70, 120, 31, 21));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/426833070_362133560103314_8738250760355801066_n.png")));
        label_12->setScaledContents(true);
        date = new QDateEdit(centralWidget);
        date->setObjectName("date");
        date->setGeometry(QRect(180, 280, 161, 41));
        date->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 5px;\n"
"    border: 2px solid #43aff7;\n"
"    border-radius: 15px;\n"
"    \n"
"	font: 700 9pt \"Segoe UI\";\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #2ecc71; /* Couleur de la bordure lorsqu'il est activ\303\251 */\n"
"}\n"
""));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(400, 150, 521, 351));
        tableView->setStyleSheet(QString::fromUtf8(""));
        update = new QPushButton(centralWidget);
        update->setObjectName("update");
        update->setGeometry(QRect(820, 520, 161, 41));
        update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
""));
        supprimer = new QPushButton(centralWidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(460, 520, 158, 41));
        supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
"    border: 0px solid rgba(255, 255, 255, 0.3);\n"
"  border-radius: 20px;\n"
"  padding: 8px 16px;\n"
"  color: #fff;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton:hover {\n"
"\n"
"background-color: rgba(255, 255, 255, 0.5);\n"
"}\n"
"\n"
""));
        qrCodeLabel = new QLabel(centralWidget);
        qrCodeLabel->setObjectName("qrCodeLabel");
        qrCodeLabel->setGeometry(QRect(970, 170, 291, 281));
        qrCodeLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 148, 148);"));
        MainWindow->setCentralWidget(centralWidget);
        afficher->raise();
        ajouter->raise();
        recherche->raise();
        logout->raise();
        label_5->raise();
        label_10->raise();
        musique->raise();
        statButton->raise();
        pdf->raise();
        pushButton_10->raise();
        textBrowser->raise();
        lineEdit_14->raise();
        lineEdit_11->raise();
        lineEdit_7->raise();
        lineEdit_9->raise();
        lineEdit_13->raise();
        idc->raise();
        quant->raise();
        prix->raise();
        idf->raise();
        label_7->raise();
        label_12->raise();
        filtrer->raise();
        label_6->raise();
        label_2->raise();
        label_4->raise();
        date->raise();
        tableView->raise();
        update->raise();
        supprimer->raise();
        qrCodeLabel->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1303, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        filtrer->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_2->setText(QString());
        afficher->setText(QCoreApplication::translate("MainWindow", "AFFICHER", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "DATE:", nullptr));
        quant->setText(QString());
        label_6->setText(QString());
        recherche->setText(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "        recherche :", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindow", "IDF:", nullptr));
        logout->setText(QCoreApplication::translate("MainWindow", "LOGOUT", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "QUANTITE:", nullptr));
        label_5->setText(QString());
        lineEdit_14->setText(QCoreApplication::translate("MainWindow", "PRIX_PR:", nullptr));
        label_10->setText(QString());
        filtrer->setText(QCoreApplication::translate("MainWindow", "TRIE", nullptr));
        musique->setText(QString());
        label_4->setText(QString());
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "IDC:", nullptr));
        statButton->setText(QCoreApplication::translate("MainWindow", "STAT", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "       PDF", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Gestions des Commandes :", nullptr));
        label_7->setText(QString());
        label_12->setText(QString());
        update->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        qrCodeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
