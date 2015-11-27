#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <string>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QProgressDialog>
#include "conexionred.h"
#include "jugadorlocal.h"

class MainView : public QGraphicsView {
 Q_OBJECT
 public:
   MainView();
   ~MainView();
 private:
   void setUpMenu();
   QGraphicsScene *menu, *juego;
   QMediaPlayer *player;
   ConexionRed *conexion;
   QTimer timer;
   QProgressDialog *esperando;
   std::string nombreConexion;
   JugadorLocal *jugador;
 public slots:
   void crearPartida();
   void cancelarEspera();
   void encontrandoJugadores();
   void unirseAPartida();
};

#endif // MAINVIEW_H
