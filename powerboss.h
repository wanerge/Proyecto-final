#ifndef POWERBOSS_H
#define POWERBOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>
#include <math.h>
#include "jefe.h"
#include "personaje_principal.h"
#include "bullets.h"

class Powerboss :public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //Variable que va a almacenar al jefe
    jefe *boss;

    //Vector que almacena los personajes
    QVector<personaje_principal *> personajes;
    //personaje_principal *person;
    QPixmap *img;
    QTimer *timer;
    //Dimensiones
    float ancho, alto;
    float filas = 0, columnas = 0,total_columnas;
    //Variables fisicas
    float velocidad =36;
    float V0o;

    float G=5;
    float posx,posy;
    float pi = 3.1416;
    float tiempo = 0, tiempo2 = 0;
    float angle;
    float friccion = 0.3,coeficiente = 0.9;
    float ayudantepos,posiniciox,posinicioy;
    float contador = 0, posxskill,posyskill;
    float Vxo;
    float Vyo;

    //Movimiento del poder
    int movement;

public:
    //Constructor poder
    explicit Powerboss(QString direccion_img, float ancho_, float alto_, float total_columnas_,int movement_, jefe *boss_, QVector<personaje_principal *> personajes_,QObject *parent = nullptr);
    ~Powerboss();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Funciones de diferentes tipos de movimientos
    void movimiento1();
    void movimiento2();
    void movimiento3();
    void movimiento4();

signals:

public slots:
    //Funcion que actualiza el sprite y invoca a la funcion movimientox()
    void actualizar();

};

#endif // POWERBOSS_H
