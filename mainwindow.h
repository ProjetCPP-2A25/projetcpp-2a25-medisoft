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
#include <QPainter>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>



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
void on_radioButton_deetoile_clicked();
void on_radioButton_denom_clicked();
void on_radioButton_nom_clicked();
QString generateHtmlFromData(QAbstractItemModel* model);
void showMap();
void on_pushButton_showStats2_clicked();


private:
    Ui::MainWindow *ui;
    Fournisseur ftmp; // Instance temporaire pour les opérations CRUD
    QSqlQueryModel* model; // Declare a persistent model

};

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
