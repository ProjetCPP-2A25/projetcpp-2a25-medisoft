// temperaturetrend.cpp
#include "temperaturetrend.h"
#include <QPainter>
#include <QPainterPath>

TemperatureTrend::TemperatureTrend(QWidget *parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(200, 100);
}

void TemperatureTrend::addTemperature(float temp) {
    temperatures.append(temp);
    if (temperatures.size() > MAX_POINTS) {
        temperatures.removeFirst();
    }
    update();  // Trigger repaint
}

void TemperatureTrend::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw background
    painter.fillRect(rect(), Qt::white);

    if (temperatures.isEmpty()) return;

    // Calculate scaling
    int w = width();
    int h = height();
    int padding = 20;

    // Draw axis
    painter.setPen(Qt::black);
    painter.drawLine(padding, h-padding, w-padding, h-padding);  // X axis
    painter.drawLine(padding, padding, padding, h-padding);      // Y axis

    // Plot points
    QVector<QPointF> points;

    for (int i = 0; i < temperatures.size(); ++i) {
        float x = padding + (i * (w - 2*padding) / (MAX_POINTS-1));
        float y = h - padding - ((temperatures[i] - minTemp) * (h - 2*padding) / (maxTemp - minTemp));
        points.append(QPointF(x, y));
    }

    // Draw line graph
    painter.setPen(QPen(Qt::blue, 2));
    for (int i = 1; i < points.size(); ++i) {
        painter.drawLine(points[i-1], points[i]);
    }

    // Draw points
    painter.setPen(QPen(Qt::red, 4));
    for (const QPointF& point : points) {
        painter.drawPoint(point);
    }

    // Draw temperature scale
    painter.setPen(Qt::black);
    painter.drawText(5, padding, QString::number(maxTemp));
    painter.drawText(5, h-padding, QString::number(minTemp));
}
