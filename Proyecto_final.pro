QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullets.cpp \
    button.cpp \
    colisiones.cpp \
    enemigos.cpp \
    interfaz_inicio.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    personaje_principal.cpp \
    spawn.cpp

HEADERS += \
    bullets.h \
    button.h \
    colisiones.h \
    enemigos.h \
    interfaz_inicio.h \
    mainwindow.h \
    mapa.h \
    personaje_principal.h \
    spawn.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
