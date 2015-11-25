#ifndef CONEXIONRED_H
#define CONEXIONRED_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
//Pesa 3 bytes
struct cabecera{
	//Cabecera
    char letraUnoPotrocolo;
    char letraDosPotrocolo;
    unsigned char version :8;
};
//Pesa 1 byte
struct respuestaServidor{
	unsigned char sinUsar :3;
	unsigned char varianteReversi :3;
	unsigned char quienIniciaPartida :1;
	unsigned char reconoceVersion :1;
};

//2 bytes
struct paqueteJuego{
	char numeroMovimiento;
	char movimiento; 

};

class conexionRed{
	int sockfd;
public:
    conexionRed(char * ip, short puerto);
};

#endif // CONEXIONRED_H
