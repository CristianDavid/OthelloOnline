#include "partida.h"
#include <string>
#include <iostream>

using namespace std;

Partida::Partida(){
    int i,j;
    for (i = 0; i< ANCHO_TABLERO; i++){
        for (j=0; j< ALTO_TABLERO; j++){
            tablero[i][j]=LUGAR_VACIO;
        }
    }
    tablero[ANCHO_TABLERO/2 -1][ANCHO_TABLERO/2 -1]=JUGADOR_BLANCO;
    tablero[ANCHO_TABLERO/2][ANCHO_TABLERO/2]=JUGADOR_BLANCO;
    tablero[ANCHO_TABLERO/2][ANCHO_TABLERO/2-1]=JUGADOR_NEGRO;
    tablero[ANCHO_TABLERO/2-1][ANCHO_TABLERO/2]=JUGADOR_NEGRO;
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

bool Partida::esLaLineaValida(char jugador,int y, std::string linea){
	bool esValida;
	char contrario;
	contrario=(jugador==JUGADOR_NEGRO)?JUGADOR_BLANCO:JUGADOR_NEGRO;
	vector<string> v=split(linea,y);
	string parteUno,parteDos;
	parteUno = v.at(0);
	parteDos = v.at(1);

	if (y+1>linea.length()){
		cout << "ERROR: NO PUEDES PASAR UN X MAYOR QUE LA CADENA" << endl;
	}
	else{
		if (linea.length()>=3){
			//Primera cadena.
			cout << "Primera cadena :" << parteUno << "|";
			int j=(parteUno.length()-1)-1;
			if (parteUno[j]==contrario){
				while(j>0 && parteUno[j]==contrario ){
					cout << j<< "*j*" <<endl;
					j--;
				}
				if(j>=0 && parteUno[j]==jugador ){
					esValida=true;
					cout << "true";
				}

			}
			else{
				esValida=false;
			}


			//Segunda cadena
			cout << "Segunda cadena:" << parteDos << "|";
			if(esValida==false){
				int i=1;
				if (parteDos[i]==contrario){
					while(i<parteDos.length() && parteDos[i]==contrario ){
						i++;
						cout << i+y<< "*i*" <<endl;
					}
					if(i<parteDos.length() && parteDos[i]==jugador ){
						esValida=true;
						cout << "true";
					}

				}
				else{
					esValida=false;
				}
				
			}

		}
		else 
			esValida=false;
	}
	return esValida;
}

void Partida::hacerMovimiento(int x, int y , char jugador){
	tablero[x][y]=jugador;
}


vector<string> Partida::split(string s, int posicion){
	// =(
	std::vector<string> v;
	char cadena[s.length()+1];
	char cadenaUno[s.length()+1], cadenaDos[s.length()+1];

	strcpy (cadena,s.c_str());
	strncpy (cadenaUno,cadena,posicion+1);
	strncpy (cadenaDos,cadena+posicion,s.length());

	cadenaUno[posicion+1]=0;
	cadenaDos[s.length()]=0;

	string stringUno(cadenaUno);
	string stringDos(cadenaDos);
	v.push_back(cadenaUno);
	v.push_back(cadenaDos);
	return v;
}