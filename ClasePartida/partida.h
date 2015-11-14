#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>

#define JUGADOR_NEGRO 'X'
#define JUGADOR_BLANCO 'O'
#define LUGAR_VACIO '.'
#define ALTO_TABLERO 8
#define ANCHO_TABLERO 8


class Partida{
    char tablero[ANCHO_TABLERO][ALTO_TABLERO];
    //jugadorRemoto
    //JugadorLocal

public:
    Partida();
    bool esMovimientoValido(int x, int y);
};

#endif // PARTIDA_H
