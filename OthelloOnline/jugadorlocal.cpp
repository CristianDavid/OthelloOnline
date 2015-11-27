#include "jugadorlocal.h"
#include "boardscene.h"

JugadorLocal::JugadorLocal(BoardScene *juego, const char *nombre, Partida &partida) :
   juego(juego),
   proximoMovimiento(-1),
   partida(partida) {
   setNombre(nombre);
}

int JugadorLocal::hacerMovimiento() {
   while (proximoMovimiento == -1) continue;
   return proximoMovimiento;
}

void JugadorLocal::notificarMovimiento(int movimientoAdversario) {
}
