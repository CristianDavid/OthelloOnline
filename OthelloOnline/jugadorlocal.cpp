#include "jugadorlocal.h"
#include "boardscene.h"

JugadorLocal::JugadorLocal(BoardScene *juego, const char *nombre, Partida &partida) :
   juego(juego),
   partida(partida),
   proximoMovimiento(-1) {
   setNombre(nombre);
}

int JugadorLocal::hacerMovimiento() {
   while (proximoMovimiento == -1) continue;
   return proximoMovimiento;
}

int JugadorLocal::notificarMovimiento(int movimientoAdversario) {
   return -1;
}
