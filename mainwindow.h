#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QWidget>
#include <QProgressBar>
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>
#include "personaje_principal.h"
#include "mapa.h"
#include "interfaz_inicio.h"
#include "bullets.h"
#include "colisiones.h"
#include "life.h"
#include "spawn.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Funcion de keypreesevent que detecta las teclas presionadas
    void keyPressEvent(QKeyEvent *evento);
    void keyReleaseEvent(QKeyEvent *evento);

    //funciones para el movimiento del disparo
    void direccion_disparo();

    //funciones para el movimiento del personaje
    void actualizar();
    void colision_up();
    void colision_down();
    void colision_left();
    void colision_right();
    void colision_spawn();

    //carga el menu principal
    void menu();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    interfaz_inicio *inicio;
    QGraphicsScene *ayuda;
    mapa *escenario;
    QString estado;

    //se crea personaje principal
    personaje_principal *person;
    QProgressBar *barra_personaje;
    life *vidas;
    bullets *bullet;
    char letra1;
    char letra2;

    //Spawn de enemigos
    spawn *Spawner;

    QTimer *timer1;

public slots:
    //reposaito invoca el qevent de tecla 0
    void movimiento_personaje();

private slots:
    void on_boton_Nueva_clicked();
    void on_boton_Multi_clicked();
    void on_boton_Cargar_clicked();
    void on_boton_Eliminar_clicked();
    void on_boton_Ayuda_clicked();
    void on_boton_Salir_clicked();

};


#endif // MAINWINDOW_H
