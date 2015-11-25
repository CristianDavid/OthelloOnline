#include "jugadorlocal.h"
#include "vistajuego.h"
#include "boardscene.h"

JugadorLocal::JugadorLocal(const char *nombre) :
   proximoMovimiento(-1) {
   setNombre(nombre);
}

int JugadorLocal::hacerMovimiento() {
   return proximoMovimiento;
}

void JugadorLocal::notificarMovimiento(int movimientoAdversario) {
}
