#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMainWindow>

class life
{
public:
    //constructor se crea un GraphicsView y una escena nueva que difieren de la principal
    life(QMainWindow *s, int num_vidas, int max_x_view, int pos_x, int pos_y);
    ~life();

    void eliminar_vida();

    QVector<QGraphicsPixmapItem *> *getVidas() const;

private:
    QGraphicsView *view;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *corazon;
    QVector<QGraphicsPixmapItem *> *vidas;
};

#endif // LIFE_H
