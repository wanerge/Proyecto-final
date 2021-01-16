#include "interfaz_pausa.h"

interfaz_pausa::interfaz_pausa(bool multijugador)
{
    wid = new QWidget;
    lay = new QVBoxLayout;

    wid->resize(200,200);

    if (!multijugador) {
        boton_Guardar = new Button("Guardar Partida");
        lay->addWidget(boton_Guardar);
    }

    boton_Reiniciar = new Button("Reiniciar Partida");
    boton_Salir = new Button("Volver al Menu");

    lay->addWidget(boton_Reiniciar);
    lay->addWidget(boton_Salir);

    wid->setLayout(lay);

    lay->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

QWidget *interfaz_pausa::getWid() const
{
    return wid;
}

QVBoxLayout *interfaz_pausa::getLay() const
{
    return lay;
}

Button *interfaz_pausa::getBoton_Guardar() const
{
    return boton_Guardar;
}

Button *interfaz_pausa::getBoton_Reiniciar() const
{
    return boton_Reiniciar;
}

Button *interfaz_pausa::getBoton_Salir() const
{
    return boton_Salir;
}

interfaz_pausa::~interfaz_pausa()
{
    delete wid;
}
