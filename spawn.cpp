#include "spawn.h"

spawn::spawn(QObject *parent) : QObject(parent)
{
    //  carga_Datos(":/info/enemy_info.txt");
    infoenemy = new QMap<QString,QVector<float>>;
    identidades = new QList<enemigos *>;
}
void spawn::carga_Datos(QString nombre_archivo)
{
    QString linea1, linea2;
    QString *aux;
    aux=new QString;
    QVector<float> *datos;
    datos=new QVector<float>;
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
                    case 1:{
                        *aux=linea2;
                        break;}
                    case 2:{
                        datos->push_back( linea2.toFloat());
                        break;}
                    case 3:{
                        datos->push_back( linea2.toFloat());
                        break;}
                    case 4:{
                        datos->push_back( linea2.toFloat());
                        break;
                    }


                    }
                    linea2 = "";
                }
                else linea2.push_back(linea1[i]);
            }
            datos->push_back( linea2.toFloat());
            infoenemy->insert(*aux,*datos);
            datos->clear();

        }
        archivo.close();
    }
}

void spawn::leerdatos()
{
    QMap<QString, QVector<float>>::const_iterator i = infoenemy->constBegin();
    while (i != infoenemy->end()) {
        qDebug() << i.key() << ": " << i.value();
        ++i;
    }
}

QList<enemigos*> spawn::generador(QString mob,QString imagsource)
{
    QList<enemigos*> *spawners;
    spawners=new QList<enemigos*>;
    QMap<QString, QVector<float>>::const_iterator i = infoenemy->constBegin();
    infoenemy->value("Cucarron").value(3);
    float *posiciones=0,*datatxt=0;
    posiciones= new float,datatxt=new float;
    while (i != infoenemy->end()) {

        if(mob == "Cucarron"){

            posiciones[0]=150,posiciones[1]=450,posiciones[2]=300,posiciones[3]=350,posiciones[4]=700,posiciones[5]=300,posiciones[6]=360,posiciones[7]=270,posiciones[8]=500,posiciones[9]=320,posiciones[10]=800;
            datatxt[0]=i.value()[0],datatxt[1]=i.value()[1],datatxt[2]=i.value()[2];

            for(int mobs = 0,pos=0;mobs <i.value()[3] ;mobs++,pos+=2){

                spawners->push_back(new enemigos(imagsource,datatxt[0],datatxt[1],datatxt[2],posiciones[pos],posiciones[pos+1]));
            }
            QMap<QString, QVector<float>>::iterator it = infoenemy->find("Cucarron");
            if (it != infoenemy->end())
                it.value()[3] = {0};

            break;
        }

    }
    return *spawners;
}

QList<enemigos *> spawn::zona_activa(int i)
{
    if(i == 0){
        *identidades = generador("Cucarron",":/Imagenes/Enemigos/1Cucarron.png");
    }

    return *identidades;
}


