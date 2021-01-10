#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    view = new QGraphicsView(this);

    this->window()->showFullScreen();
    if (this->width() <= 1366 && this->height() <= 768) {
        //this->showFullScreen();
        this->showMaximized();
    }
    else {
        this->setMaximumSize(1366,768);
        this->setMinimumSize(1366,768);
        this->showMaximized();
    }

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
            if(!evento->isAutoRepeat()){
                letra2 = letra1;
                letra1 = 'A';
            }
        }
        else if(evento->key() == Qt::Key_D){
            if(!evento->isAutoRepeat()){
                letra2 = letra1;
                letra1 = 'D';
            }
        }
        else if(evento->key() == Qt::Key_W){
            if(!evento->isAutoRepeat()){
                letra2 = letra1;
                letra1 = 'W';
            }
        }
        else if(evento->key() == Qt::Key_S){
            if(!evento->isAutoRepeat()){
                letra2 = letra1;
                letra1 = 'S';
            }
        }
        else if ((evento->key() == Qt::Key_Space) && (!evento->isAutoRepeat())) {
            //barra_personaje->setValue(barra_personaje->value()-10);
            bullets *bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 50, 50, 3);
            if ((letra1 == 'A') || (letra2 == 'a')) {
                bullet->filas = 100;
            }
            else if ((letra1 == 'D') || (letra2 == 'd')) {
                bullet->filas = 0;
            }
            else if ((letra1 == 'W') || (letra2 == 'w')) {
                bullet->filas = 50;
            }
            else if ((letra1 == 'S') || (letra2 == 's')) {
                bullet->filas = 150;
            }
            escenario->getMundo()->addItem(bullet);
            bullet->setPos(person->x(), person->y());
        }
    }
    if(evento->key()==Qt::Key_Escape){
        if (boton == "new") {
            delete timer1;
            delete person;
            delete barra_personaje;
            delete escenario;       
        }
        else if(boton == "help"){
            delete ayuda;
        }
        boton = "esc";
        menu();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *evento)
{
    if (boton == "new") {
        if(evento->key() == Qt::Key_A && !evento->isAutoRepeat()){
            if (letra1 == 'A') {
                letra1 = letra2;
                letra2 = 'a';
            }
            else {
                letra2 = 'a';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_D && !evento->isAutoRepeat()){
            if (letra1 == 'D') {
                letra1 = letra2;
                letra2 = 'd';
            }
            else {
                letra2 = 'd';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_W && !evento->isAutoRepeat()){
            if (letra1 == 'W') {
                letra1 = letra2;
                letra2 = 'w';
            }
            else {
                letra2 = 'w';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_S && !evento->isAutoRepeat()){
            if (letra1 == 'S') {
                letra1 = letra2;
                letra2 = 's';
            }
            else {
                letra2 = 's';
            }
            person->ispush=false;
        }
    }
}

void MainWindow::movimiento_personaje()
{
    if ((letra1 == 'W' && letra2 == 'A') || (letra2 == 'W' && letra1 == 'A')) {
        colision_up();
        actualizar();
        colision_left();
        actualizar();
    }
    else if ((letra1 == 'W' && letra2 == 'D') || (letra2 == 'W' && letra1 == 'D')) {
        colision_up();
        actualizar();
        colision_right();
        actualizar();
    }
    else if ((letra1 == 'S' && letra2 == 'A') || (letra2 == 'S' && letra1 == 'A')) {
        colision_down();
        actualizar();
        colision_left();
        actualizar();
    }
    else if ((letra1 == 'S' && letra2 == 'D') || (letra2 == 'S' && letra1 == 'D')) {
        colision_down();
        actualizar();
        colision_right();
        actualizar();
    }
    else if (letra1 == 'A' || letra2 == 'A') {
        person->filas = 70;
        colision_left();
        actualizar();
    }
    else if (letra1 == 'D' || letra2 == 'D') {
        person->filas = 105;
        colision_right();
        actualizar();
    }
    else if (letra1 == 'W' || letra2 == 'W') {
        person->filas = 35;
        colision_up();
        actualizar();
    }
    else if (letra1 == 'S' || letra2 == 'S') {
        person->filas = 0;
        colision_down();
        actualizar();
    }
}

void MainWindow::actualizar()
{
    view->centerOn(person);
    barra_personaje->setGeometry(person->x()+15,person->y()+8, barra_personaje->maximumWidth(), barra_personaje->maximumHeight());
}

void MainWindow::colision_up()
{
    person->up();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->down();
        }
    }
}

void MainWindow::colision_down()
{
    person->down();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->up();
        }
    }
}

void MainWindow::colision_left()
{
    person->left();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->right();
        }
    }
}

void MainWindow::colision_right()
{
    person->right();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->left();
        }
    }
}

void MainWindow::on_boton_Nueva_clicked()
{
    delete inicio;

    timer1 = new QTimer;
    person = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    barra_personaje = new QProgressBar;
    escenario = new mapa(":/Imagenes/primer_mapa.png");

    escenario->carga_Datos(":/info/colisiones1.txt");

    view->setScene(escenario->getMundo());
    escenario->getMundo()->addItem(person);
    view->centerOn(person->x(),person->y());
    escenario->getMundo()->addWidget(barra_personaje);

    barra_personaje->setMinimum(0);
    barra_personaje->setMaximum(1000);
    barra_personaje->setValue(1000);
    barra_personaje->setMaximumSize(35,10);
    barra_personaje->setGeometry(person->x()+15,person->y()+8, barra_personaje->maximumWidth(), barra_personaje->maximumHeight());
    barra_personaje->setTextVisible(false);

    timer1->start(40);

    connect(timer1, &QTimer::timeout, this, &MainWindow::movimiento_personaje);

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

MainWindow::~MainWindow()
{
    delete ui;
}
