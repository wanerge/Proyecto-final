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
    if (estado == "easy" || estado == "hard" || estado == "multi") {
        if (personaje_pri) {
            key_press(personaje1,timer1,evento);
        }
        if (personaje_seg) {
            key_press(personaje2,timer2,evento);
        }
    }
    if(evento->key()==Qt::Key_Escape){
        if (estado == "new") {
            inicio->modo_menu();
        }
        else if (estado == "hard" || estado == "easy") {
            view->resetTransform();
            delete timer1;
            delete vidas;
            delete personaje1;
            delete escenario;
            delete Spawner;
        }
        else if (estado == "multi") {
            view->resetTransform();
            delete timer1;
            delete timer2;
            delete vidas;
            delete personaje1;
            delete personaje2;
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
    if (estado == "easy" || estado == "hard" || estado == "multi") {
        if (personaje_pri) {
            key_release(personaje1, timer1, evento);
        }
        if (personaje_seg) {
            key_release(personaje2, timer2, evento);
        }
    }
}

void MainWindow::key_press(personaje_principal *person, QTimer *time, QKeyEvent *evento)
{
    if (person == personaje1) {
        if(evento->key() == Qt::Key_A){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'A';
            }
        }
        else if(evento->key() == Qt::Key_D){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'D';
            }
        }
        else if(evento->key() == Qt::Key_W){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'W';
            }
        }
        else if(evento->key() == Qt::Key_S){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'S';
            }
        }
        else if ((evento->key() == Qt::Key_Space) && (!evento->isAutoRepeat())) {
            bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 20, 20, 3, Spawner->getEnemigos());
            direccion_disparo(person);
            escenario->getMundo()->addItem(bullet);
            time->stop();
            person->ispush = true;
            person->columnas = person->ancho*4;
            person->max_columnas = 7;
        }
    }
    else if (person == personaje2){
        if(evento->key() == Qt::Key_J){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'A';
            }
        }
        else if(evento->key() == Qt::Key_L){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'D';
            }
        }
        else if(evento->key() == Qt::Key_I){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'W';
            }
        }
        else if(evento->key() == Qt::Key_K){
            if(!evento->isAutoRepeat()){
                person->letra2 = person->letra1;
                person->letra1 = 'S';
            }
        }
        else if ((evento->key() == Qt::Key_P) && (!evento->isAutoRepeat())) {
            bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 20, 20, 3, Spawner->getEnemigos());
            direccion_disparo(person);
            escenario->getMundo()->addItem(bullet);
            time->stop();
            person->ispush = true;
            person->columnas = person->ancho*4;
            person->max_columnas = 7;
        }
    }
}

void MainWindow::key_release(personaje_principal *person, QTimer *time, QKeyEvent *evento)
{
    if (person == personaje1) {
        if(evento->key() == Qt::Key_A && !evento->isAutoRepeat()){
            if (person->letra1 == 'A') {
                person->letra1 = person->letra2;
                person->letra2 = 'a';
            }
            else {
                person->letra2 = 'a';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_D && !evento->isAutoRepeat()){
            if (person->letra1 == 'D') {
                person->letra1 = person->letra2;
                person->letra2 = 'd';
            }
            else {
                person->letra2 = 'd';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_W && !evento->isAutoRepeat()){
            if (person->letra1 == 'W') {
                person->letra1 = person->letra2;
                person->letra2 = 'w';
            }
            else {
                person->letra2 = 'w';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_S && !evento->isAutoRepeat()){
            if (person->letra1 == 'S') {
                person->letra1 = person->letra2;
                person->letra2 = 's';
            }
            else {
                person->letra2 = 's';
            }
            person->ispush=false;
        }
        else if ((evento->key() == Qt::Key_Space) && (!evento->isAutoRepeat())) {
            time->start();
        }
    }
    else  if (person == personaje2){
        if(evento->key() == Qt::Key_J && !evento->isAutoRepeat()){
            if (person->letra1 == 'A') {
                person->letra1 = person->letra2;
                person->letra2 = 'a';
            }
            else {
                person->letra2 = 'a';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_L && !evento->isAutoRepeat()){
            if (person->letra1 == 'D') {
                person->letra1 = person->letra2;
                person->letra2 = 'd';
            }
            else {
                person->letra2 = 'd';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_I && !evento->isAutoRepeat()){
            if (person->letra1 == 'W') {
                person->letra1 = person->letra2;
                person->letra2 = 'w';
            }
            else {
                person->letra2 = 'w';
            }
            person->ispush=false;
        }
        else if(evento->key() == Qt::Key_K && !evento->isAutoRepeat()){
            if (person->letra1 == 'S') {
                person->letra1 = person->letra2;
                person->letra2 = 's';
            }
            else {
                person->letra2 = 's';
            }
            person->ispush=false;
        }
        else if ((evento->key() == Qt::Key_P) && (!evento->isAutoRepeat())) {
            time->start();
        }
    }
}

void MainWindow::direccion_disparo(personaje_principal *person)
{
    if ((person->letra1 == 'W' && person->letra2 == 'A') || (person->letra2 == 'W' && person->letra1 == 'A')) {
        bullet->setPos(person->x()+12, person->y()-7);
        bullet->filas = 40;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((person->letra1 == 'W' && person->letra2 == 'D') || (person->letra2 == 'W' && person->letra1 == 'D')) {
        bullet->setPos(person->x()+51, person->y()-7);
        bullet->filas = 20;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((person->letra1 == 'S' && person->letra2 == 'A') || (person->letra2 == 'S' && person->letra1 == 'A')) {
        bullet->setPos(person->x()+12, person->y()+18);
        bullet->filas = 60;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if ((person->letra1 == 'S' && person->letra2 == 'D') || (person->letra2 == 'S' && person->letra1 == 'D')) {
        bullet->setPos(person->x()+51, person->y()+18);
        bullet->filas = 0;
        bullet->setRotation(45);
        bullet->diagonal = true;
        bullet->velocidad = sqrt(pow(bullet->velocidad,2)/2);
    }
    else if (person->letra1 == 'A' || person->letra2 == 'A') {
        bullet->setPos(person->x(), person->y()+12);
        bullet->filas = 40;
    }
    else if (person->letra1 == 'D' || person->letra2 == 'D') {
        bullet->setPos(person->x()+35, person->y()+12);
        bullet->filas = 0;
    }
    else if (person->letra1 == 'W' || person->letra2 == 'W') {
        bullet->setPos(person->x()+17, person->y()-5);
        bullet->filas = 20;
    }
    else if (person->letra1 == 'S' || person->letra2 == 'S') {
        bullet->setPos(person->x()+12, person->y()+35);
        bullet->filas = 60;
    }
    else if (person->letra2 == 'a') {
        bullet->setPos(person->x(), person->y()+12);
        bullet->filas = 40;
    }
    else if (person->letra2 == 'd') {
        bullet->setPos(person->x()+35, person->y()+12);
        bullet->filas = 0;
    }
    else if (person->letra2 == 'w') {
        bullet->setPos(person->x()+17, person->y()-5);
        bullet->filas = 20;
    }
    else if (person->letra2 == 's') {
        bullet->setPos(person->x()+12, person->y()+35);
        bullet->filas = 60;
    }
}

void MainWindow::personajes_activos()
{
    if (personaje_pri) {
        movimiento_personaje(personaje1);
    }
    if (personaje_seg) {
        movimiento_personaje(personaje2);
    }
}

void MainWindow::movimiento_personaje(personaje_principal *person)
{
    if ((person->letra1 == 'W' && person->letra2 == 'A') || (person->letra2 == 'W' && person->letra1 == 'A')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_up(person);
        actualizar(person);
        colision_left(person);
        actualizar(person);
    }
    else if ((person->letra1 == 'W' && person->letra2 == 'D') || (person->letra2 == 'W' && person->letra1 == 'D')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_up(person);
        actualizar(person);
        colision_right(person);
        actualizar(person);
    }
    else if ((person->letra1 == 'S' && person->letra2 == 'A') || (person->letra2 == 'S' && person->letra1 == 'A')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_down(person);
        actualizar(person);
        colision_left(person);
        actualizar(person);
    }
    else if ((person->letra1 == 'S' && person->letra2 == 'D') || (person->letra2 == 'S' && person->letra1 == 'D')) {
        person->velocidad = sqrt(pow(6, 2)/2);
        colision_down(person);
        actualizar(person);
        colision_right(person);
        actualizar(person);
    }
    else if (person->letra1 == 'A' || person->letra2 == 'A') {
        person->velocidad = 6;
        person->filas = 70;
        colision_left(person);
        actualizar(person);
    }
    else if (person->letra1 == 'D' || person->letra2 == 'D') {
        person->velocidad = 6;
        person->filas = 105;
        colision_right(person);
        actualizar(person);
    }
    else if (person->letra1 == 'W' || person->letra2 == 'W') {
        person->velocidad = 6;
        person->filas = 35;
        colision_up(person);
        actualizar(person);
    }
    else if (person->letra1 == 'S' || person->letra2 == 'S') {
        person->velocidad = 6;
        person->filas = 0;
        colision_down(person);
        actualizar(person);
    }
    colision_spawn(person);
}

void MainWindow::actualizar(personaje_principal *person)
{
    if (person == personaje1) {
        view->centerOn(person);
    }
    person->barra_personaje->move(person->x()+15,person->y()+8);
}

void MainWindow::colision_up(personaje_principal *person)
{
    person->up();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->down();
        }
    }
    for (int i = 0;i < escenario->getZona_blocked()->size();i++) {
        if(person->collidesWithItem(escenario->getZona_blocked()->at(i))){
            person->down();
        }
    }
}

void MainWindow::colision_down(personaje_principal *person)
{
    person->down();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->up();
        }
    }
    for (int i = 0;i < escenario->getZona_blocked()->size();i++) {
        if(person->collidesWithItem(escenario->getZona_blocked()->at(i))){
            person->up();
        }
    }
}

void MainWindow::colision_left(personaje_principal *person)
{
    person->left();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->right();
        }
    }
    for (int i = 0;i < escenario->getZona_blocked()->size();i++) {
        if(person->collidesWithItem(escenario->getZona_blocked()->at(i))){
            person->right();
        }
    }


}

void MainWindow::colision_right(personaje_principal *person)
{
    person->right();
    for (int i = 0;i < escenario->getContenedor()->size();i++) {
        if(person->collidesWithItem(escenario->getContenedor()->at(i))){
            person->left();
        }
    }
    for (int i = 0;i < escenario->getZona_blocked()->size();i++) {
        if(person->collidesWithItem(escenario->getZona_blocked()->at(i))){
            person->left();
        }
    }
}

void MainWindow::colision_spawn(personaje_principal *person)
{
    if (Spawner->getEnemigos()->isEmpty()) {
        if(Spawner->activo){
            //escenario->getMundo()->removeItem(escenario->getZona_blocked()->back());
            escenario->getZona_blocked()->pop_back();
            Spawner->activo=false;
        }
        for (int i = 0 ;i < escenario->getZonaspawn()->size();i++) {
            if(person->collidesWithItem(escenario->getZonaspawn()->at(i))){
                Spawner->zona_activa(i);
                for(auto it : *Spawner->getEnemigos()){
                    escenario->getMundo()->addItem(it);
                }
                //escenario->getZonaspawn()->removeAt(i);
            }
        }
    }
    else {
        for(auto it : *Spawner->getEnemigos()){
            if (it->collidesWithItem(person)) {
                person->velocidad = 4;
                if (person->x()-it->x() < 15 and person->x()-it->x() > -15 ) {
                    if (person->x() > it->x()) {
                        colision_right(person);
                    }
                    else {
                        colision_left(person);
                    }
                    actualizar(person);
                    person->vida -= 8;
                    person->barra_personaje->setValue(person->vida);
                }
                else {
                    for (auto itt : *Spawner->getEnemigos()) {
                        if (person->x() > it->x()) {
                            if (itt != it) {
                                if (it->collidesWithItem(itt)){
                                    itt->seguir(itt->x(), itt->y());
                                }
                            }
                            it->seguir(person->x()+20,person->y());
                        }
                        else if (it->x() > person->x()){
                            if (itt != it) {
                                if (it->collidesWithItem(itt)){
                                    itt->seguir(itt->x(), itt->y());
                                }
                            }
                            it->seguir(person->x()-20,person->y());
                        }
                    }
                }
            }
            else {
                for (auto itt : *Spawner->getEnemigos()) {
                    if (itt != it) {
                        if (it->collidesWithItem(itt)){
                            itt->seguir(itt->x(), itt->y());
                        }
                    }
                }
                it->seguir(person->x(),person->y());
            }
        }
    }
}

void MainWindow::on_boton_Nueva_clicked()
{
    inicio->modo_dificultad();
    connect(inicio->getBoton_Facil(), &QPushButton::clicked , this, &MainWindow::on_boton_Facil_clicked);
    connect(inicio->getBoton_Dificil(), &QPushButton::clicked , this, &MainWindow::on_boton_Dificil_clicked);
    estado = "new";
}

void MainWindow::on_boton_Facil_clicked()
{
    delete inicio;

    escenario = new mapa(":/Imagenes/primer_mapa.png");

    timer1 = new QTimer;
    personaje1 = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    vidas = new life(this, 3, 100);

    Spawner = new spawn();

    view->setScene(escenario->getMundo());
    view->scale(1.7,1.4);
    view->centerOn(personaje1->x(), personaje1->y());

    Spawner->carga_Datos(":/info/enemy_info.txt");

    escenario->carga_Datos(":/info/colisiones1.txt", escenario->getContenedor());
    escenario->carga_Datos(":/info/zonas_spawn.txt", escenario->getZonaspawn());
    escenario->carga_Datos(":/info/zona_bloqueada1.txt",escenario->getZona_blocked());
    escenario->getMundo()->addItem(personaje1);
    escenario->getMundo()->addWidget(personaje1->barra_personaje);

    timer1->start(40);

    connect(timer1, &QTimer::timeout, this, &MainWindow::personajes_activos);
    personaje_pri = true;
    personaje_seg = false;

    estado = "easy";
}

void MainWindow::on_boton_Dificil_clicked()
{
    delete inicio;

    escenario = new mapa(":/Imagenes/primer_mapa.png");

    timer1 = new QTimer;
    personaje1 = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);
    vidas = new life(this, 3, 100);

    Spawner = new spawn();

    view->setScene(escenario->getMundo());
    view->scale(1.7,1.4);
    view->centerOn(personaje1->x(), personaje1->y());

    Spawner->carga_Datos(":/info/enemy_info.txt");

    escenario->carga_Datos(":/info/colisiones1.txt", escenario->getContenedor());
    escenario->carga_Datos(":/info/zonas_spawn.txt", escenario->getZonaspawn());
    escenario->getMundo()->addItem(personaje1);
    escenario->getMundo()->addWidget(personaje1->barra_personaje);

    timer1->start(40);

    connect(timer1, &QTimer::timeout, this, &MainWindow::personajes_activos);
    personaje_pri = true;
    personaje_seg = false;

    estado = "hard";
}

void MainWindow::on_boton_Multi_clicked()
{
    on_boton_Dificil_clicked();

    personaje_seg = true;

    timer2 = new QTimer;
    personaje2 = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0);

    escenario->getMundo()->addItem(personaje2);
    escenario->getMundo()->addWidget(personaje2->barra_personaje);

    timer2->start(70);

    connect(timer2, &QTimer::timeout, this, &MainWindow::personajes_activos);

    personaje2->setPos(370, 740);
    actualizar(personaje2);

    estado = "multi";
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
