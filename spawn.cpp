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
    QMap<QString, float *>::iterator i = infoenemy->find(mob);
    for (int num_enemigo = 0, indice_dato = 4; num_enemigo < i.value()[3] ; num_enemigo++, indice_dato+=2) {
        Enemigos->push_back(new enemigos(imagsource,i.value()[0], i.value()[1],i.value()[2],i.value()[indice_dato],i.value()[indice_dato+1]));
    }
    if(i.value()[3] != 0){
        activo = true;
    }
    i.value()[3] = 0;
}

void spawn::zona_activa(int i)
{
    if(mundo == 1){
        if(i == 0){
            generador("Cucarron",":/Imagenes/Enemigos/mundo1/1Cucarron.png");
        }
        else if(i == 1){
            generador("Escarabajo",":/Imagenes/Enemigos/mundo1/1Escarabajo.png");
        }
        else if(i == 2){
            generador("Cienpies",":/Imagenes/Enemigos/mundo1/1Cien_pies.png");
        }
        else if(i == 3){
            generador("Aranas",":/Imagenes/Enemigos/mundo1/1arana.png");
        }
        else if(i == 4){
            generador("Motosierra",":/Imagenes/Enemigos/mundo1/2motosierra.png");
        }
        else if(i == 5){
            generador("Carnivora",":/Imagenes/Enemigos/mundo1/2planta_carnivora.png");
        }
        else if(i == 6){
            generador("Cocodrilo",":/Imagenes/Enemigos/mundo1/2Cocodrilo.png");
        }
        else if(i == 7){
            generador("Dragonagua",":/Imagenes/Enemigos/mundo1/3Dragon_agua.png");
        }
        else if(i == 8){
            generador("Cangrejo",":/Imagenes/Enemigos/mundo1/4mini_cangrejo.png");
        }
        else if(i == 9){
            generador("Urgot",":/Imagenes/Enemigos/mundo1/4Urgot.png");
        }
    }
    else if(mundo == 2){
        if(i == 0){
            generador("Esqueleto",":/Imagenes/Enemigos/mundo2/Esqueleticoxd.png");
        }
        else if(i == 1){
            generador("Tarantula",":/Imagenes/Enemigos/mundo2/Tarantula.png");
        }
        else if(i == 2){
            generador("Dracula",":/Imagenes/Enemigos/mundo2/Dracula.png");
        }
        else if(i == 3){
            generador("Genio",":/Imagenes/Enemigos/mundo2/genio.png");
        }
        else if(i == 4){
            generador("Momia",":/Imagenes/Enemigos/mundo2/Momia .png");
        }
        else if(i == 5){
            generador("Dracula2",":/Imagenes/Enemigos/mundo2/Dracula.png");
        }
        else if(i == 6){
            generador("Gargola",":/Imagenes/Enemigos/mundo2/Gargola.png");
        }
        else if(i == 7){
            generador("Esqueleto2",":/Imagenes/Enemigos/mundo2/Esqueleticoxd.png");
        }
        else if(i == 8){
            generador("Drakebone",":/Imagenes/Enemigos/mundo2/Drago_Esqueleto.png");
        }
        else if(i == 9){
            generador("Diabloculon",":/Imagenes/Enemigos/mundo2/Demonio_cajaxd.png");
        }
        else if(i == 10){
            generador("Diablo",":/Imagenes/Enemigos/mundo2/diablo_enano.png");
        }
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

