#include "personaje_principal.h"
//Constructor de la clase del personaje
personaje_principal::personaje_principal(QString direccion, float ancho_, float alto_, float fila_, float columna_, QObject *parent) : QObject(parent)
{
    setPos(150, 740);

    filas = fila_;
    columnas = columna_;
    ancho = ancho_;
    alto = alto_;

    img = new QPixmap(direccion);
    timer = new QTimer;

    timer->start(50);

    connect(timer, &QTimer::timeout, this, &personaje_principal::Actualizacion);
}


//Funcion que actualiza las imagenes del sprite
void personaje_principal::Actualizacion()
{
    if(ispush){
        columnas += ancho;
        if (columnas >= (ancho*4)){
            columnas = 0;
        }
    }
    this->update(ancho/2, alto/2, ancho, alto);

}

QRectF personaje_principal::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void personaje_principal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void personaje_principal::up()
{
    ispush = true;
    if(y() > 50){
        setPos(x(), y()-velocidad);
    }
}

void personaje_principal::down()
{
    ispush = true;
    if(y() < 900){
        setPos(x(), y()+velocidad);
    }
}

void personaje_principal::left()
{
    ispush = true;
    if(x() > 70){
        setPos(x()-velocidad, y());
    }
}

void personaje_principal::right()
{
    ispush = true;
    if(x() < 4750){
        setPos(x()+velocidad, y());
    }
}

personaje_principal::~personaje_principal()
{
    delete img;
    delete timer;
}

