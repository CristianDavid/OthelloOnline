#include "conexionred.h"

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>

using namespace std;

ConexionRed::ConexionRed(const char * ip, short puerto) {
   this->host   = new char[256];
   this->puerto = puerto;
   this->clientSocket = -1;
   this->_isOpen = false;
   this->remoteName[0] = '\0';
   this->serverSocket = -1;
   strcpy(host, ip);
}

ConexionRed::ConexionRed() { // inicializar como servidor
   this->host   = NULL;
   this->puerto = OTHELLO_ONLINE_DEFAULT_PORT;
   this->clientSocket = -1;
   this->_isOpen = false;
   this->remoteName[0] = '\0';
   this->serverSocket = -1;
   if (startListening() == -1)
      perror("Error al poner a la escucha");
}

ConexionRed::~ConexionRed() {
   close();
}

bool ConexionRed::start(const char *localName) {
   if (host == NULL) {
      _isOpen = startAsServer(localName);
   } else {
      _isOpen = startAsClient(localName);
   }
   return _isOpen;
}

const char *ConexionRed::getRemoteName() {
   delete [] host;
   return remoteName;
}

int ConexionRed::hacerMovimiento(char movimiento) {
   int res = send(clientSocket, &movimiento, 1, 0);
   if (res == -1) {
      _shouldRetry = (errno == EAGAIN || errno == EWOULDBLOCK);
      if (!shouldRetry()) {
         perror("Error al enviar movimiento");
         close();
      }
   } else if (res == 0) {
      _shouldRetry = false;
      close();
   }
   return res;
}

int ConexionRed::recibirMovimiento() {
   char movimiento;
   int res;
   res = recv(clientSocket, &movimiento, 1, 0);
   if (res == -1) {
      _shouldRetry = (errno == EAGAIN || errno == EWOULDBLOCK);
      if (!shouldRetry()) {
         perror("Error al recibir movimiento");
         close();
      }
      return res;
   } else if (res == 0) {
      close();
      _shouldRetry = false;
      return -1;
   } else {
      return movimiento;
   }
}

bool ConexionRed::isOpen() {
   return _isOpen;
}

bool ConexionRed::shouldRetry() {
   return _shouldRetry;
}

void ConexionRed::close() {
   if (clientSocket != -1) {
      ::close(clientSocket);
      clientSocket = -1;
      _isOpen = false;
   }
}

bool ConexionRed::startAsServer(const char *localName) {
   if (serverSocket == -1) {
      startListening();
   }
   if (serverSocket == -1) {
      perror("Error al comenzar escuha");
      _shouldRetry = true;
      return false;
   }
   clientSocket = accept(serverSocket, NULL, NULL);
   if (clientSocket == -1) {
      _shouldRetry = (errno == EAGAIN || errno == EWOULDBLOCK);
      if (!shouldRetry()) {
         perror("Error al aceptar cliente");
         ::close(serverSocket);
         close();
      }
      return false;
   }
   ::close(serverSocket);
   serverSocket = -1;

   unsigned char buf[512];
   int res = recv(clientSocket, buf, sizeof(buf), 0);
   if (res == -1) {
      perror("Error al iniciar comunicación");
      close();
      return false;
   }

   strncpy(remoteName, (char *) &buf[4], buf[3]);


   buf[0] = 3;
   buf[1] = strlen(localName);
   strncpy((char*) &buf[2], localName, buf[1]);
   res = send(clientSocket, buf, buf[1] + 2, 0);
   if (res == -1) {
      perror("Error al confirmar comunicación");
      close();
      return false;
   }

   if (establecerNoBloqueante(clientSocket) == -1) {
      perror("Error al establecer cliente no bloqueante");
      close();
      return false;
   }

   return true;
}

bool ConexionRed::startAsClient(const char *localName) {
   struct addrinfo hints;
   struct addrinfo *result, *iter;
   char servicio[8];
   int res;

   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family    = AF_UNSPEC;
   hints.ai_socktype  = SOCK_STREAM;
   hints.ai_flags     = 0;
   hints.ai_protocol  = 0;

   sprintf(servicio, "%u", puerto);
   res = getaddrinfo(host, servicio, &hints, &result);
   if (res != 0) {
      fprintf(stderr, "ERROR AL RESOLVER HOST: %s\n", gai_strerror(res));
      return false;
   }

   iter = result;
   while (iter != NULL) {
       int addrFamily = iter->ai_family;
       int addrLen    = iter->ai_addrlen;

       clientSocket = socket(addrFamily, SOCK_STREAM, 0);
       if (clientSocket < 0) {
          perror("ERROR AL ABRIR SOCKET CLIENTE");
          break;
       }

       res = connect(clientSocket, iter->ai_addr, addrLen);
       if (res < 0) {
          perror("ERROR AL CONECTAR CLIENTE");
          close();
       } else {
          break;
       }
       iter = iter->ai_next;
   }

   freeaddrinfo(result);
   if (clientSocket == -1) return false;

   unsigned char buf[512] = "OO";
   buf[3] = strlen(localName);
   strncpy((char *) &buf[4], localName, buf[3]);
   res = send(clientSocket, buf, buf[3]+4, 0);
   if (res < 0) {
      perror("Error al formular peticion");
      close();
      return false;
   }

   res = recv(clientSocket, buf, sizeof(buf), 0);
   if (res < 0) {
      perror("Error al recibir respuesta");
      close();
      return false;
   }

   strncpy(remoteName, (char *) &buf[2], buf[1]);
   return true;
}

int ConexionRed::startListening() {
   serverSocket = socket(AF_INET6, SOCK_STREAM, 0);
   if (serverSocket == -1) {
      return -1;
   }

   struct sockaddr_storage addr_serv;
   struct sockaddr_in6 *addr_in6;
   memset(&addr_serv, 0, sizeof(addr_serv));
   addr_in6 = (struct sockaddr_in6 *) &addr_serv;
   addr_in6->sin6_family = AF_INET6;
   addr_in6->sin6_port  = htons(puerto);
   addr_in6->sin6_addr  = in6addr_any;

   int res = bind(serverSocket, (struct sockaddr *) addr_in6, sizeof(addr_serv));
   if (res == -1) {
      serverSocket = -1;
      return -1;
   }
   res = listen(serverSocket, 1);
   if (res == -1) {
      serverSocket = -1;
      return -1;
   }

   res = establecerNoBloqueante(serverSocket);
   if (res == -1) {
      ::close(serverSocket);
      serverSocket = -1;
   }

   return serverSocket;
}

int ConexionRed::establecerNoBloqueante(int fd) {
   int res;
   int flags = fcntl(fd, F_GETFL);
   if (flags < 0) {
      return -1;
   }
   flags |= O_NONBLOCK;
   res = fcntl(fd, F_SETFL, flags);
   if (res < 0) {
      return -1;
   }
   return res;
}
