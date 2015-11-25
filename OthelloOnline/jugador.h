#ifndef JUGADOR_INCLUDED
#define JUGADOR_INCLUDED

class Jugador {
 public:
   virtual ~Jugador();
   virtual int hacerMovimiento() = 0;
   virtual void notificarMovimiento(int movimientoAdversario) = 0;
   void setNombre(const char *nombre);
   const char *getNombre();
 private:
   char nombre[256];
};

#endif // JUGADOR_INCLUDED
