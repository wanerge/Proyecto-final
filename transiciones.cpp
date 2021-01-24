#include "transiciones.h"

transiciones::transiciones(QString direccion_img, float ancho_, float alto_, float total_columnas_, float total_filas_)
{
    total_columnas = total_columnas_;
    total_filas = total_filas_;
    ancho = ancho_;
    alto = alto_;

    img = new QPixmap(direccion_img);
    timer = new QTimer;

    timer->start(250);
    connect(timer, &QTimer::timeout, this, &transiciones::Actualizacion);
}

void transiciones::Actualizacion()
{
    tiempo_transcurrido += 0.25;
    if ((filas == 0 && tiempo_transcurrido == 4) || (filas == alto*4 && tiempo_transcurrido == 4)) {
        columnas += ancho;
        tiempo_transcurrido = 0;
        if (columnas >= (ancho*total_columnas)) {
            columnas = 0;
            filas += alto;
        }
    }
    else if((filas == alto*1) || (filas == alto*2) || (filas == alto*3)) {
        columnas += ancho;
        if (columnas >= (ancho*total_columnas)){
            columnas = 0;
        }
        if (tiempo_transcurrido == 4) {
            tiempo_transcurrido = 0;
            columnas = 0;
            filas += alto;
        }
    }

    this->update(0, 0, ancho, alto);
}

QRectF transiciones::boundingRect() const
{
    return QRectF(0, 0, ancho, alto);
}

void transiciones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *img, columnas, filas, ancho, alto);
}

transiciones::~transiciones()
{
    delete timer;
    delete img;
}
