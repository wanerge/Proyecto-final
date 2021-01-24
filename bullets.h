#ifndef BULLETS_H
#define BULLETS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "enemigos.h"
#include "jefe.h"

class bullets : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<enemigos *> *enemy, QObject *parent = nullptr);
    explicit bullets(QString direccion_img, float ancho_, float alto_, float total_columnas_, QVector<jefe *> *enemy, QObject *parent = nullptr);
    ~bullets();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    float velocidad = 20, distancia_max = 400;
    float filas = 0, columnas = 0, total_columnas;

    bool diagonal = false, tipo_enemy = true;

private:
    QVector<jefe *> *Jefe;
    QVector<enemigos *> *Enemigos;
    QPixmap *img;
    QTimer *timer;
    float ancho, alto;

signals:

public slots:
    void Actualizacion();

};

#endif // BULLETS_H
