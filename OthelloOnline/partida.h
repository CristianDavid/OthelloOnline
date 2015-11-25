#ifndef PARTIDA_H
#define PARTIDA_H

#define JUGADOR_NEGRO 'X'
#define JUGADOR_BLANCO 'O'
#define LUGAR_VACIO '.'
#define ALTO_TABLERO 8
#define ANCHO_TABLERO 8
#define HORIZONTAL 0
#define VERTICAL 1
/*Se refiere a una linea que 
se creta desde NOROESTE hacia sureste*/
#define NOROESTE 2
/* se refiere a una linea que 
se crea dede sureste hacia noreste*/
#define SUROESTE 3

#include <string>
#include <string.h>
#include <vector>

using namespace std;
class Partida{
    char tablero[ANCHO_TABLERO][ALTO_TABLERO];
    //jugadorRemoto
    //JugadorLocal
    //para pruebas.
private:
	std::vector<std::string> split(string s, int posicion);
public:
    void imprimirTablero();
    std::string obtenerLinea(int x, int y , int direccion);
    bool esLaLineaValida(char jugador,int y, std::string linea);
    void hacerMovimiento(int x, int y , char jugador);
    Partida();
    bool esMovimientoValido(int x, int y);

};

#endif // PARTIDA_H
