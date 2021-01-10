#ifndef BULLETS_H
#define BULLETS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "enemigos.h"
#include "colisiones.h"

class bullets : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QObject *parent = nullptr);
    ~bullets();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    int velocidad = 20, distancia_max = 400;
    float filas = 0, columnas = 0, total_columnas;

private:
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;

signals:

public slots:
    void Actualizacion();

};

#endif // BULLETS_H
