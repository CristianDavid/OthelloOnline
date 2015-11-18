#include "vistajuego.h"
#include "boardscene.h"
#include <QApplication>
#include <QGraphicsRectItem>

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   VistaJuego view;
   BoardScene scene;

   view.setScene(&scene);
   view.show();

   return app.exec();
}
