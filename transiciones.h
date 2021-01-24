#ifndef TRANSICIONES_H
#define TRANSICIONES_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class transiciones : public QObject, public QGraphicsItem
{
public:
    transiciones(QString direccion_img, float ancho_, float alto_, float total_columnas_, float total_filas_);
    ~transiciones();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float ancho, alto;
    float filas = 0, columnas = 0, total_columnas, total_filas;
    float tiempo_transcurrido=0;

private:
    QPixmap *img;
    QTimer *timer;

public slots:
    void Actualizacion();
};

#endif // TRANSICIONES_H
