#include "bullets_enemy.h"

bullets_enemy::bullets_enemy(QString direccion_img, float ancho_, float alto_, float total_columnas_, personaje_principal *personaje_, QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;
    personaje = personaje_;
    pos_final_x = personaje->x()+16;
    pos_final_y = personaje->y()+16;

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

//    if (x()-pos_final_x > 0) {
//        right();
//    }
//    else {
//        left();
//    }
//    if (pos_final_y > y()) {
//        down();
//    }
//    else {
//        up();
//    }

//    if (x() < pos_final_x and y() < pos_final_y) {
//        right();
//        down();
//    }
//    else if (x() > pos_final_x and y() < pos_final_y) {
//        left();
//        down();
//    }
//    else if (x() < pos_final_x and y() > pos_final_y) {
//        right();
//        up();
//    }
//    else if (x() > pos_final_x and y() > pos_final_y) {
//        left();
//        up();
//    }

    if (this->collidesWithItem(personaje)) {
        personaje->vida -= 10;
        personaje->barra_personaje->setValue(personaje->vida);
        setPos(pos_final_x, pos_final_y);
    }

    if ((pos_final_x-x() < 6 && pos_final_x-x() > -6) && (pos_final_y-y() < 6 && pos_final_y-y() > -6)){
        scene()->removeItem(this);
        delete this;
    }

    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);
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
