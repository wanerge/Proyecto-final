#ifndef SONIDOS_H
#define SONIDOS_H
#include <QMediaPlayer>
#include <QMediaPlaylist>

class sonidos
{
private:
    //Variable QmediaPlaylist para hacer un loop en el sondio de fondo
    QMediaPlaylist *musicafondo;

    //Variable QmediaPlayer que reproducira la QmediaPlaylist
    QMediaPlayer *musica;

    //Variable QmediaPlayer que reproducira sonidos varios
    QMediaPlayer *sonido1;
    QString ultimosong = "nada";
public:
    sonidos();
    //Funcion que detecta si se reproduce musica del menu o del juego
    void sonidosfondo(QString eleccion);

    //Funcion que detecta una accion en el juego para reproducir un sonido
    void sonidosvarios(QString eleccion);

    //destructor
    ~sonidos();

};

#endif // SONIDOS_H
