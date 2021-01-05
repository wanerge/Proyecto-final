#include "mapa.h"

mapa::mapa()
{

}

void mapa::carga_Datos(QString nombre_archivo)
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
            colisiones *rec = new colisiones(datos[0], datos[1], datos[2], datos[3]);
            contenedor->push_back(rec);
        }
        archivo.close();
    }
}

QVector<colisiones *> *mapa::getContenedor() const
{
    return contenedor;
}
