#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include "jugador.h"

class JugadorLocal : public Jugador {
public:
   JugadorLocal(const char *nombre);
   int hacerMovimiento();
   void notificarMovimiento(int movimientoAdversario);
private:
   int proximoMovimiento;
};

#endif // JUGADORLOCAL_H
