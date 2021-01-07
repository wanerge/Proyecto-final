#include "interfaz_inicio.h"

interfaz_inicio::interfaz_inicio()
{
    wid = new QWidget;
    scene = new QGraphicsScene;
    lay = new QVBoxLayout;
    boton_Nueva = new Button("Nueva Partida");
    boton_Multijugador = new Button("Multijugador");
    boton_Cargar = new Button("Cargar Partida");
    boton_Eliminar = new Button("Eliminar Partida");
    boton_Ayuda = new Button("Ayuda");
    boton_Salir = new Button("Salir");

    scene->setSceneRect(0,0,1366,768);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/portada.jpg")));
    //scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/ayuda.png")));

    lay->addWidget(boton_Nueva);
    lay->addWidget(boton_Multijugador);
    lay->addWidget(boton_Cargar);
    lay->addWidget(boton_Eliminar);
    lay->addWidget(boton_Ayuda);
    lay->addWidget(boton_Salir);

    wid->setLayout(lay);

    lay->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

QGraphicsScene *interfaz_inicio::getScene() const
{
    return scene;
}

QVBoxLayout *interfaz_inicio::getLay() const
{
    return lay;
}

Button *interfaz_inicio::getBoton_Nueva() const
{
    return boton_Nueva;
}

Button *interfaz_inicio::getBoton_Cargar() const
{
    return boton_Cargar;
}

Button *interfaz_inicio::getBoton_Eliminar() const
{
    return boton_Eliminar;
}

Button *interfaz_inicio::getBoton_Ayuda() const
{
    return boton_Ayuda;
}

Button *interfaz_inicio::getBoton_Salir() const
{
    return boton_Salir;
}

Button *interfaz_inicio::getBoton_Multijugador() const
{
    return boton_Multijugador;
}

QWidget *interfaz_inicio::getWid() const
{
    return wid;
}

interfaz_inicio::~interfaz_inicio()
{
    delete wid;
    delete scene;
}
