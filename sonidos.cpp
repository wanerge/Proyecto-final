#include "sonidos.h"

sonidos::sonidos()
{
    musicafondo = new QMediaPlaylist();
    musica = new QMediaPlayer();
    sonido1 = new QMediaPlayer();
}

void sonidos::sonidosfondo(QString eleccion)
{
    if(eleccion == "menu" and ultimosong != "menu"){
        if(musica->isAudioAvailable()){
            musica->stop();
            musicafondo->clear();
        }
        musicafondo->addMedia(QUrl("qrc:/sonidos/musica_menu.mp3"));
        musicafondo->setPlaybackMode(QMediaPlaylist::Loop);
        musica->setPlaylist(musicafondo);
        musica->setVolume(10);
        musica->play();
        ultimosong = "menu";
    }
    else if(eleccion == "jugar" and ultimosong != "jugar"){
        if(musica->isAudioAvailable()){
            musica->stop();
            musicafondo->clear();
        }
        musicafondo->addMedia(QUrl("qrc:/sonidos/musica_juego.mp3"));
        musicafondo->setPlaybackMode(QMediaPlaylist::Loop);
        musica->setPlaylist(musicafondo);
        musica->play();
        ultimosong = "jugar";
    }
}

void sonidos::sonidosvarios(QString eleccion)
{
    if(eleccion == "bala"){
        sonido1->setMedia(QUrl("qrc:/sonidos/bala.mp3"));
        sonido1->setVolume(60);
        if(sonido1->state() == QMediaPlayer::PlayingState){
            sonido1->setPosition(0);
        }
        else if(sonido1->state() == QMediaPlayer::StoppedState){
            sonido1->play();
        }
    }

    else if(eleccion == "grito"){
        sonido1->setVolume(100);
        sonido1->setMedia(QUrl("qrc:/sonidos/grito_hombre.mp3"));
        sonido1->play();
    }
    else if(eleccion == "gameover"){
        sonido1->setVolume(100);
        sonido1->setMedia(QUrl("qrc:/sonidos/game_over.mp3"));
        sonido1->play();
    }
}

sonidos::~sonidos()
{
    delete musicafondo;
    delete musica;
    delete sonido1;

}
