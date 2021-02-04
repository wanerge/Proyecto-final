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
    //constructor se crea y carga la imagen del mapa
    mapa(QString mundo_);
    ~mapa();

    QVector<colisiones *> *getContenedor() const;
    QGraphicsScene *getMundo() const;
    QVector<colisiones *> *getZonaspawn() const;

    //carga los datos de un archivo de texto y los guarda en un contenedor tipo QVector<colisiones *> *
    void carga_Datos(QString nombre_archivo, QVector<colisiones *> *container);

    QVector<colisiones *> *getZona_blocked() const;

    void setZona_blocked(QVector<colisiones *> *value);

private:
    colisiones *rec;
    QGraphicsScene *mundo;
    QVector<colisiones *> *contenedor;
    QVector<colisiones *> *zonaspawn;
    QVector<colisiones *> *zona_blocked;
};

#endif // MAPA_H
