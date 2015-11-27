#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include "jugador.h"
#include "boardscene.h"
#include "partida.h"

class JugadorLocal : public Jugador {
public:
   JugadorLocal(BoardScene *juego, const char *nombre, Partida &partida);
   int hacerMovimiento();
   int notificarMovimiento(int movimientoAdversario);
private:
   BoardScene *juego;
   Partida &partida;
   int proximoMovimiento;
};

#endif // JUGADORLOCAL_H
