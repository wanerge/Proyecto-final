#ifndef PERSONAJE_PRINCIPAL_H
#define PERSONAJE_PRINCIPAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QProgressBar>

class personaje_principal : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    //constructor se crea el personaje con su barra de vida
    explicit personaje_principal(QString direccion, float ancho_, float alto_, float fila_, float columna_, int vida_, QObject *parent = nullptr);
    ~personaje_principal();

    //variable que me dice si estan precionando una tecla
    bool ispush = false;

    //variable para determinar la vida del objeto
    int vida;
     //velocidad define cada cuantos pixeles se desplaza el objeto
    float velocidad = 6;
    //variables para el funcionamiento del cambio de imagen
    int max_columnas = 4;
    float filas, columnas;
    //dimensiones del objeto
    float ancho, alto;

    /*variables para determinar la direccion de movimiento del objeto dependiendo de las teclas presionadas.
    se almacena en letra1 la nueva tecla presionada y en letra2 la anterior tecla presionada si la hubo */
    char letra1;
    char letra2;

    //define si la vida del objeto es mayor a 0 no cambia de estado
    QString estado = "vivo";

    QProgressBar *barra_personaje;

    //funcion movimiento ascendente personaje
    void up();
    void down();
    void left();
    void right();

    //funciones para el cambio de imagen del objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *img;
    QTimer *timer;

signals:

public slots:
    //funcion para el constante cambio de imagen del objeto
    void Actualizacion();

};

#endif // P_PRINCIPAL_H

