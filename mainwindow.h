#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QWidget>
#include <math.h>
#include <QFileDialog>
#include <QMessageBox>
#include "personaje_principal.h"
#include "mapa.h"
#include "interfaz_inicio.h"
#include "interfaz_pausa.h"
#include "bullets.h"
#include "colisiones.h"
#include "life.h"
#include "spawn.h"
#include "bullets_enemy.h"
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
    void direccion_disparo(personaje_principal *person);

    //funciones para el movimiento del personaje
    void movimiento_personaje(personaje_principal *person);
    void actualizar(personaje_principal *person);
    void colision_up(personaje_principal *person);
    void colision_down(personaje_principal *person);
    void colision_left(personaje_principal *person);
    void colision_right(personaje_principal *person);
    void colision_spawn(personaje_principal *person);
    void key_press(personaje_principal *person, QTimer *time, QKeyEvent *evento);
    void key_release(personaje_principal *person, QTimer *time, QKeyEvent *evento);    
    void reinicio_muerte(personaje_principal *person, life *vidas, QTimer *time);

    //carga el menu principal
    void menu();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    interfaz_inicio *inicio;
    interfaz_pausa *pausa;
    QGraphicsScene *ayuda;
    mapa *escenario;
    QString estado;

    //se crea personaje principal
    bool personaje_pri, personaje_seg;
    personaje_principal *personaje1, *personaje2;
    life *vidas1, *vidas2;
    bullets *bullet;

    //Spawn de enemigos
    spawn *Spawner;

    QTimer *timer1, *timer2, *timer3;

public slots:
    //reposaito invoca el qevent de tecla 0
    void personajes_activos();

    //funciones para el disparo basico de los enemigos
    void generar_disparo();

private slots:
    void on_boton_Nueva_clicked();
    void on_boton_Facil_clicked();
    void on_boton_Dificil_clicked();
    void on_boton_Multi_clicked();
    void on_boton_Cargar_clicked();
    void on_boton_Eliminar_clicked();
    void on_boton_Ayuda_clicked();
    void on_boton_Salir_clicked();

    void on_boton_Guardar_clicked();
    void on_boton_Reiniciar_clicked();
    void on_boton_Menu_clicked();
};


#endif // MAINWINDOW_H
