/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "patient.h"


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_Ajouter_clicked();
    void on_Supprimer_clicked();
    void on_Afficher_clicked();
    void on_Modifier_clicked();
    void on_Rechercher_clicked();
    //void on_btn_statistiques_clicked();
    void on_exporter_clicked();
    void on_sortButton_clicked();
private:
    Ui::MainWindow *ui;
    Patient pat;
};

#endif // MAINWINDOW_H
*/

#define MAINWINDOW_H  // Si non, le définit

#include <QMainWindow>
#include <QSqlTableModel>
#include "patient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_Ajouter_clicked();
    void on_Supprimer_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_Afficher_clicked();
    void on_Modifier_clicked();
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
private:
    Ui::MainWindow *ui;
    Patient pat;
    QModelIndex lastClickedIndex;  // Stocker l'index de la dernière ligne cliquée
    void showModifyForm(int IDP);
};

