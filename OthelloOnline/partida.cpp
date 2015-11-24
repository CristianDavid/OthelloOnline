#include "partida.h"
#include <string>
#include <iostream>

using namespace std;

//TODO:FALTA VALIDAR LA EXPRESION DE CADENA VALIDA

Partida::Partida(){
    int i,j;
    for (i = 0; i< ANCHO_TABLERO; i++){
        for (j=0; j< ALTO_TABLERO; j++){
            tablero[i][j]=LUGAR_VACIO;
        }
    }
    tablero[3][3]=JUGADOR_BLANCO;
    tablero[4][4]=JUGADOR_BLANCO;
    tablero[4][3]=JUGADOR_NEGRO;
    tablero[3][4]=JUGADOR_NEGRO;
    imprimirTablero();
}

bool Partida::esMovimientoValido(int x, int y){
    bool movimientoValido;
    if (tablero[x][y]==LUGAR_VACIO){

    }
    else movimientoValido=false;
    return movimientoValido;
}

void Partida::imprimirTablero(){
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int j = 0; j < ALTO_TABLERO; ++j) {
            cout << tablero[i][j]<< "|";
        }
        cout << endl;
    }
}

string Partida::obtenerLinea(int x , int y, int direccion){
	//Tal vez deberia separar este metodo.
	char cadena[ALTO_TABLERO+1];
	int i;
	switch(direccion){
		case HORIZONTAL:
			for (i =0 ; i< ANCHO_TABLERO; i++){
				cadena[i]=tablero[x][i];
			}
		break;
		case VERTICAL:
			for (i = 0; i < ALTO_TABLERO; ++i){
				cadena[i]=tablero[i][y];
			}
		break;
		case NOROESTE:
			while ((x!=0) && (y!=0) ){
				y--;
				x--;
			}
			for (i=0; x<ANCHO_TABLERO && y < ALTO_TABLERO; x++,y++,i++){
				cadena[i]=tablero[x][y];
			}
			if (i<ANCHO_TABLERO)
				cadena[i]=0;
		break;
		case SUROESTE:
			while(x!=0){
				x--;
				y++;
			}
			for (i=0; x<ANCHO_TABLERO && y<ALTO_TABLERO && y!=-1; x++,y--,i++){
				cadena[i]=tablero[x][y];
			}
			if (i<ANCHO_TABLERO)
				cadena[i]=0;

		break;
	}
	string lineaDeseada(cadena);
	return lineaDeseada;
}

bool Partida::esLaLineaValida(char jugador,int x, std::string linea){
	//FALTA TERMINAR
	bool esValida;
	char contrario;
	contrario=(jugador==JUGADOR_NEGRO)?JUGADOR_BLANCO:JUGADOR_NEGRO;
	if (x+1>linea.length()){
		cout << "ERROR: NO PUEDES PASAR UN X MAYOR QUE LA CADENA" << endl;
	}
	else{
		if (linea.length()>=3){
			//Automata equivalente a .*x*o*x
			for (int i =0 ; i < linea.length(); i++){
				for (int j = i; j < linea.length(); ++j){
					
				}

			}
		}
		else 
			esValida=false;
		
	}
	return esValida;
}
