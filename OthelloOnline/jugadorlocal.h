#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include <QObject>
#include "boardscene.h"
#include "partida.h"
#include "jugadorremoto.h"

class JugadorLocal : public QObject, public Jugador {
   Q_OBJECT
public:
   JugadorLocal(BoardScene *juego, const char *nombre, Partida *partida, JugadorRemoto *oponente);
   int hacerMovimiento();
   int notificarMovimiento(int movimientoAdversario);
   ~JugadorLocal();
private:
   BoardScene *juego;
   Partida *partida;
   int proximoMovimiento;
   JugadorRemoto *oponente;
signals:
public slots:
   void hacerMovimientoLocal(int i, int j);
};

#endif // JUGADORLOCAL_H
