#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include "jugador.h"

class JugadorLocal : public Jugador {
public:
   JugadorLocal();
private:
   int proximoMovimiento;
};

#endif // JUGADORLOCAL_H
