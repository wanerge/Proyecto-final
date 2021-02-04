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
    //constructor se crea un objeto en forma de cortometraje
    transiciones(QString direccion_img, float ancho_, float alto_, float total_columnas_, float total_filas_);
    ~transiciones();

    //funciones para el cambio de imagen del objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //dimensiones del objeto
    float ancho, alto;
    //variables para el funcionamiento del cambio de imagen
    float filas = 0, columnas = 0, total_columnas, total_filas;
    //variable para saber el tiempo transcurrido en cada transicion de imagen
    float tiempo_transcurrido=0;

private:
    QPixmap *img;
    QTimer *timer;

public slots:
    //funcion para el constante cambio de imagen del objeto
    void Actualizacion();
};

#endif // TRANSICIONES_H
