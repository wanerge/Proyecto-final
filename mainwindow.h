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
#include "powerboss.h"
#include "transiciones.h"
#include "load_and_save.h"
#include "zonas_especiales.h"
#include "sonidos.h"
#include "puntaje.h"
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

    //funciones para el movimiento del disparo del personaje
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
    //funcion para actualizar el personaje cuando muere
    void reinicio_muerte(personaje_principal *person, life *vidas, QTimer *time);

    //carga el menu principal
    void menu();

    //carga el primer mundo
    void cargar_mundo1();
    //carga el segundo mundo
    void cargar_mundo2();

    void cargar_personajes(int persona, float pos_x, float pos_y, int vida_total, int num_vidas, int milisegundos);

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    interfaz_inicio *inicio;
    interfaz_pausa *pausa;
    QGraphicsScene *ayuda;
    mapa *escenario;
    zonas_especiales *zonas_jefes;
    QString estado;
    int mundo;
    bool crear_personaje;

    //variables para la creacion de personajes
    bool personaje_pri, personaje_seg;
    personaje_principal *personaje1, *personaje2;
    life *vidas1, *vidas2;
    bullets *bullet;
    QVector<personaje_principal *> personajes;

    //Spawn de enemigos
    spawn *Spawner;
    QTimer *timer1, *timer2, *timer3;

    //puntaje del jugador
    puntaje *cuadro_puntos;
    int *puntos;

    transiciones *transicion;
    load_and_save *datos_almacenados;
    sonidos *sonidoefecto;


public slots:
    //reposaito invoca el qevent de tecla 0
    void personajes_activos();

    //funciones para el disparo basico de los enemigos
    void generar_disparo();

    //funcion para ver una pequeña transicion del primer mundo al segundo
    void cambiar_mundo();

    //muestra una imagen cuando gana el juego y luego vuelve al menu
    void imagen_final();

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
