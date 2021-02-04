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
    //Constructor de balas que afectan a los jugadores
    explicit bullets_enemy(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<personaje_principal *> personajes_, QObject *parent = nullptr);
    ~bullets_enemy();

    //funciones para el cambio de imagen del objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Funciones de movimiento de las balas
    void up();
    void down();
    void left();
    void right();

    //velocidad define cada cuantos pixeles se desplaza el objeto
    float velocidad = 3;
    //variables para el funcionamiento del cambio de imagen
    float filas = 0, columnas = 0, total_columnas;

private:
    QVector<personaje_principal *> personajes;
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;
    //variables para determinar la posicion final del objeto durante su desplazamiento
    float pos_final_x , pos_final_y;

signals:

public slots:
    //funcion para el constante movimiento, colision y cambio de imagen del objeto
    void Actualizacion();

};

#endif // BULLETS_ENEMY_H
