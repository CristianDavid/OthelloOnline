#ifndef CONEXIONRED_H
#define CONEXIONRED_H

#define OTHELLO_ONLINE_DEFAULT_PORT 20303

class ConexionRed{
public:
    ConexionRed(const char *host, short puerto);
    ConexionRed(); // inicializar como servidor
    ~ConexionRed();
    bool start(const char *localName);
    const char *getRemoteName();
    int hacerMovimiento(char movimiento);
    int recibirMovimiento();
    bool isOpen();
    bool shouldRetry();
    bool isServer();
    void close();
private:
    bool startAsServer(const char *localName);
    bool startAsClient(const char *localName);
    int startListening();
    int establecerNoBloqueante(int fd);
    int clientSocket;
    char *host;
    short puerto;
    bool _isOpen;
    bool _shouldRetry;
    char remoteName[256];
    int serverSocket;
    int prevFlags;
};

#endif // CONEXIONRED_H
