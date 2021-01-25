#include "zonas_especiales.h"

zonas_especiales::zonas_especiales()
{
    contenedor = new QVector<colisiones *>;
}

void zonas_especiales::mundo1()
{
    contenedor->clear();
    rec = new colisiones(5, 70, -1370, -190, Qt::green);
    contenedor->push_back(rec);
    rec = new colisiones(500, 5, -1400, -615, Qt::green);
    contenedor->push_back(rec);
    rec = new colisiones(250, 5, -4400, -515, Qt::green);
    contenedor->push_back(rec);
    rec = new colisiones(5, 500, -4050, -20, Qt::green);
    contenedor->push_back(rec);
}

void zonas_especiales::mundo2()
{
    contenedor->clear();
    rec = new colisiones(200, 5, -710, -605, Qt::green);
    contenedor->push_back(rec);
    rec = new colisiones(5, 200, -4150, -350, Qt::green);
    contenedor->push_back(rec);
    rec = new colisiones(500, 5, -4200, -250, Qt::green);
    contenedor->push_back(rec);
}

QVector<colisiones *> *zonas_especiales::getContenedor() const
{
    return contenedor;
}

zonas_especiales::~zonas_especiales()
{
    delete contenedor;
}
