#include "bullets_enemy.h"

bullets_enemy::bullets_enemy(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<personaje_principal *> personajes_, QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;
    personajes = personajes_;
    pos_final_x = personajes.first()->x()+16;
    pos_final_y = personajes.first()->y()+16;

    img = new QPixmap(direccion_img);
    timer = new QTimer;

    timer->start(15);

    connect(timer, &QTimer::timeout, this, &bullets_enemy::Actualizacion);
}

void bullets_enemy::Actualizacion()
{
    if (pos_final_x > x()) {
        right();
    }
    else {
        left();
    }
    if (pos_final_y > y()) {
        down();
    }
    else {
        up();
    }

    for (auto it : personajes) {
        if (this->collidesWithItem(it)) {
            it->vida -= 10;
            it->barra_personaje->setValue(it->vida);
            setPos(pos_final_x, pos_final_y);
        }
    }

    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);

    if ((pos_final_x-x() < 6 && pos_final_x-x() > -6) && (pos_final_y-y() < 6 && pos_final_y-y() > -6)){
        scene()->removeItem(this);
        delete this;
    }
}

QRectF bullets_enemy::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void bullets_enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void bullets_enemy::up()
{
    setPos(x(),y()-velocidad);
}

void bullets_enemy::down()
{
    setPos(x(),y()+velocidad);
}

void bullets_enemy::left()
{
    setPos(x()-velocidad,y());
}

void bullets_enemy::right()
{
    setPos(x()+velocidad,y());
}

bullets_enemy::~bullets_enemy()
{
    delete timer;
    delete img;
}
