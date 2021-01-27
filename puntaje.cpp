#include "puntaje.h"

puntaje::puntaje(QMainWindow *mainwindow, int x_, int y_)
{
    label = new QLabel(mainwindow);
    label->setGeometry(x_, y_, 200, 35);

    QFont font = label->font();
    font.setFamily("Comic Sans MS");
    font.setPointSize(30);
    label->setFont(font);

    QPalette pal = label->palette();
    pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
    label->setPalette(pal);

    label->setText(QString::number(0));
    label->show();
}

void puntaje::actualizar(int *puntos)
{
    label->setText(QString::number(*puntos));
}


puntaje::~puntaje()
{
    delete label;
}

