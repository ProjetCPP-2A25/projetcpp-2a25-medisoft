// temperaturetrend.h
#ifndef TEMPERATURETREND_H
#define TEMPERATURETREND_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPainterPath>

class TemperatureTrend : public QWidget {
    Q_OBJECT

public:
    explicit TemperatureTrend(QWidget *parent = nullptr);
    void addTemperature(float temp);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<float> temperatures;
    static const int MAX_POINTS = 20;  // Store last 20 readings
    float minTemp = 0;
    float maxTemp = 50;
};

#endif // TEMPERATURETREND_H
