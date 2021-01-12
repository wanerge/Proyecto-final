#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <math.h>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <enemigos.h>
#include <QGraphicsScene>
#include <QDebug>

class spawn : public QObject
{
    Q_OBJECT
    QString direccion;
    QList<enemigos*> *identidades;

public:
    float *casa;
    explicit spawn(QObject *parent = nullptr);
    QMap<QString,QVector<float> > *infoenemy;
    void carga_Datos(QString nombre_archivo);
    void leerdatos();
    QList<enemigos*> generador(QString mob,QString imagsource);
    QList<enemigos*> zona_activa(int i);
    QVector<int *> *ayudante;


signals:

};

#endif // SPAWN_H
