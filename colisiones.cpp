#include "colisiones.h"


//Tomamos posicion y dimensiones del muro
colisiones::colisiones(int w_, int h_, int x, int y)
{
    w=w_;
    h=h_;
    posx=x;
    posy=y;
}
//Tomamos dimensiones y posicion del rectangulo que contendra la pared
QRectF colisiones::boundingRect() const
{
      return QRectF(-posx,-posy,w,h);
}

//Dibujamos el rectangulo
void colisiones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
