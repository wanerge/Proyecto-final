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
    //Funcion para gargar datos de un txt a un qmap
    void carga_Datos(QString nombre_archivo);

    //Funcion que me genera los enemigos y jefes en el mapa
    void generador(QString mob, QString imagsource, QString disparo);

    //Funcion que invoca a generador con diferentes
    //parametros dependiendo de la zona
    void zona_activa(int i);

    //Variable del nivel
    int mundo=1;

    //variable para saber si una zona ya no esta activa
    bool activo=false;

    //Retorna vector de enemigos
    QVector<enemigos *> *getEnemigos() const;

    //Retorna vector de jefes
    QVector<jefe *> *getJefes() const;

    //Retorna vector de poderes
    QVector<Powerboss *> *getEyes() const;

    //Retorna el Qmap
    QMap<QString, float *> *getInfoenemy() const;

    void setInfoenemy(QMap<QString, float *> *value);

private:
    //Mapa que contiene toda la informacion de los enemgigos y jefes
    QMap<QString, float *> *infoenemy;
    //Vector que contiene a los enemigos activos
    QVector<enemigos *> *Enemigos;
    //Vector que contiene  a los jefes activos
    QVector<jefe *> *Jefes;
    //Vector que contiene a los ojos del toro activos
    QVector<Powerboss *> *eyes;

    float *datos;
    //QVector<int> numero_datos;

signals:

};

#endif // SPAWN_H
