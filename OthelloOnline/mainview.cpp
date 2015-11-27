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
#include <QDebug>
#include "unirseapatridadialog.h"
#include "dialogocrearpartida.h"
#include "mainmenuitem.h"
#include "boardscene.h"
#include "conexionred.h"

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
      ConexionRed *conexion = dialog.getConexion();
      const char *nombre = dialog.getNombrePartida();
      if (conexion != NULL && nombre != NULL) {
         QProgressDialog esperando("Esperando un jugador", "Cancelar Partida", 0, 0, this);
         //esperando.setWindowModality(Qt::NonModal);
         //esperando.show();
         do {
            qDebug() << "paso here";
            conexion->start(nombre);
           // if (esperando.wasCanceled()) {
             //  delete conexion;
              // return;
            //}
         } while (!conexion->isOpen() || conexion->shouldRetry());
         juego = new BoardScene(this);
         setScene(juego);
      }
   }
}

void MainView::unirseAPartida() {
   UnirseAPatridaDialog dialog(this);
   int option = dialog.exec();
   if (option == QDialog::Accepted) {
      const char *host = dialog.getSelectedHost();
      if (host != NULL) {
         ConexionRed conexion(host, OTHELLO_ONLINE_DEFAULT_PORT);
         juego = new BoardScene(this);
         setScene(juego);
      }
   }
}
