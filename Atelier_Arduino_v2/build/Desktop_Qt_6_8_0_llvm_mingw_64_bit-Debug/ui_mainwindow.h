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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *sendCodeButton;
    QLabel *label_3;
    QLabel *statusLabel;
    QPushButton *openServoButton;
    QLineEdit *codeInput;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(596, 324);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 61, 16));
        sendCodeButton = new QPushButton(centralWidget);
        sendCodeButton->setObjectName("sendCodeButton");
        sendCodeButton->setGeometry(QRect(80, 180, 181, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 90, 47, 13));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(320, 30, 241, 111));
        openServoButton = new QPushButton(centralWidget);
        openServoButton->setObjectName("openServoButton");
        openServoButton->setGeometry(QRect(320, 180, 181, 31));
        codeInput = new QLineEdit(centralWidget);
        codeInput->setObjectName("codeInput");
        codeInput->setGeometry(QRect(100, 40, 151, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 596, 25));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Le Code:", nullptr));
        sendCodeButton->setText(QCoreApplication::translate("MainWindow", "Send Code ", nullptr));
        label_3->setText(QString());
        statusLabel->setText(QString());
        openServoButton->setText(QCoreApplication::translate("MainWindow", "Open La porte ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
