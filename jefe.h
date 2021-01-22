#ifndef JEFE_H
#define JEFE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <math.h>
#include <QDebug>
#include "powerboss.h"
#include <stdlib.h>

class jefe :  public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    float vida;
    float velocidad = 25,velocidad3 = 10;
    float ayudantepos,posiniciox,posinicioy;
    float contador = 0, posxskill,posyskill;
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;



    float tiempo = 0 ,tiempo2 = 0;
public:

    float playerx = 1400,playery = 400;
    explicit jefe(QString direccion_img, int movement_, float ancho_, float alto_, float total_columnas_, float vida_,  float posx, float posy, QObject *parent = nullptr);
    int movement;
    float filas = 0, columnas = 0, total_columnas;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void up();
    void down();
    void left();
    void right();
    void movimiento1();
    void movimiento2();
    void movimiento3();
    void movimiento4();
    void seguir(float playerx_, float playery_);
    ~jefe();


signals:
public slots:
    void Actualizacion();

};

#endif // JEFE_H
