#ifndef COLISIONES_H
#define COLISIONES_H

#include <QGraphicsItem>
#include <QPainter>

//Clase para las colisiones del personaje con paredes del escenario
class colisiones: public QGraphicsItem
{

public:
    //Ancho y alto de la colision
    int w,h;
    //posicion en X y en Y
    int posx,posy;
    //Constructor de las paredes
    colisiones(int w_, int h_, int x, int y, QBrush color_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr);
    QBrush color;

};

#endif // COLISIONES_H
