#ifndef INTERFAZ_INICIO_H
#define INTERFAZ_INICIO_H

#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QWidget>
#include <QDebug>
#include "button.h"

class interfaz_inicio: public QGraphicsScene
{
public:
    interfaz_inicio();
    ~interfaz_inicio();

    void modo_menu();
    void modo_dificultad();

    QWidget *getWid() const;
    QGraphicsScene *getScene() const;
    QVBoxLayout *getLay() const;
    Button *getBoton_Nueva() const;
    Button *getBoton_Multijugador() const;
    Button *getBoton_Cargar() const;
    Button *getBoton_Eliminar() const;
    Button *getBoton_Ayuda() const;
    Button *getBoton_Salir() const;

private:
    QWidget *wid;
    QGraphicsScene *scene;
    QVBoxLayout *lay;

    Button *boton_Nueva;
    Button *boton_Multijugador;
    Button *boton_Cargar;
    Button *boton_Eliminar;
    Button *boton_Ayuda;
    Button *boton_Salir;

    Button *boton_facil;
    Button *boton_dificil;
};

#endif // INTERFAZ_INICIO_H
