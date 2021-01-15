#include "spawn.h"

spawn::spawn(QObject *parent) : QObject(parent)
{
    //carga_Datos(":/info/enemy_info.txt");
    infoenemy = new QMap<QString, float *>;
    Enemigos = new QVector<enemigos *>;
}

void spawn::carga_Datos(QString nombre_archivo)
{
    int num_datos;
    QString linea1, linea2;
    QString aux;
    QFile archivo(nombre_archivo);
    if (archivo.open(QIODevice::ReadOnly)) {
        QTextStream in(&archivo);
        while (!in.atEnd())
        {
            linea1 = in.readLine();
            linea2 = "";
            num_datos = linea1.count(' ');
            datos = new float[num_datos];
            for (int i = 0, j = 1, k = 0; i < linea1.length(); i++) {
                if(linea1[i] == ' '){
                    switch (j) {
                    case 1:
                        aux = linea2;
                        j++;
                        break;
                    case 2:
                        datos[k] = linea2.toFloat();
                        k++;
                        break;
                    }
                    linea2 = "";
                }
                else linea2.push_back(linea1[i]);
            }
            datos[num_datos-1] = linea2.toFloat();
            infoenemy->insert(aux, datos);
            numero_datos.push_back(num_datos);
        }
        archivo.close();
    }
}

void spawn::generador(QString mob, QString imagsource)
{
    Enemigos = new QVector<enemigos *>;
    QMap<QString, float *>::iterator i = infoenemy->find(mob);
    for (int num_enemigo = 0, indice_dato = 4; num_enemigo < i.value()[3] ; num_enemigo++, indice_dato+=2) {
        Enemigos->push_back(new enemigos(imagsource,i.value()[0], i.value()[1],i.value()[2],i.value()[indice_dato],i.value()[indice_dato+1]));
    }
    i.value()[3] = 0;
}

void spawn::zona_activa(int i)
{
    delete Enemigos;
    if(i == 0){
        generador("Cucarron",":/Imagenes/Enemigos/mundo1/1Cucarron.png");
    }
}

QVector<enemigos *> *spawn::getEnemigos() const
{
    return Enemigos;
}

spawn::~spawn()
{
    delete Enemigos;
    delete infoenemy;
}

