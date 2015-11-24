#include "mainview.h"
#include <cmath>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QFontDatabase>
#include <QFont>
#include <QMediaPlayer>
#include <QPointF>
#include <QRadialGradient>
#include <QString>
#include <QDebug>
#include "boardscene.h"
#include "vistajuego.h"
#include "unirseapatridadialog.h"

#define DEFAULT_FONT_FILE "fonts/d-puntillas-D-to-tiptoe.ttf"
#define URI_TEMA_INICIO "/home/cristian/Source/PrograInternet/ProyectoFinal/OthelloOnline/build-debug/audio/OthelloOnline.wav"

const QString OPCIONES[] = {
   QString("Crear partida"),
   QString("Unirse a partida"),
   QString::fromUtf8("Configuraci\u00f3n"),
};

void crearPartida(void) {
   VistaJuego *view = new VistaJuego;
   BoardScene *scene = new BoardScene;
   view->setScene(scene);
   view->show();
}

void unirseAPartida() {
   UnirseAPatridaDialog *dialog = new UnirseAPatridaDialog;
   dialog->show();
}

void configuracion() {

}

void (*subMenus[])(void) = {
   crearPartida,
   unirseAPartida,
   configuracion
};

class MainMenuItem : public QGraphicsSimpleTextItem {
 public:
   MainMenuItem(const QString &text, void (*onClick) (void) = NULL) :
      QGraphicsSimpleTextItem(text),
      onClick(onClick) {
      if (fontId == -2)
         fontId = QFontDatabase::addApplicationFont(DEFAULT_FONT_FILE);
      if (fontId != -1) {
         QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
         QFont font(family, 40, 40, true);
         setFont(font);
      }
      setBrush(QColor(89,133,0));
      setFlag(QGraphicsItem::ItemIsFocusable);
   }
 protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event) {
      pressed = event->lastPos();
   }

   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
      if (pressed == event->lastPos() && onClick != NULL)
         onClick();
   }

 private:
   void (*onClick) (void);
   static int fontId;
   static QPointF pressed;
};

int MainMenuItem::fontId = -2;
QPointF MainMenuItem::pressed(NAN, NAN);

MainView::MainView() {
   QGraphicsScene *menu = new QGraphicsScene();
   MainMenuItem *text;
   qreal y = 0;
   for (int i = 0; i < 3; i++) {
      text = new MainMenuItem(OPCIONES[i], subMenus[i]);
      text->setPos(menu->width() / 2, y);
      menu->addItem(text);
      y += 160;
   }
   QRadialGradient gradient(100, 500, 250);
   gradient.setColorAt(0, QColor::fromRgbF(0.9, 0.9, 0.9));
   gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0));
   QBrush bgBrush(gradient);
   setBackgroundBrush(bgBrush);
   setFixedSize(800, 600);
   menu->setSceneRect(0, 0, 790, 590);
   setScene(menu);

   player = new QMediaPlayer;
   player->setMedia(QUrl::fromLocalFile(URI_TEMA_INICIO));
   player->setVolume(50);
   player->play();
}

MainView::~MainView() {
   delete player;
}
