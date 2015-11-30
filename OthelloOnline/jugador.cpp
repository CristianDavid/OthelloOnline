#include "jugador.h"
#include <cstring>
#include "partida.h"

Jugador::~Jugador() {
}

void Jugador::setNombre(const char *nombre) {
   strncpy(this->nombre, nombre, 255);
}

const char *Jugador::getNombre() {
   return nombre;
}

void Jugador::setColor(char color) {
   this->color = color;
}

char Jugador::getColor() {
   return color;
}

void Jugador::setPuntaje(int puntaje) {
   this->puntaje = puntaje;
}

int Jugador::getPuntaje() {
   return puntaje;
}
