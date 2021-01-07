#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    view = new QGraphicsView(this);
    timer1 = new QTimer;

    this->setMaximumSize(1366,768);
    this->setMinimumSize(1366,768);
    this->resize(1366,768);
    this->showMaximized();

    view->resize(1366,1000);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menu();
}

void MainWindow::menu()
{
    inicio = new interfaz_inicio;

    view->setAlignment(Qt::AlignmentFlag::AlignTop);
    view->setScene(inicio->getScene());

    this->setCentralWidget(inicio->getWid());

    connect(inicio->getBoton_Nueva(), &QPushButton::clicked , this, &MainWindow::on_boton_Nueva_clicked);
    connect(inicio->getBoton_Multijugador(), &QPushButton::clicked , this, &MainWindow::on_boton_Multi_clicked);
    connect(inicio->getBoton_Cargar(), &QPushButton::clicked , this, &MainWindow::on_boton_Cargar_clicked);
    connect(inicio->getBoton_Eliminar(), &QPushButton::clicked , this, &MainWindow::on_boton_Eliminar_clicked);
    connect(inicio->getBoton_Ayuda(), &QPushButton::clicked , this, &MainWindow::on_boton_Ayuda_clicked);
    connect(inicio->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Salir_clicked);
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if (boton == "new") {
        if(evento->key() == Qt::Key_A){
            person->ispush=true;
            person->filas=70;
            if(person->x() >90){
                person->left();
                for (int i = 0;i < escenario->getContenedor()->size();i++) {
                    if(person->collidesWithItem(escenario->getContenedor()->at(i))){
                        person->right();
                    }
                }
                view->centerOn(person->x(),person->y());
            }
        }
        else if(evento->key() == Qt::Key_D){
            person->ispush=true;
            person->filas=105;
            if(person->x() <4750){
                person->right();
                for (int i = 0;i < escenario->getContenedor()->size();i++) {
                    if(person->collidesWithItem(escenario->getContenedor()->at(i))){
                        person->left();
                    }
                }
                view->centerOn(person->x(),person->y());
            }
        }
        else if(evento->key() == Qt::Key_W){
            person->ispush=true;
            person->filas=35;
            if(person->y() >50){
                person->up();
                for (int i = 0;i < escenario->getContenedor()->size();i++) {
                    if(person->collidesWithItem(escenario->getContenedor()->at(i))){
                        person->down();
                    }
                }
                view->centerOn(person->x(),person->y());
            }
        }
        else if(evento->key() == Qt::Key_S){
            person->ispush=true;
            person->filas=0;
            if(person->y() <900){
                person->down();
                for (int i = 0;i < escenario->getContenedor()->size();i++) {
                    if(person->collidesWithItem(escenario->getContenedor()->at(i))){
                        person->up();
                    }
                }
                view->centerOn(person->x(),person->y());
            }
        }
        else if(evento->key()==Qt::Key_0){
            person->ispush=false;
        }
    }
    if(evento->key()==Qt::Key_Escape){
        if (boton == "new") {
            delete person;
            delete escenario;
        }
        else if(boton == "help"){
            delete ayuda;
        }
        boton = "esc";
        timer1->stop();
        menu();
    }
}

void MainWindow::on_boton_Nueva_clicked()
{
    delete inicio;

    person = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    escenario = new mapa(":/Imagenes/primer_mapa.png");

    escenario->carga_Datos("../Proyecto_final/info/colisiones1.txt");

    view->setScene(escenario->getMundo());
    escenario->getMundo()->addItem(person);
    view->centerOn(person->x(),person->y());

    timer1->start(200);

    connect(timer1, &QTimer::timeout, this, &MainWindow::reposaito);

    boton = "new";
}

void MainWindow::on_boton_Multi_clicked()
{
    close();
}

void MainWindow::on_boton_Cargar_clicked()
{
    close();
}

void MainWindow::on_boton_Eliminar_clicked()
{
    close();
}

void MainWindow::on_boton_Ayuda_clicked()
{
    delete inicio;
    ayuda = new QGraphicsScene;
    ayuda->setSceneRect(0,0,1366,768);
    ayuda->setBackgroundBrush(QBrush(QImage(":/Imagenes/ayuda.png")));
    view->setScene(ayuda);

    boton = "help";
}

void MainWindow::on_boton_Salir_clicked()
{
    close();
}

void MainWindow::reposaito()
{
    keyPressEvent(cero);
}

MainWindow::~MainWindow()
{
    delete ui;
}
