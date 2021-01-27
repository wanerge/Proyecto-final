#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("PixHell");
    QIcon icon = this->windowIcon();
    icon.addFile(":/Imagenes/Doom.png");
    this->setWindowIcon(icon);

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

    sonidoefecto = new sonidos();

    menu();


}

void MainWindow::menu()
{   
    inicio = new interfaz_inicio;
    mundo = 1;
    crear_personaje = true;

    view->setAlignment(Qt::AlignmentFlag::AlignTop);
    view->setScene(inicio->getScene());
    this->setCentralWidget(inicio->getWid());

    connect(inicio->getBoton_Nueva(), &QPushButton::clicked , this, &MainWindow::on_boton_Nueva_clicked);
    connect(inicio->getBoton_Multijugador(), &QPushButton::clicked , this, &MainWindow::on_boton_Multi_clicked);
    connect(inicio->getBoton_Cargar(), &QPushButton::clicked , this, &MainWindow::on_boton_Cargar_clicked);
    connect(inicio->getBoton_Eliminar(), &QPushButton::clicked , this, &MainWindow::on_boton_Eliminar_clicked);
    connect(inicio->getBoton_Ayuda(), &QPushButton::clicked , this, &MainWindow::on_boton_Ayuda_clicked);
    connect(inicio->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Salir_clicked);

    estado = "menu";
    sonidoefecto->sonidosfondo("menu");

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
        if (estado == "pause_N_easy"){
            delete pausa;
            estado = "easy";
        }
        else if (estado == "pause_N_hard") {
            delete pausa;
            estado = "hard";
        }
        else if (estado == "pause_M") {
            delete pausa;
            estado = "multi";
        }
        else if (estado == "new") {
            inicio->modo_menu();
            estado = "esc";
            connect(inicio->getBoton_Nueva(), &QPushButton::clicked , this, &MainWindow::on_boton_Nueva_clicked);
            connect(inicio->getBoton_Multijugador(), &QPushButton::clicked , this, &MainWindow::on_boton_Multi_clicked);
            connect(inicio->getBoton_Cargar(), &QPushButton::clicked , this, &MainWindow::on_boton_Cargar_clicked);
            connect(inicio->getBoton_Eliminar(), &QPushButton::clicked , this, &MainWindow::on_boton_Eliminar_clicked);
            connect(inicio->getBoton_Ayuda(), &QPushButton::clicked , this, &MainWindow::on_boton_Ayuda_clicked);
            connect(inicio->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Salir_clicked);
        }
        else if (estado == "hard" || estado == "easy") {
            if (Spawner->getEnemigos()->isEmpty() && Spawner->getJefes()->isEmpty()) {
                pausa = new interfaz_pausa(false);
                this->setCentralWidget(pausa->getWid());
                connect(pausa->getBoton_Guardar(), &QPushButton::clicked , this, &MainWindow::on_boton_Guardar_clicked);
                connect(pausa->getBoton_Reiniciar(), &QPushButton::clicked , this, &MainWindow::on_boton_Reiniciar_clicked);
                connect(pausa->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Menu_clicked);
                if (estado == "hard") {
                    estado = "pause_N_hard";
                }
                else {
                    estado = "pause_N_easy";
                }
            }
        }
        else if (estado == "multi") {
            if (Spawner->getEnemigos()->isEmpty() && Spawner->getJefes()->isEmpty()) {
                pausa = new interfaz_pausa(true);
                this->setCentralWidget(pausa->getWid());
                connect(pausa->getBoton_Reiniciar(), &QPushButton::clicked , this, &MainWindow::on_boton_Reiniciar_clicked);
                connect(pausa->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Menu_clicked);
                estado = "pause_M";
            }
        }
        else if(estado == "help"){
            delete ayuda;
            menu();
        }
        else if ((estado != "transicion_N_easy") && (estado != "transicion_N_hard") && (estado != "transicion_M")) {
            estado = "esc";
        }
//        else{
//            estado = "esc";
//        }
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
            if (person->estado == "vivo") {
                if (!Spawner->getEnemigos()->isEmpty()) {
                    bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 20, 20, 3, Spawner->getEnemigos(),puntos);
                }
                else {
                    bullet = new bullets(":/Imagenes/disparos/disparos_varios.png", 20, 20, 3, Spawner->getJefes());
                }
                direccion_disparo(person);
                escenario->getMundo()->addItem(bullet);
                time->stop();
                person->ispush = true;
                person->columnas = person->ancho*4;
                person->max_columnas = 7;
                sonidoefecto->sonidosvarios("bala");
            }
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
            if (person->estado == "vivo") {
                if (!Spawner->getEnemigos()->isEmpty()) {
                    bullet = new bullets(":/Imagenes/disparos/disparos_varios2.png", 20, 20, 3, Spawner->getEnemigos(),puntos);
                }
                else {
                    bullet = new bullets(":/Imagenes/disparos/disparos_varios2.png", 20, 20, 3, Spawner->getJefes());
                }
                direccion_disparo(person);
                escenario->getMundo()->addItem(bullet);
                time->stop();
                person->ispush = true;
                person->columnas = person->ancho*4;
                person->max_columnas = 7;
                sonidoefecto->sonidosvarios("bala");
            }
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
        if (personaje1->estado == "vivo") {
            movimiento_personaje(personaje1);
        }
        else {
            timer1->start(40);
            timer3->start();
            personaje1->filas = 0;
            personaje1->estado = "vivo";
            for(auto it : *Spawner->getEnemigos()){
                it->timer->start();
            }
            for(auto it : *Spawner->getJefes()){
                it->timer->start();
            }
            personaje1->vida = 1000;
            personaje1->barra_personaje->setValue(personaje1->vida);
        }
        reinicio_muerte(personaje1, vidas1, timer1);
    }
    if (personaje_seg) {
        if (personaje2->estado == "vivo") {
            movimiento_personaje(personaje2);
        }
        else {
            timer2->start(60);
            timer3->start();
            personaje2->filas = 0;
            personaje2->estado = "vivo";
            for(auto it : *Spawner->getEnemigos()){
                it->timer->start();
            }
            for(auto it : *Spawner->getJefes()){
                it->timer->start();
            }
            personaje2->vida = 1000;
            personaje2->barra_personaje->setValue(personaje2->vida);
        }
        reinicio_muerte(personaje2, vidas2, timer2);
    }
}

void MainWindow::reinicio_muerte(personaje_principal *person, life *vidas, QTimer *time)
{
    if (person->vida <= 0) {
        sonidoefecto->sonidosvarios("grito");
        vidas->eliminar_vida();
        if (person == personaje1) {
            personaje_pri = false;
            personajes.removeOne(personaje1);
        }
        else {
            personaje_seg = false;
            personajes.removeOne(personaje2);
        }
        if (!vidas->getVidas()->isEmpty()) {
            person->estado = "muerto";
            time->start(3000);
            timer3->stop();
            person->filas = 140;
            for(auto it : *Spawner->getEnemigos()){
                it->timer->stop();
            }
            for(auto it : *Spawner->getJefes()){
                it->timer->stop();
            }
            if (person == personaje1) {
                personaje_pri = true;
                personajes.push_front(personaje1);
            }
            else {
                personaje_seg = true;
                personajes.push_back(personaje2);
            }
        }
        else {
            person->barra_personaje->setVisible(false);
            escenario->getMundo()->removeItem(person);
            if (estado == "hard" || estado == "easy") {
                pausa = new interfaz_pausa(true);
                this->setCentralWidget(pausa->getWid());
                connect(pausa->getBoton_Reiniciar(), &QPushButton::clicked , this, &MainWindow::on_boton_Reiniciar_clicked);
                connect(pausa->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Menu_clicked);
                if (estado == "hard") {
                    estado = "pause_N_hard";
                }
                else {
                    estado = "pause_N_easy";
                }
                sonidoefecto->sonidosvarios("gameover");
            }
            else if (estado == "multi" && !personaje_pri && !personaje_seg) {
                sonidoefecto->sonidosvarios("gameover");
                pausa = new interfaz_pausa(true);
                this->setCentralWidget(pausa->getWid());
                connect(pausa->getBoton_Reiniciar(), &QPushButton::clicked , this, &MainWindow::on_boton_Reiniciar_clicked);
                connect(pausa->getBoton_Salir(), &QPushButton::clicked , this, &MainWindow::on_boton_Menu_clicked);
                estado = "pause_M";
            }
        }
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
    cuadro_puntos->actualizar(puntos);
}

void MainWindow::actualizar(personaje_principal *person)
{
    if (personaje_pri) {
        view->centerOn(personaje1);
    }
    else {
        view->centerOn(personaje2);
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
    if (!Spawner->getJefes()->isEmpty()) {
        for (int i = 0; i < zonas_jefes->getContenedor()->size() ;i++) {
            if(person->collidesWithItem(zonas_jefes->getContenedor()->at(i))){
                person->down();
            }
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
    if (!Spawner->getJefes()->isEmpty()) {
        for (int i = 0; i < zonas_jefes->getContenedor()->size() ;i++) {
            if(person->collidesWithItem(zonas_jefes->getContenedor()->at(i))){
                person->up();
            }
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
    if (!Spawner->getJefes()->isEmpty()) {
        for (int i = 0; i < zonas_jefes->getContenedor()->size() ;i++) {
            if(person->collidesWithItem(zonas_jefes->getContenedor()->at(i))){
                person->right();
            }
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
    if (!Spawner->getJefes()->isEmpty()) {
        for (int i = 0; i < zonas_jefes->getContenedor()->size() ;i++) {
            if(person->collidesWithItem(zonas_jefes->getContenedor()->at(i))){
                person->left();
            }
        }
    }
}

void MainWindow::colision_spawn(personaje_principal *person)
{
    if (Spawner->getEnemigos()->isEmpty() && Spawner->getJefes()->isEmpty()) {
        if(Spawner->activo){
            escenario->getMundo()->removeItem(escenario->getZona_blocked()->last());
            escenario->getZona_blocked()->pop_back();
            Spawner->activo = false;
        }
        for (int i = 0 ;i < escenario->getZonaspawn()->size();i++) {
            if(person->collidesWithItem(escenario->getZonaspawn()->at(i))){
                Spawner->zona_activa(i);
                for(auto it : *Spawner->getEnemigos()){
                    timer3->start(2300);
                    escenario->getMundo()->addItem(it);
                }
                for(auto it : *Spawner->getJefes()){
                    if (it->movement == 1) {
                        timer3->start(2300);
                    }
                    else {
                        timer3->start(300);
                    }
                    escenario->getMundo()->addItem(it);
                    if (Spawner->mundo == 1) {
                        zonas_jefes->mundo1();
                    }
                    else {
                        zonas_jefes->mundo2();
                    }
                    if (estado == "multi") {
                        if (personaje_pri && personaje_seg) {
                            if (it->movement == 2) {
                                if (personaje2->y() > personaje1->y()) {
                                    personaje2->setPos(personaje1->pos());
                                    actualizar(personaje2);
                                }
                                else {
                                    personaje1->setPos(personaje2->pos());
                                    actualizar(personaje1);
                                }
                            }
                            else if (personaje2->x() < personaje1->x()) {
                                personaje2->setPos(personaje1->pos());
                                actualizar(personaje2);
                            }
                            else {
                                personaje1->setPos(personaje2->pos());
                                actualizar(personaje1);
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        for(auto it : *Spawner->getEnemigos()){
            if (it->collidesWithItem(person)) {
                person->velocidad = 4;
                if (person->x()-it->x() < 6 and person->x()-it->x() > -6) {
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
                            it->seguir(person->x()+100,person->y()+15);
                        }
                        else if (it->x() > person->x()){
                            if (itt != it) {
                                if (it->collidesWithItem(itt)){
                                    itt->seguir(itt->x(), itt->y());
                                }
                            }
                            it->seguir(person->x()-100,person->y()+15);
                        }
                    }
                }
            }
            else {
                it->seguir(person->x(),person->y());
            }
        }

    }

}

void MainWindow::generar_disparo()
{
    for (auto it : *Spawner->getEnemigos()){
        if (personaje_pri || personaje_seg) {
            if (it->Disparo != "no") {
                bullets_enemy *Bullet = new bullets_enemy(it->Disparo, 17, 17, 3, personajes);
                Bullet->setPos(it->x()+15, it->y()+15);
                escenario->getMundo()->addItem(Bullet);
            }
        }
    }
    if (!Spawner->getJefes()->isEmpty()) {
        for (auto it: *Spawner->getJefes()){
            if(it->movement == 1){
                Powerboss *fisica = new Powerboss(":/Imagenes/disparos/roca1.png",18,18,1,1,it,personajes);
                escenario->getMundo()->addItem(fisica);
                if (it->vida <= 0){
                    escenario->getMundo()->removeItem(it);
                    Spawner->getJefes()->removeFirst();
                    *puntos += 1000;
                }
            }
            else if(it->movement == 2){
                Powerboss *fisica = new Powerboss(":/Imagenes/disparos/burbuja.png",17,17,6,2,it,personajes);
                escenario->getMundo()->addItem(fisica);
                if (it->vida <= 0){
                    escenario->getMundo()->removeItem(it);
                    Spawner->getJefes()->removeFirst();
                    transicion = new transiciones(":/Imagenes/transicion_mundo2.png", 1366,768,4,5);
                    escenario->getMundo()->addItem(transicion);
                    view->resetTransform();
                    escenario->getMundo()->setSceneRect(0,0,1366,768);
                    disconnect(timer3, &QTimer::timeout, this, &MainWindow::generar_disparo);
                    connect(timer3, &QTimer::timeout, this, &MainWindow::cambiar_mundo);
                    if (estado == "easy") {
                        estado = "transicion_N_easy";
                    }
                    else if (estado == "hard") {
                        estado = "transicion_N_hard";
                    }
                    else if (estado == "multi") {
                        estado = "transicion_M";
                    }
                    *puntos += 1000;
                }
            }
            else if(it->movement == 3){
                if ((it->vida <= 3800 && it->total_habilidades == 3) || (it->vida <= 2900 && it->total_habilidades == 2) || (it->vida <=2000 && it->total_habilidades == 1) ) {
                    it->habilidad_disponible = true;
                }
                if (it->habilidad_disponible) {
                    Powerboss *fisica = new Powerboss(":/Imagenes/disparos/ojo.png",20,20,3,3,it,personajes);
                    escenario->getMundo()->addItem(fisica);
                    it->habilidad_disponible = false;
                    it->total_habilidades -= 1;
                    Spawner->getEyes()->push_back(fisica);
                }
                if(it->distancia_recorrida > 60){
                    if (personaje_pri) {
                        it->playerx = personaje1->x();
                        it->playery = personaje1->y();
                    }
                    else if(personaje_seg){
                        it->playerx = personaje2->x();
                        it->playery = personaje2->y();
                    }
                    it->distancia_recorrida = 0;
                }
                it->distancia_recorrida += 10;
                for (auto itt : personajes) {
                    if (it->collidesWithItem(itt)) {
                        itt->vida -= 10;
                        itt->barra_personaje->setValue(itt->vida);
                    }
                }
                if (it->vida <= 0) {
                    for (auto it : *Spawner->getEyes()) {
                        escenario->getMundo()->removeItem(it);
                        delete it;
                    }
                    delete Spawner->getEyes();
                    escenario->getMundo()->removeItem(it);
                    Spawner->getJefes()->removeFirst();
                    *puntos += 1000;
                }
            }
            else if(it->movement == 4){
                Powerboss *fisica = new Powerboss(":/Imagenes/disparos/bola_roja.png",17,17,3,4,it,personajes);
                escenario->getMundo()->addItem(fisica);
                if (it->vida <= 0){
                    escenario->getMundo()->removeItem(it);
                    Spawner->getJefes()->removeFirst();
                    view->resetTransform();
                    escenario->getMundo()->setSceneRect(0,0,1366,768);
                    escenario->getMundo()->setBackgroundBrush(QBrush(QImage(":/Imagenes/imagen_final1.png")));
                    timer3->start(7000);
                    disconnect(timer3, &QTimer::timeout, this, &MainWindow::generar_disparo);
                    connect(timer3, &QTimer::timeout, this, &MainWindow::imagen_final);
                }
            }
        }
    }
}

void MainWindow::cambiar_mundo()
{
    if (transicion->filas == (transicion->total_filas * transicion->alto)) {
        int vida1 = personaje1->vida, num_vida1 = vidas1->getVidas()->length();
        escenario->getMundo()->removeItem(transicion);
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete vidas1;
        delete personaje1;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        mundo = 2;
        crear_personaje = false;
        if (estado == "transicion_N_easy") {
            estado = "reset";
            on_boton_Facil_clicked();
            cargar_personajes(1, 150, 150, 1000, num_vida1, 40);
            personaje1->vida = vida1;
            personaje1->barra_personaje->setValue(personaje1->vida);
            personaje_seg = false;
        }
        else if (estado == "transicion_N_hard") {
            estado = "reset";
            on_boton_Dificil_clicked();
            cargar_personajes(1, 150, 150, 1000, num_vida1, 40);
            personaje1->vida = vida1;
            personaje1->barra_personaje->setValue(personaje1->vida);
            personaje_seg = false;
        }
        else if (estado == "transicion_M") {
            int vida2 = personaje2->vida, num_vida2 = vidas2->getVidas()->length();
            delete timer2;
            delete vidas2;
            estado = "reset";
            on_boton_Multi_clicked();
            if (personaje_pri) {
                cargar_personajes(1, 150, 150, 1000, num_vida1, 40);
                personaje1->vida = vida1;
                personaje1->barra_personaje->setValue(personaje1->vida);
            }
            else {
                cargar_personajes(1, 150, 150, 0, 1, 40);
            }
            if (personaje_seg) {
                cargar_personajes(2, 110, 150, 1000, num_vida2, 60);
                personaje2->vida = vida2;
                personaje2->barra_personaje->setValue(personaje2->vida);
            }
            else {
                cargar_personajes(2, 150, 150, 0, 1, 40);
            }
        }
        crear_personaje = true;
        mundo = 1;
    }
}

void MainWindow::imagen_final()
{
    if (estado == "easy" || estado == "hard") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete vidas1;
        delete personaje1;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;
    }
    else if (estado == "multi") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete timer2;
        delete vidas1;
        delete vidas2;
        delete personaje1;
        delete personaje2;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;
    }
    crear_personaje = true;
    mundo = 1;
    menu();
}

void MainWindow::cargar_mundo1()
{
    personajes.clear();

    escenario = new mapa(":/Imagenes/primer_mapa.png");
    Spawner = new spawn();
    zonas_jefes = new zonas_especiales;

    view->setScene(escenario->getMundo());
    view->scale(1.7,1.4);

    Spawner->carga_Datos(":/info/enemy_info.txt");
    escenario->carga_Datos(":/info/colisiones1.txt", escenario->getContenedor());
    escenario->carga_Datos(":/info/zonas_spawn.txt", escenario->getZonaspawn());
    escenario->carga_Datos(":/info/zona_bloqueada1.txt", escenario->getZona_blocked());

    timer3 = new QTimer;
    timer3->start(300);
    connect(timer3, &QTimer::timeout, this, &MainWindow::generar_disparo);
}

void MainWindow::cargar_mundo2()
{
    personajes.clear();

    escenario = new mapa(":/Imagenes/segundo_mapa.png");
    Spawner = new spawn();
    zonas_jefes = new zonas_especiales;
    Spawner->mundo = 2;

    view->setScene(escenario->getMundo());
    view->scale(1.7,1.4);

    Spawner->carga_Datos(":/info/enemy_info2.txt");
    escenario->carga_Datos(":/info/colisiones2.txt", escenario->getContenedor());
    escenario->carga_Datos(":/info/zonas_spawn2.txt", escenario->getZonaspawn());
    escenario->carga_Datos(":/info/zona_bloqueada2.txt", escenario->getZona_blocked());

    timer3 = new QTimer;
    timer3->start(300);
    connect(timer3, &QTimer::timeout, this, &MainWindow::generar_disparo);
}

void MainWindow::cargar_personajes(int persona, float pos_x, float pos_y, int vida_total, int num_vidas, int milisegundos)
{
    if (persona == 1) {
        timer1 = new QTimer;
        personaje1 = new personaje_principal(":/Imagenes/soldado universal.png",35,35,0,0,vida_total);
        vidas1 = new life(this, num_vidas, (num_vidas*33)+1, 0, 0);

        escenario->getMundo()->addItem(personaje1);
        escenario->getMundo()->addWidget(personaje1->barra_personaje);
        personaje1->setPos(pos_x,pos_y);

        timer1->start(milisegundos);

        connect(timer1, &QTimer::timeout, this, &MainWindow::personajes_activos);

        personaje_pri = true;
        personajes.push_back(personaje1);
        actualizar(personaje1);
    }
    else {
        timer2 = new QTimer;
        personaje2 = new personaje_principal(":/Imagenes/soldado universal2.png",35,35,0,0,vida_total);
        vidas2 = new life(this, num_vidas, (num_vidas*33)+1, 1332, 0);

        escenario->getMundo()->addItem(personaje2);
        escenario->getMundo()->addWidget(personaje2->barra_personaje);
        personaje2->setPos(pos_x,pos_y);

        timer2->start(milisegundos);

        connect(timer2, &QTimer::timeout, this, &MainWindow::personajes_activos);

        personaje_seg = true;
        personajes.push_back(personaje2);
        actualizar(personaje2);
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
    if (estado != "reset") {
        delete inicio;
    }
    if (mundo == 1) {
        cargar_mundo1();
        if (crear_personaje) {
            cargar_personajes(1, 150, 740, 1000, 3, 40);
            personaje_seg = false;
            puntos = new int(0);
            cuadro_puntos = new puntaje(this, 0, 33);
        }
    }
    else {
        cargar_mundo2();
        if (crear_personaje) {
            cargar_personajes(1, 150, 150, 1000, 3, 40);
            personaje_seg = false;
        }
    }

    estado = "easy";
    sonidoefecto->sonidosfondo("jugar");
}

void MainWindow::on_boton_Dificil_clicked()
{
    if (estado != "reset") {
        delete inicio;
    }
    if (mundo == 1) {
        cargar_mundo1();
        if (crear_personaje) {
            cargar_personajes(1, 150, 740, 1000, 1, 40);
            personaje_seg = false;
            puntos = new int(0);
            cuadro_puntos = new puntaje(this, 0, 33);
        }
    }
    else {
        cargar_mundo2();
        if (crear_personaje) {
            cargar_personajes(1, 150, 150, 1000, 1, 40);
            personaje_seg = false;
        }
    }
    estado = "hard";
    sonidoefecto->sonidosfondo("jugar");
}

void MainWindow::on_boton_Multi_clicked()
{
    on_boton_Dificil_clicked();

    if (crear_personaje) {
        cargar_personajes(2, (personaje1->x()-40), personaje1->y(), 1000, 1, 60);
        timer1->start(60);
    }

    estado = "multi";
}

void MainWindow::on_boton_Cargar_clicked()
{
    QString nombreArch;
    nombreArch = QFileDialog::getOpenFileName(this, "Abrir Archivo");
    datos_almacenados = new load_and_save(this);
    datos_almacenados->load(nombreArch);
    if (datos_almacenados->crear) {
        estado = datos_almacenados->estado;
        mundo = datos_almacenados->mundo;
        crear_personaje = false;
        if (estado == "easy") {
            estado = "reset";
            on_boton_Facil_clicked();
            cargar_personajes(1, datos_almacenados->per_x, datos_almacenados->per_y, 1000, datos_almacenados->num_vidas, 40);
            personaje1->vida = datos_almacenados->vida;
            personaje1->barra_personaje->setValue(personaje1->vida);
        }
        else {
            estado = "reset";
            on_boton_Dificil_clicked();
            cargar_personajes(1, datos_almacenados->per_x, datos_almacenados->per_y, 1000, datos_almacenados->num_vidas, 40);
            personaje1->vida = datos_almacenados->vida;
            personaje1->barra_personaje->setValue(personaje1->vida);
        }
        puntos = new int(0);
        cuadro_puntos = new puntaje(this, 0, 33);
        *puntos = datos_almacenados->puntos;
        personaje_seg = false;
        crear_personaje = true;
        mundo = 1;
        delete Spawner->getInfoenemy();
        delete escenario->getZona_blocked();
        Spawner->setInfoenemy(datos_almacenados->getInfoenemy());
        escenario->setZona_blocked(datos_almacenados->getZona_blocked());
        delete inicio;
    }
    delete datos_almacenados;
}

void MainWindow::on_boton_Eliminar_clicked()
{
    QFile arch;
    QString nombreArch, extension;
    nombreArch = QFileDialog::getOpenFileName(this, "Eliminar Archivo");
    if (!nombreArch.isEmpty()) {
        arch.setFileName(nombreArch);
        for (int i = (nombreArch.length()-1); i > (nombreArch.length()-6)  ; i-- ) {
            extension.push_front(nombreArch[i]);
        }
        if (extension == ".hell") {
            arch.remove();
        }
        else {
            QMessageBox::critical(this, "Error", "Archivo Denegado");
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

void MainWindow::on_boton_Guardar_clicked()
{
    QString nombreArch;
    nombreArch = QFileDialog::getSaveFileName(this, "Guardar Como");

    datos_almacenados = new load_and_save(this);

    if (estado == "pause_N_easy"){
        datos_almacenados->estado = "easy";
    }
    else if (estado == "pause_N_hard") {
        datos_almacenados->estado = "hard";
    }
    datos_almacenados->mundo = Spawner->mundo;
    datos_almacenados->num_vidas = vidas1->getVidas()->length();
    datos_almacenados->personajes = personajes;
    datos_almacenados->infoenemy = Spawner->getInfoenemy();
    datos_almacenados->zona_blocked = escenario->getZona_blocked();
    datos_almacenados->puntos = *puntos;

    datos_almacenados->save(nombreArch);
    delete datos_almacenados;
}

void MainWindow::on_boton_Reiniciar_clicked()
{
    delete pausa;
    if (estado == "pause_N_easy" || estado == "pause_N_hard") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete vidas1;
        delete personaje1;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;

        if (estado == "pause_N_easy") {
            estado = "reset";
            on_boton_Facil_clicked();
        }
        else {
            estado = "reset";
            on_boton_Dificil_clicked();
        }
    }
    else if (estado == "pause_M") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete timer2;
        delete vidas1;
        delete vidas2;
        delete personaje1;
        delete personaje2;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;

        estado = "reset";
        on_boton_Multi_clicked();
    }
}

void MainWindow::on_boton_Menu_clicked()
{
    delete pausa;
    if (estado == "pause_N_easy" || estado == "pause_N_hard") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete vidas1;
        delete personaje1;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;
    }
    else if (estado == "pause_M") {
        view->resetTransform();
        delete timer3;
        delete timer1;
        delete timer2;
        delete vidas1;
        delete vidas2;
        delete personaje1;
        delete personaje2;
        delete zonas_jefes;
        delete escenario;
        delete Spawner;
        delete cuadro_puntos;
        delete puntos;
    }
    menu();
}

MainWindow::~MainWindow()
{
    delete ui;
}
