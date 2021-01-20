#ifndef BULLETS_ENEMY_H
#define BULLETS_ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include <math.h>
#include "personaje_principal.h"

class bullets_enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bullets_enemy(QString direccion_img, float ancho_, float alto_, float total_columnas_, personaje_principal *personaje_, QObject *parent = nullptr);
    ~bullets_enemy();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    float velocidad = 3;
    float filas = 0, columnas = 0, total_columnas;

private:
    personaje_principal *personaje;
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;
    float pos_final_x , pos_final_y;

signals:

public slots:
    void Actualizacion();

};

#endif // BULLETS_ENEMY_H
