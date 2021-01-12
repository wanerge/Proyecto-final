#include "enemigos.h"

enemigos::enemigos(QString direccion_img, float ancho_, float alto_, float total_columnas_, float posx, float posy,QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;
    img = new QPixmap(direccion_img);
    timer = new QTimer;
    timer->start(60);
    connect(timer, &QTimer::timeout, this, &enemigos::Actualizacion);
    setPos(posx,posy);


}

void enemigos::Actualizacion()
{
    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);

    if(y() < playery-5 ){
        down();
        filas=0;
    }
    else if(y() > playery+5){
        up();
        filas = alto;
    }
    else if(x() > playerx){
        left();
        filas = alto*3;
    }
    else{
        right();
        filas = alto*2;
    }

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

void enemigos::seguir(float playerx_, float playery_)
{
    playerx=playerx_;
    playery=playery_;
}

enemigos::~enemigos()
{
    delete img;
    delete timer;
}
