#include <QObject>
#include <QColor>
#include "jugadorlocal.h"
#include "boardscene.h"
#include "jugadorremoto.h"

JugadorLocal::JugadorLocal(BoardScene *juego, const char *nombre, Partida *partida, JugadorRemoto *oponente) :
   juego(juego),
   partida(partida),
   proximoMovimiento(-1),
   oponente(oponente) {
   setNombre(nombre);
   connect(juego, SIGNAL(casillaClick(int,int)), this, SLOT(hacerMovimientoLocal(int,int)));
}

JugadorLocal::~JugadorLocal() {

}

int JugadorLocal::hacerMovimiento() {
   return 0;
}

int JugadorLocal::notificarMovimiento(int movimiento) {
   QColor colorFicha = (oponente->getColor() == JUGADOR_BLANCO)? Qt::white : Qt::black;
   if (partida->esMovimientoValido(movimiento / 8, movimiento % 8, oponente->getColor())) {
      juego->ponerFicha(movimiento / 8, movimiento % 8, colorFicha);
      return 1;
   } else {
      return -1;
   }
}

void JugadorLocal::hacerMovimientoLocal(int i, int j) {
   if (partida->esMovimientoValido(i, j, getColor())) {
      oponente->notificarMovimiento(i*8 + j);
      juego->ponerFicha(i, j, (getColor() == JUGADOR_BLANCO)? Qt::white : Qt::black);
   }
}
