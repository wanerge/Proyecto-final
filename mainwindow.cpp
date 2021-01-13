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
    if (estado == "new") {
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
            bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 20, 20, 3);
            direccion_disparo();
            escenario->getMundo()->addItem(bullet);
            timer1->stop();
            person->ispush = true;
            person->columnas = person->ancho*4;
            person->max_columnas = 7;
        }
    }
    if(evento->key()==Qt::Key_Escape){
        if (estado == "new") {
            view->resetTransform();
            delete timer1;
            delete vidas;
            delete person;
            delete barra_personaje;
            delete escenario;
            delete Spawner;
        }
        else if(estado == "help"){
            delete ayuda;
        }

        estado = "esc";
        menu();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *evento)
{
    if (estado == "new") {
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
        else if ((evento->key() == Qt::Key_Space) && (!evento->isAutoRepeat())) {
            timer1->start();
        }
    }
}

void MainWindow::direccion_disparo()
{
    if ((letra1 == 'W' && letra2 == 'A') || (letra2 == 'W' && letra1 == 'A')) {
        bullet->setPos(person->x()+12, person->y()-7);
        bullet->filas = 40;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((letra1 == 'W' && letra2 == 'D') || (letra2 == 'W' && letra1 == 'D')) {
        bullet->setPos(person->x()+51, person->y()-7);
        bullet->filas = 20;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((letra1 == 'S' && letra2 == 'A') || (letra2 == 'S' && letra1 == 'A')) {
        bullet->setPos(person->x()+12, person->y()+18);
        bullet->filas = 60;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((letra1 == 'S' && letra2 == 'D') || (letra2 == 'S' && letra1 == 'D')) {
        bullet->setPos(person->x()+51, person->y()+18);
        bullet->filas = 0;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if (letra1 == 'A' || letra2 == 'A') {
        bullet->setPos(person->x(), person->y()+12);
        bullet->filas = 40;
    }
    else if (letra1 == 'D' || letra2 == 'D') {
        bullet->setPos(person->x()+35, person->y()+12);
        bullet->filas = 0;
    }
    else if (letra1 == 'W' || letra2 == 'W') {
        bullet->setPos(person->x()+17, person->y()-5);
        bullet->filas = 20;
    }
    else if (letra1 == 'S' || letra2 == 'S') {
        bullet->setPos(person->x()+12, person->y()+35);
        bullet->filas = 60;
    }
    else if (letra2 == 'a') {
        bullet->setPos(person->x(), person->y()+12);
        bullet->filas = 40;
    }
    else if (letra2 == 'd') {
        bullet->setPos(person->x()+35, person->y()+12);
        bullet->filas = 0;
    }
    else if (letra2 == 'w') {
        bullet->setPos(person->x()+17, person->y()-5);
        bullet->filas = 20;
    }
    else if (letra2 == 's') {
        bullet->setPos(person->x()+12, person->y()+35);
        bullet->filas = 60;
    }
}

void MainWindow::movimiento_personaje()
{
    if ((letra1 == 'W' && letra2 == 'A') || (letra2 == 'W' && letra1 == 'A')) {
        person->velocidad = sqrt(pow(6 ,2)/2);
        colision_up();
        actualizar();
        colision_left();
        actualizar();
    }
    else if ((letra1 == 'W' && letra2 == 'D') || (letra2 == 'W' && letra1 == 'D')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_up();
        actualizar();
        colision_right();
        actualizar();
    }
    else if ((letra1 == 'S' && letra2 == 'A') || (letra2 == 'S' && letra1 == 'A')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_down();
        actualizar();
        colision_left();
        actualizar();
    }
    else if ((letra1 == 'S' && letra2 == 'D') || (letra2 == 'S' && letra1 == 'D')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_down();
        actualizar();
        colision_right();
        actualizar();
    }
    else if (letra1 == 'A' || letra2 == 'A') {
        person->velocidad = 6;
        person->filas = 70;
        colision_left();
        actualizar();
    }
    else if (letra1 == 'D' || letra2 == 'D') {
        person->velocidad = 6;
        person->filas = 105;
        colision_right();
        actualizar();
    }
    else if (letra1 == 'W' || letra2 == 'W') {
        person->velocidad = 6;
        person->filas = 35;
        colision_up();
        actualizar();
    }
    else if (letra1 == 'S' || letra2 == 'S') {
        person->velocidad = 6;
        person->filas = 0;
        colision_down();
        actualizar();
    }
    colision_spawn();
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

void MainWindow::colision_spawn()
{
    if (Spawner->getEnemigos()->isEmpty()) {
        for (int i = 0 ;i < escenario->getZonaspawn()->size();i++) {
            if(person->collidesWithItem(escenario->getZonaspawn()->at(i))){
                Spawner->zona_activa(i);
                for(auto it : *Spawner->getEnemigos()){
                    escenario->getMundo()->addItem(it);
                }
                delete escenario->getZonaspawn()->at(i);
            }
        }
    }
    else {
        for(auto it : *Spawner->getEnemigos()){
            it->seguir(person->x(),person->y());
        }
    }
}

void MainWindow::on_boton_Nueva_clicked()
{
    delete inicio;

    escenario = new mapa(":/Imagenes/primer_mapa.png");

    timer1 = new QTimer;
    person = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    barra_personaje = new QProgressBar;
    vidas = new life(this, 3, 100);

    Spawner = new spawn();

    view->setScene(escenario->getMundo());
    view->scale(1.7,1.4);
    view->centerOn(person->x(),person->y());

    Spawner->carga_Datos(":/info/enemy_info.txt");

    escenario->carga_Datos(":/info/colisiones1.txt","colisiones");
    escenario->carga_Datos(":/info/zonas_spawn.txt","spawners");
    escenario->getMundo()->addItem(person);
    escenario->getMundo()->addWidget(barra_personaje);

    barra_personaje->setMinimum(0);
    barra_personaje->setMaximum(1000);
    barra_personaje->setValue(1000);
    barra_personaje->setMaximumSize(35,10);
    barra_personaje->setGeometry(person->x()+15,person->y()+8, barra_personaje->maximumWidth(), barra_personaje->maximumHeight());
    barra_personaje->setTextVisible(false);

    timer1->start(40);

    connect(timer1, &QTimer::timeout, this, &MainWindow::movimiento_personaje);

    estado = "new";
}

void MainWindow::on_boton_Multi_clicked()
{
    close();
}

void MainWindow::on_boton_Cargar_clicked()
{
    QFile arch;
    QTextStream io;
    QString nombreArch, extension;
    nombreArch = QFileDialog::getOpenFileName(this, "Abrir");
    if (!nombreArch.isEmpty()) {
        for (int i = (nombreArch.length()-1); i > (nombreArch.length()-6)  ; i-- ) {
            extension.push_front(nombreArch[i]);
        }
        if (extension == ".hell") {
            arch.setFileName(nombreArch);
            arch.open(QIODevice::ReadOnly | QIODevice::Text);
            io.setDevice(&arch);
        }
        else {
            QMessageBox::critical(this, "Error", arch.errorString());
        }
        arch.flush();
        arch.close();
    }
}

void MainWindow::on_boton_Eliminar_clicked()
{
    QFile arch;
    QString nombreArch, extension;
    nombreArch = QFileDialog::getOpenFileName(this, "Abrir");
    if (!nombreArch.isEmpty()) {
        arch.setFileName(nombreArch);
        for (int i = (nombreArch.length()-1); i > (nombreArch.length()-6)  ; i-- ) {
            extension.push_front(nombreArch[i]);
        }
        if (extension == ".hell") {
            arch.remove();
        }
        arch.close();
    }
}

void MainWindow::on_boton_Ayuda_clicked()
{
    delete inicio;
    ayuda = new QGraphicsScene;
    ayuda->setSceneRect(0,0,1366,768);
    ayuda->setBackgroundBrush(QBrush(QImage(":/Imagenes/ayuda.png")));
    view->setScene(ayuda);

    estado = "help";
}

void MainWindow::on_boton_Salir_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
