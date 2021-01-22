#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <math.h>
#include <QDebug>

class enemigos : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit enemigos(QString direccion_img, float ancho_, float alto_, float total_columnas_, float vida_, float velocidad_, QString disparo_, float posx, float posy,QObject *parent = nullptr);
    ~enemigos();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void movimiento();

    void seguir(float playerx_,float playery_);

    QString Disparo;
    float velocidad = 5;
    float filas = 0, columnas = 0, total_columnas;
    float vida = 90;

    QTimer *timer;

private:
    QPixmap *img;
    float ancho, alto;
    float playerx,playery;

signals:

public slots:
    void Actualizacion();

};

#endif // ENEMIGOS_H
