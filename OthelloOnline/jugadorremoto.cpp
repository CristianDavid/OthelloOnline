#include "jugadorremoto.h"
#include "partida.h"

JugadorRemoto::JugadorRemoto(ConexionRed *conexion) :
 conexion(conexion) {
   setNombre(conexion->getRemoteName());
   if (conexion->isServer()) {
      setColor(JUGADOR_BLANCO);
   } else {
      setColor(JUGADOR_NEGRO);
   }
}

JugadorRemoto::~JugadorRemoto() {
   delete conexion;
}

int JugadorRemoto::hacerMovimiento() {
   int res = conexion->recibirMovimiento();
   if (res == -1 && conexion->shouldRetry()) {
      res = -2;
   }
   return res;
}

int JugadorRemoto::notificarMovimiento(int movimientoAdversario) {
   int res = conexion->hacerMovimiento(movimientoAdversario);
   if (res == -1 && conexion->shouldRetry()) {
      res = -2;
   }
   return res;
}
