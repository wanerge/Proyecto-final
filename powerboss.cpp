#include "powerboss.h"

Powerboss::Powerboss(QString direccion_img, float ancho_, float alto_, float total_columnas_,int movement_, jefe *boss_, QVector<personaje_principal *> personajes_, QObject *parent) : QObject(parent)
{
    boss = boss_;
    personajes = personajes_;
    //person = person_;
    posx = boss->x();
    posy = boss->y();

    img = new QPixmap(direccion_img);
    timer = new QTimer;

    ancho = ancho_;
    alto = alto_;
    total_columnas = total_columnas_;
    movement = movement_;

    timer->start(25);

    if (movement == 2) {
        posx += 70;
        posy += 65;
    }

    if(movement != 3){
        posx += (boss->ancho/2);
        posy += (boss->alto/2);
        setPos(posx, posy);
    }
    connect(timer, &QTimer::timeout, this, &Powerboss::actualizar);
}

QRectF Powerboss::boundingRect() const
{
    return QRectF(ancho/2, alto/2, ancho, alto);
}

void Powerboss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(ancho/2, alto/2, *img, columnas, filas, ancho, alto);
}

void Powerboss::actualizar()
{
    columnas += ancho;
    if (columnas >= (ancho*total_columnas)){
        columnas = 0;
    }
    this->update(ancho/2, alto/2, ancho, alto);

    if(movement == 1){
        movimiento1();
        for (auto it : personajes) {
            if (collidesWithItem(it)) {
                it->vida -= 10;
                it->barra_personaje->setValue(it->vida);
            }
        }
        if(tiempo2 >= 40){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(movement == 2){
        movimiento2();
        for (auto it : personajes ) {
            if (collidesWithItem(it)) {
                it->vida -= 10;
                it->barra_personaje->setValue(it->vida);
                setY(1300);
            }
        }
        if(y() >= 500){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(movement == 3){
        posx = boss->x()+40;
        posy = boss->y()+40;
        movimiento3();
        for (auto it : personajes ) {
            if (collidesWithItem(it)) {
                it->vida -= 10;
                it->barra_personaje->setValue(it->vida);
            }
        }
    }
    else if(movement == 4){
        movimiento4();
        for (auto it : personajes ) {
            if (collidesWithItem(it)) {
                it->vida -= 10;
                it->barra_personaje->setValue(it->vida);
                setY(-100);
            }
        }
        if(y() <= 10){
            timer->stop();
            scene()->removeItem(this);
            delete this;
        }
    }
}

void Powerboss::movimiento1()
{
    float x,y;
    float V0o = 15;
//    if(tiempo2 >= 20){
//        scene()->removeItem(this);
//        delete this;
//    }
    if (tiempo2 == 0){
        angle = (rand()%120) + 1;
        Vxo = V0o*cos(angle*pi/180);
        Vyo = -1*V0o*sin(angle*pi/180);
        posxskill = posx;
        posyskill = posy;
    }
    if(this->x() < 1390 and contador >5){
        Vxo = Vxo*-1;
        Vxo *= coeficiente;
        contador = 0;
        posxskill = 1390;
        posyskill = this->y();
        tiempo = 0;
    }
    else if(this->x() > 1850 and contador >5){
        Vxo =Vxo*-1;
        Vxo *= coeficiente;
        posxskill = 1850;
        posyskill = this->y();
        contador = 0;
        tiempo = 0;
    }
    if(this->y() < 120 and contador >5){
        Vyo = Vyo*-1;
        Vyo *= coeficiente;
        contador = 0;
        posyskill = 120;
        posxskill = this->x();
        tiempo = 0;
    }
    else if(this->y() > 800 and contador >5){
        Vyo = Vyo*-1;
        Vyo *= coeficiente;
        contador = 0;
        posxskill = this->x();
        posyskill = 800;
        tiempo = 0;
    }
    x = posxskill + Vxo*tiempo;
    y = posyskill + Vyo*tiempo;
    setPos(x,y);
    tiempo += 1;
    tiempo2 += 0.3;
    contador++;
}

void Powerboss::movimiento2()
{
    float x2,y2;
//    if(tiempo2 >= 45){
//        scene()->removeItem(this);
//        delete this;
//    }
    if(tiempo2 >=44)
        filas = alto;
    if (tiempo2 == 0){
        V0o = (rand()%45)+25;
        angle = (rand()%75)+10;
        angle *= -1;
        //angle = -20;
        Vxo = V0o*cos(angle*pi/180);
        Vyo = V0o*sin(angle*pi/180);
        posxskill = posx;
        posyskill = posy;
    }
    x2 = posx + Vxo * tiempo;
    y2 = posy + Vyo * tiempo +(0.5 * G * tiempo * tiempo);
    setPos(x2,y2);
    tiempo += 0.3;
    tiempo2 +=0.6;
}

void Powerboss::movimiento3()
{
    float x3,y3;
    float limit=360;
    if(tiempo == 0){
        angle = 0;
        tiempo++;
    }
    if(angle > limit){
//        scene()->removeItem(this);
//        delete this;
        angle = 0;
    }

    float aux =angle*pi/180;
    x3=posx+cos(aux)*70;
    y3=posy+sin(aux)*70;
    setPos(x3,y3);
    angle+=12;
}

void Powerboss::movimiento4()
{
    float x4;
    if(tiempo == 0){
        angle = (rand()%100)+40;
    }
    Vxo = velocidad*cos(angle*pi/180);
    if(velocidad <18){
        Vxo = velocidad*cos(-angle*pi/180);
    }
//    if(velocidad <= 1){
//        scene()->removeItem(this);
//        delete this;
//    }
    velocidad=velocidad-friccion;
    x4 = posx+Vxo*tiempo;
    ayudantepos = posy+velocidad*tiempo;
    tiempo+=0.5;
    setPos(x4,ayudantepos);
}

Powerboss::~Powerboss()
{
    delete timer;
    delete img;
}
