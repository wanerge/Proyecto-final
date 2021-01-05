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
#include "colisiones.h"
#include "interfaz_inicio.h"
#include "button.h"
#include "mapa.h"

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

//    template<typename T>
//    //leer datos de archivo
//    void cargar_datos(QString nombre_archivo, T *contenedor,int mundo);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *inicio;
    QGraphicsScene *mundo1;
    QGraphicsView *view;
    QGraphicsScene *mundo2 =new QGraphicsScene(this);

    mapa *mundo_1;

    //se crea personaje principal
    personaje_principal *person;
    int mundo=1;
    char *letra;

    //timer para reposaito
    QTimer *timer1;


    /*
    Creamos un Qkeyevent para poder saber si el jugador esta presionando
    un boton y asi detener las animaciones del sprite en caso de que no se
    oprima nada
    */
    QKeyEvent *cero=new QKeyEvent(QEvent::KeyPress,48,Qt::NoModifier);

    QVector<colisiones *> *mun_crash;

public slots:
    //reposaito invoca el qevent de tecla 0
    void reposaito();

};


#endif // MAINWINDOW_H
