#include "spawn.h"

spawn::spawn(QObject *parent) : QObject(parent)
{
    infoenemy = new QMap<QString, float *>;
    Enemigos = new QVector<enemigos *>;
    Jefes = new QVector<jefe*>;
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

void spawn::generador(QString mob, QString imagsource, QString disparo)
{
    QMap<QString, float *>::iterator i = infoenemy->find(mob);
    if(mob == "Golem" && i.value()[3] != 0){
        Jefes->push_back(new jefe(imagsource,1,i.value()[0],i.value()[1],i.value()[2],i.value()[4],i.value()[5],i.value()[6], i.value()[7]));
    }
    else if(mob == "DonCangrejo" && i.value()[3] != 0){
        Jefes->push_back(new jefe(imagsource,2,i.value()[0],i.value()[1],i.value()[2],i.value()[4],i.value()[5],i.value()[6], i.value()[7]));
    }
    else if(mob == "Toro" && i.value()[3] != 0){
        eyes = new QVector<Powerboss *>;
        Jefes->push_back(new jefe(imagsource,3,i.value()[0],i.value()[1],i.value()[2],i.value()[4],i.value()[5],i.value()[6], i.value()[7]));
    }
    else if(mob == "Belcebu" && i.value()[3] != 0){
        Jefes->push_back(new jefe(imagsource,4,i.value()[0],i.value()[1],i.value()[2],i.value()[4],i.value()[5],i.value()[6], i.value()[7]));
    }
    else{
        for (int num_enemigo = 0, indice_dato = 6; num_enemigo < i.value()[3] ; num_enemigo++, indice_dato+=2) {
            Enemigos->push_back(new enemigos(imagsource,i.value()[0], i.value()[1],i.value()[2],i.value()[4],i.value()[5],disparo,i.value()[indice_dato],i.value()[indice_dato+1]));
        }
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
            generador("Cucarron",":/Imagenes/Enemigos/mundo1/1Cucarron.png", "no");
        }
        else if(i == 1){
            generador("Escarabajo",":/Imagenes/Enemigos/mundo1/1Escarabajo.png", "no");
        }
        else if(i == 2){
            generador("Cienpies",":/Imagenes/Enemigos/mundo1/1Cien_pies.png", "no");
        }
        else if(i == 3){
            generador("Aranas",":/Imagenes/Enemigos/mundo1/1arana.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 4){
            generador("Golem",":/Imagenes/Enemigos/mundo1/1Golem.png","no");
        }
        else if(i == 5){
            generador("Motosierra",":/Imagenes/Enemigos/mundo1/2motosierra.png", "no");
        }
        else if(i == 6){
            generador("Carnivora",":/Imagenes/Enemigos/mundo1/2planta_carnivora.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 7){
            generador("Cocodrilo",":/Imagenes/Enemigos/mundo1/2Cocodrilo.png", "no");
        }
        else if(i == 8){
            generador("Dragonagua",":/Imagenes/Enemigos/mundo1/3Dragon_agua.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 9){
            generador("Cangrejo",":/Imagenes/Enemigos/mundo1/4mini_cangrejo.png", "no");
        }
        else if(i == 10){
            generador("Urgot",":/Imagenes/Enemigos/mundo1/4Urgot.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 11){
            generador("DonCangrejo",":/Imagenes/Enemigos/mundo1/cangrejo clone.png","no");
        }

    }
    else if(mundo == 2){
        if(i == 0){
            generador("Esqueleto",":/Imagenes/Enemigos/mundo2/Esqueleticoxd.png", "no");
        }
        else if(i == 1){
            generador("Tarantula",":/Imagenes/Enemigos/mundo2/Tarantula.png", "no");
        }
        else if(i == 2){
            generador("Dracula",":/Imagenes/Enemigos/mundo2/Dracula.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 3){
            generador("Genio",":/Imagenes/Enemigos/mundo2/genio.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 4){
            generador("Toro",":/Imagenes/Enemigos/mundo2/Toro.png","no");
        }
        else if(i == 5){
            generador("Momia",":/Imagenes/Enemigos/mundo2/Momia .png", "no");
        }
        else if(i == 6){
            generador("Dracula2",":/Imagenes/Enemigos/mundo2/Dracula.png", "no");
        }
        else if(i == 7){
            generador("Gargola",":/Imagenes/Enemigos/mundo2/Gargola.png", "no");
        }
        else if(i == 8){
            generador("Esqueleto2",":/Imagenes/Enemigos/mundo2/Esqueleticoxd.png", "no");
        }
        else if(i == 9){
            generador("Drakebone",":/Imagenes/Enemigos/mundo2/Drago_Esqueleto.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 10){
            generador("Diabloculon",":/Imagenes/Enemigos/mundo2/Demonio_cajaxd.png", ":/Imagenes/disparos/bola_amarilla.png");
        }
        else if(i == 11){
            generador("Diablo",":/Imagenes/Enemigos/mundo2/diablo_enano.png", "no");
        }
        else if(i == 12){
            generador("Belcebu",":/Imagenes/Enemigos/mundo2/demonio_jefe.png", "no");
        }
    }
}

QVector<enemigos *> *spawn::getEnemigos() const
{
    return Enemigos;
}

QVector<jefe *> *spawn::getJefes() const
{
    return Jefes;
}

QVector<Powerboss *> *spawn::getEyes() const
{
    return eyes;
}

spawn::~spawn()
{
    delete datos;
    delete Jefes;
    delete Enemigos;
    delete infoenemy;
}

