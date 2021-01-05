#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    mundo1 =new QGraphicsScene(this);
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
    mun_crash=new QVector <colisiones *>;

    mundo1->addItem(person);

    view->centerOn(person->x(),person->y());

    letra = new char[1];

    *letra = 'S';

    timer1=new QTimer;

    timer1->start(200);

    connect(timer1, &QTimer::timeout, this, &MainWindow::reposaito);


    mun1_crash.push_back(new colisiones(20,20,-140,-115));mundo1->addItem(mun1_crash.back());
    cargar_datos("../MiguelSernaM-patch-1/info/colisiones2.txt",mun_crash,1);

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

template<typename T>
void MainWindow::cargar_datos(QString nombre_archivo, T *contenedor,int mundo)
{
    QString linea1, linea2;
    int datos[4];
    QFile archivo(nombre_archivo);
    if (archivo.open(QIODevice::ReadOnly)) {
        QTextStream in(&archivo);
        while (!in.atEnd())
        {
            linea1 = in.readLine();
            linea2 = "";
            for (int i = 0, j = 0 ; i < linea1.length(); i++) {
                if(linea1[i] == ' '){
                    j++;
                    switch (j) {
                        case 1:
                            datos[0] = linea2.toInt();
                        break;
                        case 2:
                            datos[1] = linea2.toInt();
                        break;
                        case 3:
                            datos[2] = linea2.toInt();
                        break;

                    }
                    linea2 = "";
                }
                else linea2.push_back(linea1[i]);
            }
            datos[3] =linea2.toInt();
            colisiones *rec = new colisiones( datos[0], datos[1], datos[2], datos[3]);
            if(mundo==1)
                mundo1->addItem(rec);
            else{
                mundo2->addItem(rec);
            }
            contenedor->push_back(rec);
        }
        archivo.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
