#ifndef COLISIONES_H
#define COLISIONES_H

#include <QGraphicsItem>
#include <QPainter>

//Clase para las colisiones del personaje con paredes del escenario
class colisiones: public QGraphicsItem
{

public:
    int w,h;
    int posx,posy;
    colisiones(int w_, int h_, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr);

};

#endif // COLISIONES_H
