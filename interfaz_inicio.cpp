#include "interfaz_inicio.h"

interfaz_inicio::interfaz_inicio()
{
    scene = new QGraphicsScene;
    lay = new QVBoxLayout;

    scene->setSceneRect(0,0,1200,700);

    boton_Nueva = new Button("Nueva Partida");
    boton_Cargar = new Button("Cargar Partida");
    boton_Eliminar = new Button("Eliminar Partida");
    boton_Ayuda = new Button("Ayuda");
    boton_Salir = new Button("Salir");

    lay->addWidget(boton_Nueva);
    lay->addWidget(boton_Cargar);
    lay->addWidget(boton_Eliminar);
    lay->addWidget(boton_Ayuda);
    lay->addWidget(boton_Salir);

    boton_Nueva->setGeometry(1200, 50, boton_Nueva->width(), boton_Nueva->height());
    boton_Cargar->setGeometry(1200, 100, boton_Cargar->width(), boton_Cargar->height());
    boton_Eliminar->setGeometry(1200, 150, boton_Eliminar->width(), boton_Eliminar->height());
    boton_Ayuda->setGeometry(1200, 200, boton_Ayuda->width(), boton_Ayuda->height());
    boton_Salir->setGeometry(1200, 250, boton_Salir->width(), boton_Salir->height());

    connect(boton_Nueva, &QPushButton::clicked , this, &interfaz_inicio::on_boton_Nueva_clicked);
    connect(boton_Cargar, &QPushButton::clicked , this, &interfaz_inicio::on_boton_Cargar_clicked);
    connect(boton_Eliminar, &QPushButton::clicked , this, &interfaz_inicio::on_boton_Eliminar_clicked);
    connect(boton_Ayuda, &QPushButton::clicked , this, &interfaz_inicio::on_boton_Ayuda_clicked);
    connect(boton_Salir, &QPushButton::clicked , this, &interfaz_inicio::on_boton_Salir_clicked);
}

QGraphicsScene *interfaz_inicio::getScene() const
{
    return scene;
}

QVBoxLayout *interfaz_inicio::getLay() const
{
    return lay;
}

void interfaz_inicio::on_boton_Nueva_clicked()
{
    qDebug() << "nueva";
}

void interfaz_inicio::on_boton_Cargar_clicked()
{
    qDebug() << "cargar";
}

void interfaz_inicio::on_boton_Eliminar_clicked()
{
    qDebug() << "eliminar";
}

void interfaz_inicio::on_boton_Ayuda_clicked()
{
    qDebug() << "ayuda";
}

void interfaz_inicio::on_boton_Salir_clicked()
{
    qDebug() << "salir";
}

interfaz_inicio::~interfaz_inicio()
{

}
