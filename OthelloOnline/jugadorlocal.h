#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include "jugador.h"
#include "boardscene.h"

class JugadorLocal : public Jugador {
public:
   JugadorLocal(BoardScene *juego, const char *nombre);
   int hacerMovimiento();
   void notificarMovimiento(int movimientoAdversario);
private:
   BoardScene *juego;
   int proximoMovimiento;
};

#endif // JUGADORLOCAL_H
