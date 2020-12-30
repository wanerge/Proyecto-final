#include "bolita.h"




bolita::bolita(int r_, int x, int y)
{
    r=r_;
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF bolita::boundingRect() const
{
    return  QRectF(-r,-r,2*r,2*r);
}

void bolita::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void bolita::up()
{
    posy -= 1*velocidad;
    setPos(posx,posy);
}

void bolita::down()
{
    posy += 1*velocidad;
    setPos(posx,posy);
}

void bolita::left()
{
    posx -= 1*velocidad;
    setPos(posx,posy);
}

void bolita::right()
{
    posx += 1*velocidad;
    setPos(posx,posy);
}

void bolita::cambiarder()
{
    posx =-205;
    posy = 195;
    setPos(posx,posy);
}

void bolita::cambiarizq()
{
    posx=610;
    posy=195;
    setPos(posx,posy);
}



