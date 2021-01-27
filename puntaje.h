#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QLabel>
#include <QFont>
#include <QMainWindow>

class puntaje
{
public:
    puntaje(QMainWindow *mainwindow, int x_, int y_);
    ~puntaje();

    void actualizar(int *puntos);
    QLabel *label;
};

#endif // PUNTAJE_H
