#include "mapa.h"

mapa::mapa(QString mundo_)
{
    contenedor = new QVector<colisiones *>;
    zonaspawn = new QVector<colisiones *>;
    zona_blocked = new QVector<colisiones *>;
    mundo = new QGraphicsScene;
    mundo->setSceneRect(0,0,4800,1230);
    mundo->setBackgroundBrush(QBrush(QImage(mundo_)));
}

void mapa::carga_Datos(QString nombre_archivo, QVector<colisiones *> *container)
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
            datos[3] = linea2.toInt();
            rec = new colisiones(datos[0], datos[1], datos[2], datos[3], Qt::blue);
            container->push_back(rec);
        }
        archivo.close();
    }
//    if (nombre_archivo == ":/info/zonas_spawn.txt") {
//        for(auto it : *container){
//            mundo->addItem(it);
//        }
//    }
}

QVector<colisiones *> *mapa::getZona_blocked() const
{
    return zona_blocked;
}

void mapa::setZona_blocked(QVector<colisiones *> *value)
{
    zona_blocked = value;
}

QVector<colisiones *> *mapa::getContenedor() const
{
    return contenedor;
}

QGraphicsScene *mapa::getMundo() const
{
    return mundo;
}

QVector<colisiones *> *mapa::getZonaspawn() const
{
    return zonaspawn;
}

mapa::~mapa()
{
    delete zona_blocked;
    delete zonaspawn;
    delete mundo;
    delete contenedor;
}
