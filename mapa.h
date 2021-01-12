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

    void carga_Datos(QString nombre_archivo,QString contenedor);

    QVector<colisiones *> *getContenedor() const;

    QGraphicsScene *getMundo() const;

    QVector<colisiones *> *getZonaspawn() const;

    QVector<int *> *getInvocacion() const;

    ~mapa();

private:
    spawn *myspwan;
    QGraphicsScene *mundo;
    QVector<colisiones *> *contenedor;
    QVector<colisiones *> *zonaspawn;
    QVector<int *> *invocacion;
};

#endif // MAPA_H
