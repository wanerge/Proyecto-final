#include "enemigos.h"

enemigos::enemigos(QString direccion_img, float ancho_, float alto_, float total_columnas_, QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;
    img = new QPixmap(direccion_img);
    timer = new QTimer;
    timer->start(60);
    connect(timer, &QTimer::timeout, this, &enemigos::Actualizacion);
}

void enemigos::Actualizacion()
{
    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);
}

QRectF enemigos::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void enemigos::up()
{
    setPos(x(),y()-velocidad);
}

void enemigos::down()
{
    setPos(x(),y()+velocidad);
}

void enemigos::left()
{
    setPos(x()-velocidad,y());
}

void enemigos::right()
{
    setPos(x()+velocidad,y());
}

enemigos::~enemigos()
{
    delete img;
    delete timer;
}
