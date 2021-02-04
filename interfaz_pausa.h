#ifndef INTERFAZ_PAUSA_H
#define INTERFAZ_PAUSA_H

#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QWidget>
#include <QDebug>
#include "button.h"

class interfaz_pausa: public QGraphicsScene
{
public:
    //constructor se crea la interfaz de pausa y dependiendo si es multijugador o no se carga el boton guardar
    interfaz_pausa(bool multijugador);
    ~interfaz_pausa();

    QWidget *getWid() const;
    QVBoxLayout *getLay() const;
    Button *getBoton_Guardar() const;
    Button *getBoton_Reiniciar() const;
    Button *getBoton_Salir() const;

private:
    QWidget *wid;
    QVBoxLayout *lay;

    Button *boton_Guardar;
    Button *boton_Reiniciar;
    Button *boton_Salir;
};

#endif // INTERFAZ_PAUSA_H
