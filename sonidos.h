#ifndef SONIDOS_H
#define SONIDOS_H
#include <QMediaPlayer>
#include <QMediaPlaylist>

class sonidos
{
private:
    QMediaPlaylist *musicafondo;
    QMediaPlayer *musica;
    QMediaPlayer *sonido1;
    QString ultimosong = "nada";
public:
    sonidos();
    void sonidosfondo(QString eleccion);
    void sonidosvarios(QString eleccion);
    ~sonidos();

};

#endif // SONIDOS_H
