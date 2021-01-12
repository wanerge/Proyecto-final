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

    boton_facil = new Button("Facil");
    boton_dificil = new Button("Dificil");

    scene->setSceneRect(0,0,1366,768);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/portada.jpg")));

    modo_menu();

    wid->setLayout(lay);

    lay->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

void interfaz_inicio::modo_menu()
{
    if (!lay->isEmpty()) {
        lay->removeWidget(boton_facil);
        lay->removeWidget(boton_dificil);
        modo_menu();
    }
    else {
        lay->addWidget(boton_Nueva);
        lay->addWidget(boton_Multijugador);
        lay->addWidget(boton_Cargar);
        lay->addWidget(boton_Eliminar);
        lay->addWidget(boton_Ayuda);
        lay->addWidget(boton_Salir);
    }
}

void interfaz_inicio::modo_dificultad()
{
    lay->removeWidget(boton_Nueva);
    lay->removeWidget(boton_Multijugador);
    lay->removeWidget(boton_Cargar);
    lay->removeWidget(boton_Eliminar);
    lay->removeWidget(boton_Ayuda);
    lay->removeWidget(boton_Salir);

    lay->addWidget(boton_facil);
    lay->addWidget(boton_dificil);
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
