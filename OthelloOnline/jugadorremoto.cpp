#include "jugadorremoto.h"

JugadorRemoto::JugadorRemoto(ConexionRed *conexion) :
 conexion(conexion) {
   setNombre(conexion->getRemoteName());
}

JugadorRemoto::~JugadorRemoto() {
   delete conexion;
}

int JugadorRemoto::hacerMovimiento() {
   return conexion->recibirMovimiento();
}

int JugadorRemoto::notificarMovimiento(int movimientoAdversario) {
   return conexion->hacerMovimiento(movimientoAdversario);
}


