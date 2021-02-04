#ifndef BULLETS_H
#define BULLETS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "enemigos.h"
#include "jefe.h"

class bullets : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    //Constructor de balas que afectan a enemigos
    explicit bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<enemigos *> *enemy, int *puntos_,QObject *parent = nullptr);
    //Constructor sobrecargado de balas que afectan a jefes
    explicit bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<jefe *> *enemy, QObject *parent = nullptr);
    ~bullets();

    //funciones para el cambio de imagen del objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Funciones de movimiento de las balas
    void up();
    void down();
    void left();
    void right();

    //velocidad define cada cuantos pixeles se desplaza el objeto y la distacia_max el total maximo de pixeles por desplazarse
    float velocidad = 20, distancia_max = 400;
    //variables para el funcionamiento del cambio de imagen
    float filas = 0, columnas = 0, total_columnas;
    //diagonal define si el disparo es diagonal o no y tipo_enemy define si la colision del disparo es con un enemigo normal o con un jefe
    bool diagonal = false, tipo_enemy = true;
    //puntero hacia la direccion donde se establece los puntos que el jugador hace cada vez que mata un enemigo
    int *puntos_jugador;

private:
    QVector<jefe *> *Jefe;
    QVector<enemigos *> *Enemigos;
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;

signals:

public slots:
    //funcion para el constante movimiento, colision y cambio de imagen del objeto
    void Actualizacion();

};

#endif // BULLETS_H
