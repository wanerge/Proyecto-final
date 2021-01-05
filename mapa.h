#ifndef MAPA_H
#define MAPA_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include "colisiones.h"

class mapa
{
public:
    mapa();
    void carga_Datos(QString nombre_archivo);
    QVector<colisiones *> *getContenedor() const;

private:
    QVector<colisiones *> *contenedor = new QVector<colisiones *>;
};

#endif // MAPA_H
