#ifndef SPAWN_H
#define SPAWN_H

#include <QObject>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include "enemigos.h"
#include <QDebug>

class spawn : public QObject
{
    Q_OBJECT
public:
    explicit spawn(QObject *parent = nullptr);
    ~spawn();

    void carga_Datos(QString nombre_archivo);
    void generador(QString mob, QString imagsource);
    void zona_activa(int i);
    int mundo=1;
    QVector<enemigos *> *getEnemigos() const;
    bool activo=false;

private:
    QMap<QString, float *> *infoenemy;
    QVector<enemigos *> *Enemigos;

    float *datos;
    QVector<int> numero_datos;

    int mundo = 1;

signals:

};

#endif // SPAWN_H
