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
public:
    explicit personaje_principal(QString direccion, float ancho_, float alto_, float fila_, float columna_, QObject *parent = nullptr);
    ~personaje_principal();

    QPixmap *img;
    QTimer *timer;

    //variable que me dice si estan precionando una tecla
    bool ispush;

    //Velocidad del personaje
    int velocidad = 6;
    int vida = 1000;

    float filas, columnas;
    float ancho, alto;

    //funcion movimiento ascendente personaje
    void up();
    void down();
    void left();
    void right();

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

