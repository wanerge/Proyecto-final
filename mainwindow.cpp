#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    mundo1->setSceneRect(0,0,4800,1250);
    person = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    mundo1->setBackgroundBrush(QBrush(QImage(":/Imagenes/primer_mapa.png")));
    view->setScene(mundo1);
    view->resize(1200,1000);
    this->resize(1200,1000);
    //person=new bolita(20,140,120);
    mundo1->addItem(person);
    view->centerOn(person->x(),person->y());
    letra = new char[1];
    *letra = 'S';
    timer1=new QTimer;
    timer1->start(200);
    connect(timer1, &QTimer::timeout, this, &MainWindow::reposaito);


    //colisones mundo 1
    //Seran puestas en un archivo txt
    //estaran aqui temporalmente
    mun1_crash.push_back(new colisiones(20,20,-140,-115));mundo1->addItem(mun1_crash.back());
}
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
//    if(evento->isAutoRepeat()==false){
//        person->continua();
//        timer1->stop();
//        timer1->start(600);
//    }

    if(evento->key() == Qt::Key_A){

        //person->continua();
        person->ispush=true;
        *letra='A';
        person->filas=70;
        //*presionando=true;
        if(person->x() >90){
            if(person->collidesWithItem(mun1_crash.back())){
                person->right();
            }
        person->left();
        view->centerOn(person->x(),person->y());
        }

//        valor1=person->x();

//        if(valor1>0){
//            mundo1->setSceneRect(valor1-mundo1->width()/2,valor2-mundo1->height()/2,mundo1->width(),mundo1->height());
//        }

    }

    else if(evento->key() == Qt::Key_D){
        person->ispush=true;
        //person->continua();
        *letra='D';

        person->filas=105;
        if(person->x() <4750){
        person->right();
        view->centerOn(person->x(),person->y());
        }

//        valor1=person->x();
//        if(valor1<4800){
//            mundo1->setSceneRect(valor1-mundo1->width()/2,valor2-mundo1->height()/2,mundo1->width(),mundo1->height());
//        }


    }
    else if(evento->key() == Qt::Key_W){
        person->ispush=true;
        //person->continua();
        *letra='W';
        person->filas=35;
        if(person->y() >70){
            if(person->collidesWithItem(mun1_crash.back())){
                person->down();
            }
        person->up();
        view->centerOn(person->x(),person->y());
        }
//        valor2=person->y();
//        if(valor2>0){
//            mundo1->setSceneRect(valor1-mundo1->width()/2,valor2-mundo1->height()/2,mundo1->width(),mundo1->height());
//        }
    }

    else if(evento->key() == Qt::Key_S){
        person->ispush=true;
        //person->continua();
        *letra='S';
       // *presionando=true;
        person->filas=0;
        if(person->y() <900){
        person->down();

        view->centerOn(person->x(),person->y());
        }

//        valor2=person->y();
//        if(valor2<1000){
//            mundo1->setSceneRect(valor1-mundo1->width()/2,valor2-mundo1->height()/2,mundo1->width(),mundo1->height());
//        }
        }
    else if(evento->key()==Qt::Key_0){
        person->ispush=false;
    }
    else{
    }
    }
void MainWindow::reposaito()
{
//    person->pausa();
//    if(* letra == 'A'){
//        person->filas=120;
//        person->columnas=240;
//    }
//    else if(*letra =='S'){
//        person->filas=0;
//        person->columnas=240;
//    }
//    else if(*letra =='D'){
//        person->filas=180;
//        person->columnas=240;
//    }
//    else if(*letra =='W'){
//        person->filas=60;
//        person->columnas=240;
//    }
    keyPressEvent(cero);
    }
MainWindow::~MainWindow()
{
    delete ui;
}



