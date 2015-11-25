#include "jugadorlocal.h"
#include "vistajuego.h"
#include "boardscene.h"

JugadorLocal::JugadorLocal(BoardScene *juego, const char *nombre) :
   juego(juego),
   proximoMovimiento(-1) {
   setNombre(nombre);
}

int JugadorLocal::hacerMovimiento() {
   while (proximoMovimiento == -1) continue;
   return proximoMovimiento;
}

void JugadorLocal::notificarMovimiento(int movimientoAdversario) {
}
