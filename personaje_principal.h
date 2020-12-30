#ifndef PERSONAJE_PRINCIPAL_H
#define PERSONAJE_PRINCIPAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class personaje_principal : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx=120;
    int posy =120;
public:
    explicit personaje_principal(QString direccion, float ancho_, float alto_, float fila_, float columna_, QObject *parent = nullptr);
    ~personaje_principal();

    QPixmap *img;
    QTimer *timer;
    //variable que me dice si estan precionando una tecla
    bool ispush;
    //Velocidad del personaje
    int velocidad = 5;

    float filas, columnas;
    float ancho, alto;
    //funcion movimiento ascendente personaje
    void up();

    //funcion movimiento ascendente personaje
    void down();

    //funcion movimiento ascendente personaje
    void left();

    //funcion movimiento ascendente personaje
    void right();

    //funcion movimiento ascendente personaje

    //funcion movimiento ascendente personaje

    //dibujo el recuadro que contedra al personaje
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    //Funcion para actualizar los frames del personaje
    //Funciona con un timer
    void Actualizacion();

};

#endif // P_PRINCIPAL_H

