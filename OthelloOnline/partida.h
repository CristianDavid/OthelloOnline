#ifndef PARTIDA_H
#define PARTIDA_H

#define JUGADOR_NEGRO  'X'
#define JUGADOR_BLANCO 'O'
#define LUGAR_VACIO    '.'

#define ALTO_TABLERO  8
#define ANCHO_TABLERO 8

#include <string>
#include <vector>

class JugadorRemoto;
class JugadorLocal;

class Partida {
    char tablero[ANCHO_TABLERO][ALTO_TABLERO];
    JugadorRemoto *jugadorRemoto;
    JugadorLocal *jugadorLocal;
private:
   std::vector<std::string> split(std::string s, int posicion);
public:
    Partida();
    std::string obtenerLinea(int x, int y , int direccion);
    std::vector<int> posicionesACambiar(char jugador,int y,std::string linea);
    bool esMovimientoValido(int x, int y, char jugador);
    char** dameTablero();
    void imprimirTablero();
    void hacerMovimiento(int x, int y , char jugador);
    //Solo para hacer pruebas mientra hago hacerMoviemtno
    // void mierda(int x, int y , char jugador);

};

#endif // PARTIDA_H
