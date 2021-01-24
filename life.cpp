#include "life.h"

life::life(QMainWindow *s, int num_vidas, int max_x_view, int pos_x, int pos_y)
{
    view = new QGraphicsView(s);
    escena = new QGraphicsScene;
    vidas = new QVector<QGraphicsPixmapItem *>;

    view->setGeometry(pos_x,pos_y,max_x_view,32);
    view->setScene(escena);
    view->show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(QBrush(Qt::BrushStyle::Dense1Pattern));

    for (int i = 0, posicion = 0; i < num_vidas ; i++ , posicion += 33) {
        corazon = new QGraphicsPixmapItem;
        corazon->setPixmap(QPixmap(":/Imagenes/corazon.png"));
        corazon->setPos(posicion, 0);
        vidas->push_back(corazon);
        escena->addItem(corazon);
    }
}

void life::eliminar_vida()
{
    escena->removeItem(vidas->last());
    vidas->removeLast();
}

QVector<QGraphicsPixmapItem *> *life::getVidas() const
{
    return vidas;
}

life::~life()
{
    delete vidas;
    delete escena;
    delete view;
}


