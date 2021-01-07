#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QWidget>
#include "personaje_principal.h"
#include "mapa.h"
#include "interfaz_inicio.h"

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

    void menu();

private:
    Ui::MainWindow *ui;

    QGraphicsView *view;
    interfaz_inicio *inicio;
    QGraphicsScene *ayuda;
    mapa *escenario;

    //se crea personaje principal
    personaje_principal *person;
    QString boton;

    //timer para reposaito
    QTimer *timer1;

    /*
    Creamos un Qkeyevent para poder saber si el jugador esta presionando
    un boton y asi detener las animaciones del sprite en caso de que no se
    oprima nada
    */
    QKeyEvent *cero=new QKeyEvent(QEvent::KeyPress,48,Qt::NoModifier);

public slots:
    //reposaito invoca el qevent de tecla 0
    void reposaito();

private slots:
    void on_boton_Nueva_clicked();
    void on_boton_Multi_clicked();
    void on_boton_Cargar_clicked();
    void on_boton_Eliminar_clicked();
    void on_boton_Ayuda_clicked();
    void on_boton_Salir_clicked();

};


#endif // MAINWINDOW_H
