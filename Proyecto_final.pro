QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullets.cpp \
    bullets_enemy.cpp \
    button.cpp \
    colisiones.cpp \
    enemigos.cpp \
    interfaz_inicio.cpp \
    interfaz_pausa.cpp \
    jefe.cpp \
    life.cpp \
    load_and_save.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    personaje_principal.cpp \
    powerboss.cpp \
    spawn.cpp \
    transiciones.cpp \
    zonas_especiales.cpp

HEADERS += \
    bullets.h \
    bullets_enemy.h \
    button.h \
    colisiones.h \
    enemigos.h \
    interfaz_inicio.h \
    interfaz_pausa.h \
    jefe.h \
    life.h \
    load_and_save.h \
    mainwindow.h \
    mapa.h \
    personaje_principal.h \
    powerboss.h \
    spawn.h \
    transiciones.h \
    zonas_especiales.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
