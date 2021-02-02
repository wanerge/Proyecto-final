#ifndef JEFE_H
#define JEFE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class jefe :  public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    //Variable para imag enemigo
    QPixmap *img;
    //Velocidad del jefe
    float velocidad;
    //Variables utilizadas en sus movimientos
    float ayudantepos, posiniciox, posinicioy;
    float contador = 0, posxskill, posyskill;
    float tiempo = 0 ,tiempo2 = 0;

public:
    //Constructor
    explicit jefe(QString direccion_img, int movement_, float ancho_, float alto_, float total_columnas_, float vida_, float velocidad_, float posx, float posy, QObject *parent = nullptr);
    ~jefe();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //Funciones de que se invocan en el movimiento del 3er jefe
    void up();
    void down();
    void left();
    void right();

    //Movimiento de jefe 1
    void movimiento1();
    //Movimiento de jefe 2
    void movimiento2();
    //Movimiento de jefe 3
    void movimiento3();
    //Movimiento de jefe 4
    void movimiento4();

    //funcion para tener pos usuario
    void seguir(float playerx_, float playery_);

    QTimer *timer;
    //Vida del jefe
    float vida;
    //Dimensiones
    float ancho, alto;
    float filas = 0, columnas = 0, total_columnas;

    //varaibles de posicion de jugador para jefe 3
    float playerx = 1400,playery = 400;

    //Variable que me indica
    int movement;

    //variables para la habilidad del toro(jefe)
    int distancia_recorrida = 0, total_habilidades = 4;
    bool habilidad_disponible = true;

signals:
public slots:
    //Funcion que actualiza sprite y posicion del jefe
    void Actualizacion();

};

#endif // JEFE_H
