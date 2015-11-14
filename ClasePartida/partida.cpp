#include "partida.h"

using namespace std;
Partida::Partida()
{
    int i,j;
    for (i = 0; i< ANCHO_TABLERO; i++){
        for (j=0; j< ALTO_TABLERO; j++){
            tablero[i][j]=LUGAR_VACIO;
        }
    }

}

bool Partida::esMovimientoValido(int x, int y){

}
