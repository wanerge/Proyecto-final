#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QLabel>
#include <QFont>
#include <QMainWindow>

class puntaje
{
public:
    //constructor se crea y se muestra en pantalla la cantidad de puntos del jugador
    puntaje(QMainWindow *mainwindow, int x_, int y_);
    ~puntaje();

    //actualiza en pantalla la cantidad de puntos del jugador
    void actualizar(int *puntos);
    QLabel *label;
};

#endif // PUNTAJE_H
