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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QLabel *monLOGO;
    QLabel *label_12;
    QLabel *labelTemp;
    QLabel *labelFanState;
    QGroupBox *groupBox_2;
    QPushButton *addButton;
    QPushButton *sauvegarder;
    QTableWidget *tableWidget;
    QLabel *Background;
    QPushButton *ListProduit;
    QGroupBox *Produit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineCode;
    QLineEdit *lineName;
    QLineEdit *linePrice;
    QLineEdit *lineqte;
    QLineEdit *lineType;
    QLineEdit *lineDesc;
    QDateEdit *dateEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_5;
    QPushButton *Modifier;
    QPushButton *deleteButton;
    QPushButton *addImageButton;
    QLabel *imageLabel;
    QPushButton *searchButton;
    QPushButton *statistique;
    QPushButton *exportButton;
    QComboBox *trierLine;
    QLabel *label_11;
    QPushButton *AiDoctorButton;
    QPushButton *boutonTrier;
    QLabel *label_13;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1355, 738);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 190, 1331, 471));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/LUXORAHOTEL/image/home1.jpg")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 211, 701));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:#023020;"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 100, 141, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Perpetua")});
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:black;"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 160, 141, 41));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:#0000;"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 220, 141, 41));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:#0000;"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 280, 141, 41));
        pushButton_4->setFont(font);
        pushButton_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:black;"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 340, 141, 41));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:black;"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 400, 141, 41));
        pushButton_6->setFont(font);
        pushButton_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaeaec;\n"
"color:black;"));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(30, 560, 141, 41));
        pushButton_7->setFont(font);
        pushButton_7->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:20px;\n"
"background-color:#eaf1cd;\n"
"color:black;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 470, 131, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../phar.png")));
        label_3->setScaledContents(true);
        monLOGO = new QLabel(groupBox);
        monLOGO->setObjectName("monLOGO");
        monLOGO->setGeometry(QRect(60, 480, 81, 61));
        monLOGO->setPixmap(QPixmap(QString::fromUtf8("images/LogoApp.png")));
        monLOGO->setScaledContents(true);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 0, 111, 61));
        label_12->setPixmap(QPixmap(QString::fromUtf8("LogoApp.png")));
        label_12->setScaledContents(true);
        labelTemp = new QLabel(groupBox);
        labelTemp->setObjectName("labelTemp");
        labelTemp->setGeometry(QRect(10, 10, 191, 31));
        labelTemp->setStyleSheet(QString::fromUtf8("color:white;"));
        labelFanState = new QLabel(groupBox);
        labelFanState->setObjectName("labelFanState");
        labelFanState->setGeometry(QRect(10, 50, 191, 41));
        labelFanState->setStyleSheet(QString::fromUtf8("color:white;"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(220, 0, 1101, 681));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Perpetua")});
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color:#eaeaec"));
        addButton = new QPushButton(groupBox_2);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(140, 420, 161, 41));
        addButton->setFont(font);
        addButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        sauvegarder = new QPushButton(groupBox_2);
        sauvegarder->setObjectName("sauvegarder");
        sauvegarder->setGeometry(QRect(310, 420, 161, 41));
        sauvegarder->setFont(font);
        sauvegarder->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sauvegarder->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}\n"
""));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 470, 1111, 211));
        Background = new QLabel(groupBox_2);
        Background->setObjectName("Background");
        Background->setGeometry(QRect(0, 510, 1121, 121));
        Background->setPixmap(QPixmap(QString::fromUtf8("../../../OneDrive/Images/phar.jpg")));
        Background->setScaledContents(true);
        ListProduit = new QPushButton(groupBox_2);
        ListProduit->setObjectName("ListProduit");
        ListProduit->setGeometry(QRect(0, 10, 201, 41));
        ListProduit->setFont(font);
        ListProduit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ListProduit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        Produit = new QGroupBox(groupBox_2);
        Produit->setObjectName("Produit");
        Produit->setGeometry(QRect(380, 50, 341, 351));
        Produit->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid black;              /* Bordure noire */\n"
"    border-radius: 10px;                 /* Coins arrondis */\n"
"    background-color: rgba(128, 128, 128, 0.7); /* Gris avec opacit\303\251 (70%) */\n"
"    margin-top: 10px;                    /* Espace pour le titre */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    color: black;                        /* Couleur du titre */\n"
"    subcontrol-origin: margin;           /* Position du titre par rapport \303\240 la bordure */\n"
"    subcontrol-position: top center;     /* Centrer le titre en haut */\n"
"    padding: 0 5px;                      /* Espacement autour du texte du titre */\n"
"}\n"
""));
        layoutWidget = new QWidget(Produit);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(161, 30, 171, 306));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineCode = new QLineEdit(layoutWidget);
        lineCode->setObjectName("lineCode");

        verticalLayout->addWidget(lineCode);

        lineName = new QLineEdit(layoutWidget);
        lineName->setObjectName("lineName");

        verticalLayout->addWidget(lineName);

        linePrice = new QLineEdit(layoutWidget);
        linePrice->setObjectName("linePrice");

        verticalLayout->addWidget(linePrice);

        lineqte = new QLineEdit(layoutWidget);
        lineqte->setObjectName("lineqte");

        verticalLayout->addWidget(lineqte);

        lineType = new QLineEdit(layoutWidget);
        lineType->setObjectName("lineType");

        verticalLayout->addWidget(lineType);

        lineDesc = new QLineEdit(layoutWidget);
        lineDesc->setObjectName("lineDesc");

        verticalLayout->addWidget(lineDesc);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");

        verticalLayout->addWidget(dateEdit);

        layoutWidget1 = new QWidget(Produit);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 30, 147, 301));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Perpetua")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.4); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}\n"
""));

        verticalLayout_2->addWidget(label_2);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.5); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_8);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.4); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_4);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.3); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_6);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName("label_9");
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.3); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_9);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.3); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_7);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.3); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));

        verticalLayout_2->addWidget(label_5);

        Modifier = new QPushButton(groupBox_2);
        Modifier->setObjectName("Modifier");
        Modifier->setGeometry(QRect(770, 420, 141, 41));
        Modifier->setFont(font);
        Modifier->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        deleteButton = new QPushButton(groupBox_2);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(930, 420, 141, 41));
        deleteButton->setFont(font);
        deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        addImageButton = new QPushButton(groupBox_2);
        addImageButton->setObjectName("addImageButton");
        addImageButton->setGeometry(QRect(110, 330, 121, 31));
        imageLabel = new QLabel(groupBox_2);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(40, 150, 271, 161));
        imageLabel->setAutoFillBackground(false);
        imageLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: rgba(128, 128, 128, 0.4); /* Fond gris avec 50% d'opacit\303\251 */\n"
"    color: white; /* Texte en blanc */\n"
"    border-radius: 5px; /* Coins arrondis (optionnel) */\n"
"}"));
        imageLabel->setScaledContents(true);
        searchButton = new QPushButton(groupBox_2);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(930, 320, 141, 41));
        searchButton->setFont(font);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        statistique = new QPushButton(groupBox_2);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(800, 0, 141, 41));
        statistique->setFont(font);
        statistique->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statistique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        exportButton = new QPushButton(groupBox_2);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(950, 0, 141, 41));
        exportButton->setFont(font);
        exportButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportButton->setMouseTracking(true);
        exportButton->setTabletTracking(true);
        exportButton->setAcceptDrops(true);
        exportButton->setAutoFillBackground(false);
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        exportButton->setCheckable(true);
        exportButton->setChecked(true);
        exportButton->setAutoRepeat(true);
        exportButton->setAutoExclusive(true);
        exportButton->setAutoDefault(true);
        exportButton->setFlat(true);
        trierLine = new QComboBox(groupBox_2);
        trierLine->addItem(QString());
        trierLine->addItem(QString());
        trierLine->addItem(QString());
        trierLine->addItem(QString());
        trierLine->setObjectName("trierLine");
        trierLine->setGeometry(QRect(750, 350, 131, 28));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(750, 320, 81, 21));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color:#030C54"));
        AiDoctorButton = new QPushButton(groupBox_2);
        AiDoctorButton->setObjectName("AiDoctorButton");
        AiDoctorButton->setGeometry(QRect(10, 420, 131, 41));
        AiDoctorButton->setFont(font);
        AiDoctorButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        AiDoctorButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        boutonTrier = new QPushButton(groupBox_2);
        boutonTrier->setObjectName("boutonTrier");
        boutonTrier->setGeometry(QRect(930, 370, 141, 41));
        boutonTrier->setFont(font);
        boutonTrier->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        boutonTrier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 20px;              /* Coins arrondis */\n"
"    background-color: rgba(232, 187, 166, 0.8); /* Couleur avec opacit\303\251 \303\240 50% */\n"
"    color: white;                     /* Texte en blanc */\n"
"}"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(-10, 0, 1101, 681));
        label_13->setPixmap(QPixmap(QString::fromUtf8("phar.jpg")));
        label_13->setScaledContents(true);
        label_13->raise();
        Background->raise();
        addButton->raise();
        sauvegarder->raise();
        tableWidget->raise();
        ListProduit->raise();
        Produit->raise();
        Modifier->raise();
        deleteButton->raise();
        addImageButton->raise();
        imageLabel->raise();
        searchButton->raise();
        statistique->raise();
        exportButton->raise();
        trierLine->raise();
        label_11->raise();
        AiDoctorButton->raise();
        boutonTrier->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1355, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        exportButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Employ\303\251", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Produit", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Commandes", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "D\303\251connection", nullptr));
        label_3->setText(QString());
        monLOGO->setText(QString());
        label_12->setText(QString());
        labelTemp->setText(QString());
        labelFanState->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "PRODUIT : ", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        sauvegarder->setText(QCoreApplication::translate("MainWindow", "Sauvegader", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Date d'expiration", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        Background->setText(QString());
        ListProduit->setText(QCoreApplication::translate("MainWindow", "Liste Des Produits ", nullptr));
        Produit->setTitle(QCoreApplication::translate("MainWindow", "Produit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Code de produit", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nom de produit", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Date d'expiration", nullptr));
        Modifier->setText(QCoreApplication::translate("MainWindow", "Modifer", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        addImageButton->setText(QCoreApplication::translate("MainWindow", "Ajouter Images", nullptr));
        imageLabel->setText(QString());
        searchButton->setText(QCoreApplication::translate("MainWindow", "chercher", nullptr));
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        trierLine->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner", nullptr));
        trierLine->setItemText(1, QCoreApplication::translate("MainWindow", "Code", nullptr));
        trierLine->setItemText(2, QCoreApplication::translate("MainWindow", "Prix", nullptr));
        trierLine->setItemText(3, QCoreApplication::translate("MainWindow", "Date", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        AiDoctorButton->setText(QCoreApplication::translate("MainWindow", "AiDoctor", nullptr));
        boutonTrier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        label_13->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
