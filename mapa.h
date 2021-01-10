#ifndef MAPA_H
#define MAPA_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include "colisiones.h"
#include "bullets.h"

class mapa
{
public:
    mapa(QString mundo_);
    ~mapa();
    void carga_Datos(QString nombre_archivo);

    QVector<colisiones *> *getContenedor() const;
    QGraphicsScene *getMundo() const;

private:
    QGraphicsScene *mundo;
    QVector<colisiones *> *contenedor;
};

#endif // MAPA_H
