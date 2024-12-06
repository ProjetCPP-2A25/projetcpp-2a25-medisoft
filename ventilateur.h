#ifndef VENTILATEUR_H
#define VENTILATEUR_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class Ventilateur : public QObject
{
    Q_OBJECT

public:
    Ventilateur();
    ~Ventilateur();

    bool isVentilateurOn() const;
    void checkVentilateurStatus();

signals:
    void ventilateurOn();
    void ventilateurOff();

private:
    bool ventilateurStatus; // True si ventilateur ON, false si OFF
};

#endif // VENTILATEUR_H
