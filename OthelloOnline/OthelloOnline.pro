#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T18:50:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OthelloOnline
TEMPLATE = app


SOURCES += main.cpp \
    vistajuego.cpp \
    boardscene.cpp \
    boardhandler.cpp \
    squareitem.cpp

HEADERS  += \
    vistajuego.h \
    boardscene.h \
    boardhandler.h \
    squareitem.h

FORMS    += \
    vistajuego.ui
