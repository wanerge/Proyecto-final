#include "interfaz_inicio.h"

interfaz_inicio::interfaz_inicio()
{
    wid = new QWidget;
    scene = new QGraphicsScene;
    lay = new QVBoxLayout;

    scene->setSceneRect(0,0,1366,768);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/portada.jpg")));

    modo_menu();

    wid->setLayout(lay);

    lay->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

void interfaz_inicio::modo_menu()
{
    if (!lay->isEmpty()) {
        delete boton_Facil;
        delete boton_Dificil;
        modo_menu();
    }
    else {
        boton_Nueva = new Button("Nueva Partida");
        boton_Multijugador = new Button("Multijugador");
        boton_Cargar = new Button("Cargar Partida");
        boton_Eliminar = new Button("Eliminar Partida");
        boton_Ayuda = new Button("Ayuda");
        boton_Salir = new Button("Salir");
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
    delete boton_Nueva;
    delete boton_Multijugador;
    delete boton_Cargar;
    delete boton_Eliminar;
    delete boton_Ayuda;
    delete boton_Salir;

    boton_Facil = new Button("Facil");
    boton_Dificil = new Button("Dificil");

    lay->addWidget(boton_Facil);
    lay->addWidget(boton_Dificil);
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

Button *interfaz_inicio::getBoton_Facil() const
{
    return boton_Facil;
}

Button *interfaz_inicio::getBoton_Dificil() const
{
    return boton_Dificil;
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
    delete lay;
    delete wid;
    delete scene;
}
