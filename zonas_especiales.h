#ifndef ZONAS_ESPECIALES_H
#define ZONAS_ESPECIALES_H

#include "colisiones.h"

class zonas_especiales
{
public:
    zonas_especiales();
    ~zonas_especiales();

    //carga los objetos predefinidos para el mundo 1(objetos-colisiones para determinados lugares)
    void mundo1();
    //carga los objetos predefinidos para el mundo 2(objetos-colisiones para determinados lugares)
    void mundo2();
    QVector<colisiones *> *getContenedor() const;

private:
    colisiones *rec;
    QVector<colisiones *> *contenedor;
};

#endif // ZONAS_ESPECIALES_H
