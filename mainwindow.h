#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "bolita.h"
#include <QKeyEvent>
#include "personaje_principal.h"
#include <QTimer>
#include "colisiones.h"
#include "interfaz_inicio.h"
#include "button.h"
#include <QWidget>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    //Funcion de keypreesevent que detecta las teclas presionadas
    void keyPressEvent(QKeyEvent *evento);
      QVector<colisiones *> *mun_crash;
      template<typename T>
      //leer datos de archivo
      void cargar_datos(QString nombre_archivo, T *contenedor,int mundo);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *inicio;
    QGraphicsScene *mundo1;
    QGraphicsView *view;
    QGraphicsScene *mundo1 =new QGraphicsScene(this);
    QGraphicsScene *mundo2 =new QGraphicsScene(this);
    QPixmap *imgportada;
    //bolita *person;
    int valor1=650,valor2=350;

    //se crea personaje principal
    personaje_principal *person;
    int mundo=1;
    char *letra;

    //timer para reposaito
    QTimer *timer1;


    //Creamos un Qkeyevent para poder saber si el jugador esta presionando
    //un boton y asi detener las animaciones del sprite en caso de que no se
    //oprima nada
    QKeyEvent *cero=new QKeyEvent(QEvent::KeyPress,48,Qt::NoModifier);
public slots:
    //reposaito invoca el qevent de tecla 0
    void reposaito();

};


#endif // MAINWINDOW_H
