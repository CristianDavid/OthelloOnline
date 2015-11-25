#include "jugador.h"
#include <cstring>

Jugador::~Jugador() {
}

void Jugador::setNombre(const char *nombre) {
   strncpy(this->nombre, nombre, 255);
}

const char *Jugador::getNombre() {
   return nombre;
}
