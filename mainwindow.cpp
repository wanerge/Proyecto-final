#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    mundo1 = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    person = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    mundo1->setSceneRect(0,0,4800,1250);
    mundo1->setBackgroundBrush(QBrush(QImage(":/Imagenes/primer_mapa.png")));
    view->setScene(mundo1);
    view->resize(1366,1000);
    this->setMaximumSize(1366,768);
    this->setMinimumSize(1366,768);
    this->resize(1366,768);
    this->showMaximized();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );
    mun_crash = new QVector <colisiones *>;

    mundo1->addItem(person);

    view->centerOn(person->x(),person->y());

    letra = new char[1];

    *letra = 'S';

    timer1=new QTimer;

    timer1->start(200);

    connect(timer1, &QTimer::timeout, this, &MainWindow::reposaito);

    mapa *mundo_1 = new mapa;
    mundo_1->carga_Datos("../Proyecto_final/info/colisiones1.txt");
    mun_crash = mundo_1->getContenedor();
    delete mundo_1;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if(evento->key() == Qt::Key_A){
        person->ispush=true;
        *letra='A';
        person->filas=70;
        if(person->x() >90){
            person->left();
            for (int i = 0;i < mun_crash->size();i++) {
                if(person->collidesWithItem(mun_crash->at(i))){
                    person->right();
                }
            }
            view->centerOn(person->x(),person->y());
        }
    }
    else if(evento->key() == Qt::Key_D){
        person->ispush=true;
        *letra='D';
        person->filas=105;
        if(person->x() <4750){
            person->right();
            for (int i = 0;i < mun_crash->size();i++) {
                if(person->collidesWithItem(mun_crash->at(i))){
                    person->left();
                }
            }
            view->centerOn(person->x(),person->y());
        }
    }
    else if(evento->key() == Qt::Key_W){
        person->ispush=true;
        *letra='W';
        person->filas=35;
        if(person->y() >50){
            person->up();
            for (int i = 0;i < mun_crash->size();i++) {
                if(person->collidesWithItem(mun_crash->at(i))){
                    person->down();
                }
            }
            view->centerOn(person->x(),person->y());
        }
    }
    else if(evento->key() == Qt::Key_S){
        person->ispush=true;
        *letra='S';
        person->filas=0;
        if(person->y() <900){
            person->down();
            for (int i = 0;i < mun_crash->size();i++) {
                if(person->collidesWithItem(mun_crash->at(i))){
                    person->up();

                }
            }


            view->centerOn(person->x(),person->y());
        }
    }
    else if(evento->key()==Qt::Key_0){
        person->ispush=false;
    }
    else if(evento->key()==Qt::Key_Escape){
        QWidget *wid = new QWidget;
        interfaz_inicio *menu = new interfaz_inicio;
        view->setScene(menu->getScene());
        wid->setLayout(menu->getLay());
        this->setCentralWidget(wid);
    }
}

void MainWindow::reposaito()
{
    keyPressEvent(cero);
}

MainWindow::~MainWindow()
{
    delete ui;
}
