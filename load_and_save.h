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

    //funcion para cargar datos de un archivo con extension .hell
    void load(QString nombreArch);
    //funcion para guardar los datos en un archivo, el archivo se guarda con la extension .hell
    void save(QString nombreArch);
    //funciones para el manejo de datos al momento de cargarlos
    void l_personaje(QString linea1);
    void l_enemigos(QString linea1);
    void l_zona_bloquada(QString linea1);

    //variable para saber el estado en el que se guarda la partida(easy-hard)
    QString estado;
    //variables para saber en que mundo esta el personaje, su numero de vidas y la cantidad de vida actual
    int mundo, num_vidas, vida;
    //variables para saber la posicion del personaje
    float per_x, per_y;
    //variable necesaria para la creacion de enemigos. funcion(l_enemigos)
    float *datos;
    //variable para saber la cantidad de puntos actuales del personaje
    int puntos;
    //variable para saber si hubo un problema en el momento de cargar el archivo y permitir o no cargar los datos
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
