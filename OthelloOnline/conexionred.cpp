#include "conexionred.h"

conexionRed::conexionRed(char * ip, short puerto){

	int n = 0;
	struct sockaddr_in serv_addr; 
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("\n Error : Could not create socket \n");
	} 
	memset(&serv_addr, '0', sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(puerto); 
	if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0){
		printf("\n inet_pton error occured\n");
	} 
	if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\n Error : Connect Failed \n");
	} 
}
