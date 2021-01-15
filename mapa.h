#ifndef MAPA_H
#define MAPA_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include "colisiones.h"

class mapa
{
public:
    mapa(QString mundo_);
    ~mapa();

    QVector<colisiones *> *getContenedor() const;
    QGraphicsScene *getMundo() const;
    QVector<colisiones *> *getZonaspawn() const;

    void carga_Datos(QString nombre_archivo, QVector<colisiones *> *container);

private:
    QGraphicsScene *mundo;
    QVector<colisiones *> *contenedor;
    QVector<colisiones *> *zonaspawn;
};

#endif // MAPA_H
