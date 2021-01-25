#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include "enemigos.h"
#include <QDebug>
#include "jefe.h"
#include "powerboss.h"

class spawn : public QObject
{
    Q_OBJECT
public:
    explicit spawn(QObject *parent = nullptr);
    ~spawn();

    void carga_Datos(QString nombre_archivo);
    void generador(QString mob, QString imagsource, QString disparo);
    void zona_activa(int i);

    int mundo=1;
    bool activo=false;

    QVector<enemigos *> *getEnemigos() const;
    QVector<jefe *> *getJefes() const;
    QVector<Powerboss *> *getEyes() const;
    QMap<QString, float *> *getInfoenemy() const;

    void setInfoenemy(QMap<QString, float *> *value);

private:
    QMap<QString, float *> *infoenemy;
    QVector<enemigos *> *Enemigos;
    QVector<jefe *> *Jefes;
    QVector<Powerboss *> *eyes;

    float *datos;
    //QVector<int> numero_datos;

signals:

};

#endif // SPAWN_H
