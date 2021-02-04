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

    //funciones para el cambio de imagen del objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Funciones de movimiento del objeto
    void up();
    void down();
    void left();
    void right();
    void movimiento();

    //Funcion para obtener pos de jugador
    void seguir(float playerx_,float playery_);

    //define si el objeto se desplaza o dispara
    QString Disparo;
    //velocidad define cada cuantos pixeles se desplaza el objeto
    float velocidad = 5;
    //variables para el funcionamiento del cambio de imagen
    float filas = 0, columnas = 0, total_columnas;
    //define cuanta vida tiene el objeto
    float vida = 90;

    QTimer *timer;

private:
    QPixmap *img;
    float ancho, alto;
    //variables para definir la posicion donde esta ubicado el jugador
    float playerx,playery;

signals:

public slots:
    //funcion para el constante movimiento y cambio de imagen del objeto
    void Actualizacion();

};

#endif // ENEMIGOS_H
