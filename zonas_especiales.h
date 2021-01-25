#ifndef ZONAS_ESPECIALES_H
#define ZONAS_ESPECIALES_H

#include "colisiones.h"

class zonas_especiales
{
public:
    zonas_especiales();
    ~zonas_especiales();

    void mundo1();
    void mundo2();
    QVector<colisiones *> *getContenedor() const;

private:
    colisiones *rec;
    QVector<colisiones *> *contenedor;
};

#endif // ZONAS_ESPECIALES_H
