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

bool Partida::esMovimientoValido(int x, int y, char jugador){
    bool movimientoValido=false;
    std::vector<int> vector;
    if (tablero[x][y]==LUGAR_VACIO){
    	/*Buscando en todas las direcciones desde las cordenadas (x,y) para ver
			si hay algún movimiento valido*/
    	for (int i = 0; i <= SUROESTE; ++i)	{
    		vector=posicionesACambiar(jugador,y,obtenerLinea(x,y,i));
    		if (vector.empty()){
    			movimientoValido=true;
    			break;
    		}
    	}
    }
    return movimientoValido;
}

void Partida::imprimirTablero(){
	cout << " ";
	for (int i = 0; i < ANCHO_TABLERO; ++i) {
		cout << i << "|";
	}
	cout << endl;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
    	cout << i;
        for (int j = 0; j < ALTO_TABLERO; ++j) {
            cout << tablero[i][j]<< "|";
        }
        cout << endl;
    }
}

//Te devuelve una linea del tablero dependiedo de la direccion 
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

//Te devuelve las posiciones en una linea que cambiarian.
vector<int> Partida::posicionesACambiar(char jugador,int y, std::string linea){
	bool esValida;
	char contrario;
	contrario=(jugador==JUGADOR_NEGRO)?JUGADOR_BLANCO:JUGADOR_NEGRO;
	vector<string> v=split(linea,y);
	string parteUno,parteDos;
	parteUno = v.at(0);
	parteDos = v.at(1);
	std::vector<int> posiciones;
	std::vector<int> temp;


	if (y+1>linea.length()){
		cout << "ERROR: NO PUEDES PASAR UN X MAYOR QUE LA CADENA" << endl;
	}
	else{
		if (linea.length()>=3){
			//Primera cadena.
			int j=(parteUno.length()-1)-1;
			if (parteUno[j]==contrario){
				while(j>0 && parteUno[j]==contrario ){
					temp.push_back(j);
					j--;
				}
				if(j>=0 && parteUno[j]==jugador ){
					posiciones.push_back(y);
					for (int k =0 ; k < temp.size();k++){
						posiciones.push_back(temp.at(k));
					}
				}

			}
			//Segunda cadena
			temp.clear();
			int i=1;
			if (parteDos[i]==contrario){
				while(i<parteDos.length() && parteDos[i]==contrario ){
					i++;
					temp.push_back(i+y-1);
					temp.push_back(y);
				}
				if(i<parteDos.length() && parteDos[i]==jugador ){
					for (int k =0 ; k < temp.size();k++){
						posiciones.push_back(temp.at(k));
					}
				}

			}
		}
	}
	return posiciones;
}

void Partida::hacerMovimiento(int x, int y , char jugador){
	if (esMovimientoValido(x,y,jugador)){
		//Horizontal
		std::vector<int> v;
		v= posicionesACambiar(jugador,y,obtenerLinea(x,y,HORIZONTAL));
		for (int i =0 ; i< v.size(); i++){
			tablero[x][v.at(i)]=JUGADOR_BLANCO;
		}
		v.clear();
		//Vertical
		v= posicionesACambiar(jugador,x,obtenerLinea(x,y,VERTICAL));
		for (int i =0 ; i< v.size(); i++){
			tablero[v.at(i)][y]=JUGADOR_BLANCO;
		}
		v.clear();
		//NOROESTE
		v= posicionesACambiar(jugador,x,obtenerLinea(x,y,NOROESTE));
		int c,d,i;
		c=x;
		d=y;
		while ((c!=0) && (d!=0) ){
			d--;
			c--;
		}
		sort(v.begin(),v.end());
		v.erase( unique( v.begin(), v.end() ), v.end() );
		for (i=0; c<ANCHO_TABLERO && d < ALTO_TABLERO; c++,d++,i++){
			if (find(v.begin(), v.end(), i) != v.end()){
				
				tablero[c][d]=jugador;
			}
		}
		v.clear();
		//SUROESTE
		v= posicionesACambiar(jugador,x,obtenerLinea(x,y,SUROESTE));
		c=x;
		d=y;
		sort(v.begin(),v.end());
		v.erase( unique( v.begin(), v.end() ), v.end() );
		while(c!=0){
			c--;
			d++;
		}
		for (i=0; c<ANCHO_TABLERO && d<ALTO_TABLERO && d!=-1; c++,d--,i++){
			if (find(v.begin(), v.end(), i) != v.end()){	
				tablero[c][d]=jugador;
			}
		}


	}
	else{
		cout << "NO ES MOVIMIENTO VALIDO"<< endl;
	}
}

/*Metodo de utileria para dividir la cadena en dos, las dos cadenas
 incluyen el char en "posicion"*/
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
//Solo para hacer pruebas mientra creo hacer movimiento
// void Partida::mierda(int x, int y , char jugador){
// 	tablero[x][y]=jugador;
// }


char** Partida::dameTablero(){
  char** array2D = 0;
  array2D = new char*[ANCHO_TABLERO];

  for (int h = 0; h < ALTO_TABLERO; h++){
        array2D[h] = new char[ANCHO_TABLERO];
        for (int w = 0; w < ANCHO_TABLERO; w++){
              array2D[h][w] = tablero[h][w];
        }
  }
  return array2D;
}