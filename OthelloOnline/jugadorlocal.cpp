#include <QObject>
#include <QColor>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "jugadorlocal.h"
#include "boardscene.h"
#include "jugadorremoto.h"

#define OFRECER_TABLAS 100
#define ACEPTAR_TABLAS 101

JugadorLocal::JugadorLocal(BoardScene *juego, const char *nombre, Partida *partida, JugadorRemoto *oponente) :
   juego(juego),
   partida(partida),
   proximoMovimiento(-1),
   oponente(oponente) {
   setNombre(nombre);
   juego->setNombreJugadorLocal(getNombre());
   juego->setNombreJugadorRemoto(oponente->getNombre());
   actualizarTablero();
   connect(juego, SIGNAL(casillaClick(int,int)), this, SLOT(hacerMovimientoLocal(int,int)));
   connect(&timerRecibirMovimiento, SIGNAL(timeout()), this, SLOT(hacerMovimientoRemoto()));
   connect(&timerReenvio, SIGNAL(timeout()), this, SLOT(reintentarMovimiento()));
   movimientoPendiente = -1;
   if (oponente->getColor() == JUGADOR_NEGRO) {
      setColor(JUGADOR_BLANCO);
   } else {
      setColor(JUGADOR_NEGRO);
   }
   if (getColor() == JUGADOR_NEGRO) {
      esTurnoLocal = true;
   } else {
      esTurnoLocal = false;
   }
   juego->ponerIndicador(esTurnoLocal);
   if (!esTurnoLocal) {
      timerRecibirMovimiento.start(500);
   }
}

JugadorLocal::~JugadorLocal() {
   delete juego;
   delete partida;
   delete oponente;
}

int JugadorLocal::hacerMovimiento() {//heredado pero inútil por ahora
   return 0;
}

int JugadorLocal::notificarMovimiento(int movimiento) { // heredado pero sin uso
   return movimiento;
}

void JugadorLocal::actualizarTablero() {
   char **tablero = partida->dameTablero();
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         if (tablero[i][j] == JUGADOR_NEGRO) {
            juego->ponerFicha(i, j, Qt::black);
         } else if (tablero[i][j] == JUGADOR_BLANCO) {
            juego->ponerFicha(i, j, Qt::white);
         }
      }
   }
}

void JugadorLocal::hacerMovimientoLocal(int i, int j) {
   int res;
   if (movimientoPendiente != -1) return;
   if (!esTurnoLocal) return;
   if (partida->esMovimientoValido(i, j, getColor())) {
      movimientoPendiente = i*8 + j;
      partida->hacerMovimiento(i, j, getColor());
      actualizarTablero();
      res = oponente->notificarMovimiento(movimientoPendiente);
      if (res == -1) {
         QMessageBox mensajeError;
         mensajeError.setText("(81:Error al enviar movimiento");
         mensajeError.exec();
         delete this;
         return;
      }
      if (res == -2) {
         timerReenvio.start(500);
         return;
      }
      movimientoPendiente = -1;
      esTurnoLocal = false;
      timerRecibirMovimiento.start(500);
      juego->ponerIndicador(esTurnoLocal);
   }
}

void JugadorLocal::hacerMovimientoRemoto() {
   if (esTurnoLocal) return;
   int movimiento = oponente->hacerMovimiento();
   if (movimiento == -1) {
      QMessageBox mensajeError;
      mensajeError.setText("101:Ha habido un error en la red");
      mensajeError.exec();
      delete this;
      return;
   }
   if (movimiento == -2) return;
   int i = movimiento / 8;
   int j = movimiento % 8;
   if (!partida->esMovimientoValido(i, j, oponente->getColor())) {
      QMessageBox mensajeError;
      mensajeError.setText("110:El oponente envío en mensaje inválido");
      mensajeError.exec();
      delete this;
      return;
   }
   if (movimiento != -2) {
      partida->hacerMovimiento(i, j, oponente->getColor());
      actualizarTablero();
      esTurnoLocal = true;
      timerRecibirMovimiento.stop();
      juego->ponerIndicador(esTurnoLocal);
   }
}

void JugadorLocal::reintentarMovimiento() {
   qDebug()<<"triste realidad";
   if (!esTurnoLocal) return;
   if (movimientoPendiente == -1) return;
   int res = oponente->notificarMovimiento(movimientoPendiente);
   if (res == -1) {
      QMessageBox mensajeError;
      mensajeError.setText("Error al enviar movimiento");
      mensajeError.exec();
      delete this;
      return;
   }
   if (res != -2) {
      timerReenvio.stop();
      movimientoPendiente = -1;
      esTurnoLocal = false;
      juego->ponerIndicador(esTurnoLocal);
      timerRecibirMovimiento.start(500);
      return;
   }
}
