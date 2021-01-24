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
    QPixmap *img;

    float velocidad;
    float ayudantepos, posiniciox, posinicioy;
    float contador = 0, posxskill, posyskill;
    float tiempo = 0 ,tiempo2 = 0;

public:
    explicit jefe(QString direccion_img, int movement_, float ancho_, float alto_, float total_columnas_, float vida_, float velocidad_, float posx, float posy, QObject *parent = nullptr);
    ~jefe();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void up();
    void down();
    void left();
    void right();
    void movimiento1();
    void movimiento2();
    void movimiento3();
    void movimiento4();
    void seguir(float playerx_, float playery_);

    QTimer *timer;
    float vida;
    float ancho, alto;
    float filas = 0, columnas = 0, total_columnas;
    float playerx = 1400,playery = 400;
    int movement;

    //variables para la habilidad del toro(jefe)
    int distancia_recorrida = 0, total_habilidades = 4;
    bool habilidad_disponible = true;

signals:
public slots:
    void Actualizacion();

};

#endif // JEFE_H
