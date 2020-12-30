#ifndef BOLITA_H
#define BOLITA_H
#include <QGraphicsItem>
#include <QPainter>

class bolita:public QGraphicsItem
{
    int r;
    int posx;
    int posy;
    int velocidad = 40;
    int vidas=3;

public:
    bolita(int r_,int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget=nullptr);
    void up();
    void down();
    void left();
    void right();
    void cambiarder();
    void cambiarizq();
    void damag();
};

#endif // BOLITA_H
