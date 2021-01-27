#include "load_and_save.h"

load_and_save::load_and_save(QMainWindow *mainwindow_)
{
    mainwindow = mainwindow_;
}

void load_and_save::load(QString nombreArch)
{
    QString extension;
    if (!nombreArch.isEmpty()) {
        for (int i = (nombreArch.length()-1); i > (nombreArch.length()-6)  ; i-- ) {
            extension.push_front(nombreArch[i]);
        }
        if (extension == ".hell") {
            infoenemy = new QMap<QString, float *>;
            zona_blocked = new QVector<colisiones *>;
            int i = 1;
            QString linea1;
            QFile arch(nombreArch);
            if (arch.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&arch);
                while (!in.atEnd())
                {
                    linea1 = in.readLine();
                    switch (i) {
                    case 1:
                        estado = linea1;
                        i++;
                        break;
                    case 2:
                        mundo = linea1.toInt();
                        i++;
                        break;
                    case 3:
                        l_personaje(linea1);
                        i++;
                        break;
                    case 4:
                        puntos = linea1.toInt();
                        i++;
                        break;
                    case 5:
                        if (linea1 != "zona_bloquada") {
                            l_enemigos(linea1);
                        }
                        else {
                            i++;
                        }
                        break;
                    case 6:
                        l_zona_bloquada(linea1);
                        break;
                    }
                }
            }
            arch.flush();
            arch.close();
        }
        else {
            QMessageBox::critical(mainwindow, "Error", "Archivo Denegado");
            crear = false;
        }
    }
    else {
        QMessageBox::critical(mainwindow, "Error", "No ingreso nombre");
        crear = false;
    }
}

void load_and_save::l_personaje(QString linea1)
{
    QString linea2;
    linea2 = "";
    for (int i = 0, j = 0 ; i < linea1.length(); i++) {
        if(linea1[i] == ' '){
            j++;
            switch (j) {
            case 1:
                per_x = linea2.toFloat();
                break;
            case 2:
                per_y = linea2.toFloat();
                break;
            case 3:
                vida = linea2.toInt();
                break;
            }
            linea2 = "";
        }
        else linea2.push_back(linea1[i]);
    }
    num_vidas = linea2.toInt();
}

void load_and_save::l_enemigos(QString linea1)
{
    QString linea2 = "", aux;
    int num_datos;
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
}

void load_and_save::l_zona_bloquada(QString linea1)
{
    QString linea2 = "";
    int datos[4];
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
    colisiones *rec = new colisiones(datos[0], datos[1], datos[2], datos[3], Qt::blue);
    zona_blocked->push_back(rec);
}

QVector<colisiones *> *load_and_save::getZona_blocked() const
{
    return zona_blocked;
}

QMap<QString, float *> *load_and_save::getInfoenemy() const
{
    return infoenemy;
}

void load_and_save::save(QString nombreArch)
{
    if (!nombreArch.isEmpty()) {
        QString extension;
        for (int i = (nombreArch.length()-1); i > (nombreArch.length()-6)  ; i-- ) {
            extension.push_front(nombreArch[i]);
        }
        if (extension != ".hell") {
            nombreArch.push_back(".hell");
        }
        QFile arch(nombreArch);
        if (arch.open(QIODevice::WriteOnly)) {
            QTextStream in(&arch);
            in << estado << "\n";
            in << mundo << "\n";
            for (auto it : personajes) {
                in << int(it->x()) << " " << int(it->y()) << " " << it->vida << " " << num_vidas << "\n";
            }
            in << puntos << "\n";
            QMap<QString, float *>::iterator it = infoenemy->begin();
            for( ; it != infoenemy->end(); it++ ){
                in << it.key() << " ";
                in << it.value()[0] << " ";
                in << it.value()[1] << " ";
                in << it.value()[2] << " ";
                in << it.value()[3] << " ";
                in << it.value()[4] << " ";
                in << it.value()[5] << " ";
                for (int num_enemigo = 0, indice_dato = 6; num_enemigo < it.value()[3] ; num_enemigo++, indice_dato+=2) {
                    in << it.value()[indice_dato] << " ";
                    if (num_enemigo != (it.value()[3]-1)) {
                        in << it.value()[indice_dato+1] << " ";
                    }
                    else {
                        in << it.value()[indice_dato+1];
                    }
                }
                in << "\n";
            }
            in << "zona_bloquada" << "\n";
            for (auto it : *zona_blocked) {
                in << it->w << " " << it->h << " " << it->posx << " " << it->posy << "\n";
            }
        }
        arch.flush();
        arch.close();
    }
    else {
        QMessageBox::critical(mainwindow, "Error", "No ingreso nombre");
    }
}

load_and_save::~load_and_save()
{

}
