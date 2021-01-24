#include "jefe.h"

jefe::jefe(QString direccion_img, int movement_, float ancho_, float alto_, float total_columnas_, float vida_, float velocidad_, float posx, float posy, QObject *parent) : QObject(parent)
{
    total_columnas = total_columnas_;
    ancho = ancho_;
    alto = alto_;
    posiniciox = posx;
    posinicioy = posy;
    movement = movement_;
    vida = vida_;
    velocidad = velocidad_;

    img = new QPixmap(direccion_img);
    timer = new QTimer;

    timer->start(80);
    connect(timer, &QTimer::timeout, this, &jefe::Actualizacion);

    setPos(posx,posy);
}
void jefe::Actualizacion()
{
    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);
    if(movement == 1){
        movimiento1();
    }
    else if (movement == 2){
        movimiento2();
    }
    else if (movement == 3){
        movimiento3();
    }
    else if (movement == 4){
        movimiento4();
    }
}

QRectF jefe::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void jefe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void jefe::movimiento1()
{
    if(velocidad > 0){
        filas = alto;
    }
    else if(velocidad < 0){
        filas =alto*3;
    }
    ayudantepos = posiniciox+velocidad*tiempo;
    tiempo += 0.3;
    if(tiempo > 12){
        tiempo = 0;
        velocidad *= -1;
        posiniciox = ayudantepos;
    }
    setPos(ayudantepos,y());
}

void jefe::movimiento2()
{
    if(vida < 1500){
        filas = alto;
    }
    ayudantepos = posinicioy+velocidad*tiempo;
    tiempo += 0.2;
    if(tiempo > 11){
        tiempo = 0;
        velocidad *= -1;
        posinicioy = ayudantepos;
    }
    setPos(x(),ayudantepos);
}

void jefe::movimiento3()
{
    velocidad += 1;
    if(velocidad >35){
        velocidad = 15;
    }
    if(x() - playerx > -10 and x() - playerx < 10 and y() - playery > -10 and y() - playery < 10){
        velocidad = 0;
    }
    if(y() < playery and x()-playerx >-10 and x()-playerx < 10){
        filas = 0;
        down();
    }
    else if(y() > playery and x()-playerx >-10 and x()-playerx < 10){
        filas = alto;
        up();
    }
    else if(x() > playerx and y()-playery > -10 and y()-playery < 10){
        filas = alto*3;
        left();
    }
    else if(x() < playerx and y()-playery > -10 and y()-playery < 10){
        filas = alto*2;
        right();
    }
    else {
        if (x() < playerx and y() < playery) {
            filas = alto*2;
            right();
            down();
        }
        else if (x() > playerx and y() < playery) {
            filas = alto*3;
            left();
            down();
        }
        else if (x() < playerx and y() > playery) {
            filas = alto*2;
            right();
            up();
        }
        else if (x() > playerx and y() > playery) {
            filas = alto*3;
            left();
            up();
        }
    }
}

void jefe::movimiento4()
{
    filas = 0;
    ayudantepos = posiniciox+velocidad*tiempo;
    tiempo += 0.3;
    if(tiempo > 7){
        tiempo = 0;
        velocidad *= -1;
        posiniciox = ayudantepos;
    }
    setPos(ayudantepos,y());
}

void jefe::seguir(float playerx_, float playery_)
{
    playerx = playerx_ - 15;
    playery = playery_ - 15;
}

void jefe::up()
{
    setPos(x(),y()-velocidad);
}

void jefe::down()
{
    setPos(x(),y()+velocidad);
}

void jefe::left()
{
    setPos(x()-velocidad,y());
}

void jefe::right()
{
    setPos(x()+velocidad,y());
}

jefe::~jefe()
{
    delete timer;
    delete img;
}
