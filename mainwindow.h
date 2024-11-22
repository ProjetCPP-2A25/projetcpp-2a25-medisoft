#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"
#include <QMessageBox>
#include <QDebug>
//#include <QWebEngineView>
#include <QDesktopServices>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QQuickWidget>
#include <QQmlContext>




#include <QUrl>
#include <QPdfWriter>

//QT_CHARTS_USE_NAMESPACE

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
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_actualiser_clicked();
    void on_pushButton_showStats_clicked();
    void on_pushButton_generatePdf_clicked();
void on_tableView_clicked(const QModelIndex &index);
void on_lineEdit_search_textChanged(const QString &text);
void on_radioButton_etoile_clicked();
void on_radioButton_nom_clicked();
QString generateHtmlFromData(QAbstractItemModel* model);
void showMap();
void on_pushButton_showStats2_clicked();


private:
    Ui::MainWindow *ui;
    Fournisseur ftmp; // Instance temporaire pour les opérations CRUD
    QSqlQueryModel* model; // Declare a persistent model

};

#endif // MAINWINDOW_H
