#ifndef JUGADOR_INCLUDED
#define JUGADOR_INCLUDED

class Jugador {
 public:
   int hacerMovimiento();
   void notificarMovimiento(int movimientoAdversario);
 private:
   char nombre[256];
};

#endif // JUGADOR_INCLUDED
