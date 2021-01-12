#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMainWindow>

class life
{
public:
    life(QMainWindow *s, int num_vidas, int max_x_view);
    ~life();

    void eliminar_vida();

private:
    QGraphicsView *view;
    QGraphicsScene *escena;
    QGraphicsPixmapItem *corazon;
    QVector<QGraphicsPixmapItem *> *vidas;
};

#endif // LIFE_H
