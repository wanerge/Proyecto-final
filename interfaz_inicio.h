#ifndef INTERFAZ_INICIO_H
#define INTERFAZ_INICIO_H

#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QDebug>
#include "button.h"

class interfaz_inicio: public QGraphicsScene
{
public:
    interfaz_inicio();
    ~interfaz_inicio();

    QGraphicsScene *getScene() const;
    QVBoxLayout *getLay() const;

private:
    QGraphicsScene *scene;
    QVBoxLayout *lay;
    Button *boton_Nueva;
    Button *boton_Cargar;
    Button *boton_Eliminar;
    Button *boton_Ayuda;
    Button *boton_Salir;

private slots:
    void on_boton_Nueva_clicked();
    void on_boton_Cargar_clicked();
    void on_boton_Eliminar_clicked();
    void on_boton_Ayuda_clicked();
    void on_boton_Salir_clicked();
};

#endif // INTERFAZ_INICIO_H
