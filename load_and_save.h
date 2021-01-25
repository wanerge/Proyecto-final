#ifndef LOAD_AND_SAVE_H
#define LOAD_AND_SAVE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include "personaje_principal.h"
#include "spawn.h"
#include "colisiones.h"

class load_and_save
{
public:
    load_and_save(QMainWindow *mainwindow);
    ~load_and_save();

    void load(QString nombreArch);
    void save(QString nombreArch);
    void l_personaje(QString linea1);
    void l_enemigos(QString linea1);
    void l_zona_bloquada(QString linea1);

    QString estado;
    int mundo, num_vidas, vida;
    float per_x, per_y;
    float *datos;
    bool crear = true;

    QVector<personaje_principal *> personajes;
    QMap<QString, float *> *infoenemy;
    QVector<colisiones *> *zona_blocked;

    QMap<QString, float *> *getInfoenemy() const;
    QVector<colisiones *> *getZona_blocked() const;

private:
    QMainWindow *mainwindow;
};

#endif // LOAD_AND_SAVE_H
