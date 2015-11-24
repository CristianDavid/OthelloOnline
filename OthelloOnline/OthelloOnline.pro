#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T18:50:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = OthelloOnline
TEMPLATE = app


SOURCES += main.cpp \
    vistajuego.cpp \
    boardscene.cpp \
    boardhandler.cpp \
    squareitem.cpp \
    mainview.cpp \
    unirseapatridadialog.cpp \
    partida.cpp

HEADERS  += \
    vistajuego.h \
    boardscene.h \
    boardhandler.h \
    squareitem.h \
    mainview.h \
    unirseapatridadialog.h \
    jugador.h \
    partida.h

FORMS    += \
    vistajuego.ui \
    unirseapatridadialog.ui
