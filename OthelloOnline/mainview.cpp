#include "mainview.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QFontDatabase>
#include <QFont>
#include <QMediaPlayer>
#include <QPointF>
#include <QRadialGradient>
#include <QString>
#include <QMessageBox>
#include <QProgressDialog>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include "unirseapatridadialog.h"
#include "dialogocrearpartida.h"
#include "mainmenuitem.h"
#include "boardscene.h"
#include "conexionred.h"
#include "jugadorlocal.h"
#include "jugadorremoto.h"
#include "partida.h"

#ifdef linux
#define URI_TEMA_INICIO "qrc:/sounds/main_theme.ogg"
#else
#define URI_TEMA_INICIO "qrc:/sounds/main_theme.mp3"
#endif

MainView::MainView() {
   setUpMenu();
   setScene(menu);
   juego = NULL;
   player = new QMediaPlayer;
   player->setMedia(QUrl(URI_TEMA_INICIO));
   player->setVolume(50);
   player->play();
   connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), player, SLOT(play()));
}

MainView::~MainView() {
   delete player;
}

void MainView::setUpMenu() {
   menu = new QGraphicsScene(this);
   MainMenuItem *text;

   text = new MainMenuItem("Crear partida");
   text->setPos(menu->width() / 2, 0);
   menu->addItem(text);
   connect(text, SIGNAL(clicked()), this, SLOT(crearPartida()));

   text = new MainMenuItem("Unirse a partida");
   text->setPos(menu->width() / 2, 160);
   menu->addItem(text);
   connect(text, SIGNAL(clicked()), this, SLOT(unirseAPartida()));

   text = new MainMenuItem(QString::fromUtf8("Configuraci\u00f3n"));
   text->setPos(menu->width() / 2, 320);
   menu->addItem(text);

   QRadialGradient gradient(100, 500, 250);
   gradient.setColorAt(0, QColor::fromRgbF(0.9, 0.9, 0.9));
   gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0));
   QBrush bgBrush(gradient);
   setBackgroundBrush(bgBrush);
   setFixedSize(800, 600);
   menu->setSceneRect(0, 0, 790, 590);
}

void MainView::crearPartida() {
   DialogoCrearPartida dialog(this);
   int option = dialog.exec();
   if (option == QDialog::Accepted) {
      conexion = dialog.getConexion();
      nombreConexion = dialog.getNombrePartida();
      if (conexion != NULL) {
         esperando = new QProgressDialog("Esperando un jugador", "Cancelar Partida", 0, 0, this);
         connect(esperando, SIGNAL(canceled()), this, SLOT(cancelarEspera()));
         connect(&timer, SIGNAL(timeout()), this, SLOT(encontrandoJugadores()));
         esperando->show();
         timer.setInterval(500);
         timer.start();
      }
   }
}

void MainView::cancelarEspera() {
   timer.stop();
   delete conexion;
   esperando->hide();
   delete esperando;
}

void MainView::encontrandoJugadores() {
   conexion->start(nombreConexion.c_str());
   if (conexion->isOpen()) {
      juego = new BoardScene();
      jugador = new JugadorLocal((BoardScene*)juego, nombreConexion.c_str(), new Partida(), new JugadorRemoto(conexion));
      connect(juego, SIGNAL(destroyed()), this, SLOT(volverAMenu()));
      setScene(juego);
      timer.stop();
      delete esperando;
   } else if (!conexion->shouldRetry()) {
      cancelarEspera();
   }
}

void MainView::unirseAPartida() {
   UnirseAPatridaDialog dialog(this);
   int option = dialog.exec();
   if (option == QDialog::Accepted) {
      const char *host = dialog.getSelectedHost();
      nombreConexion = dialog.getNombrePartida();
      if (host != NULL) {
         conexion = new ConexionRed(host, OTHELLO_ONLINE_DEFAULT_PORT);
         if (conexion->start(nombreConexion.c_str())) {
            juego = new BoardScene(this);
            jugador = new JugadorLocal((BoardScene*)juego, nombreConexion.c_str(), new Partida(), new JugadorRemoto(conexion));
            connect(juego, SIGNAL(destroyed()), this, SLOT(volverAMenu()));
            setScene(juego);
         } else {
            QMessageBox mensajeError;
            mensajeError.setText("No fue posible establecer la conexion");
            mensajeError.exec();
            delete conexion;
         }
      }
   }
}

void MainView::volverAMenu() {
   setScene(menu);
}
