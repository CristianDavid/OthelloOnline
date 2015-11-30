#ifndef JUGADORLOCAL_H
#define JUGADORLOCAL_H

#include <QObject>
#include <QTimer>
#include "boardscene.h"
#include "partida.h"
#include "jugadorremoto.h"

class JugadorLocal : public QObject, public Jugador {
   Q_OBJECT
public:
   JugadorLocal(BoardScene *juego, const char *nombre, Partida *partida, JugadorRemoto *oponente);
   int hacerMovimiento();
   int notificarMovimiento(int movimientoAdversario);
   void actualizarTablero(void);
   ~JugadorLocal();
private:
   BoardScene *juego;
   Partida *partida;
   int proximoMovimiento;
   JugadorRemoto *oponente;
   bool esTurnoLocal;
   QTimer timerRecibirMovimiento, timerReenvio;
   int movimientoPendiente;
signals:
public slots:
   void hacerMovimientoLocal(int i, int j);
   void hacerMovimientoRemoto();
   void reintentarMovimiento();
};

#endif // JUGADORLOCAL_H
