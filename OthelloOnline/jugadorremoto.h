#ifndef JUGADORREMOTO_H
#define JUGADORREMOTO_H

#include "jugador.h"
#include "conexionred.h"

class JugadorRemoto : public Jugador {
public:
   JugadorRemoto(ConexionRed *conexion);
   ~JugadorRemoto();
   int hacerMovimiento();
   int notificarMovimiento(int movimientoAdversario);
private:
   ConexionRed *conexion;
};

#endif // JUGADORREMOTO_H
