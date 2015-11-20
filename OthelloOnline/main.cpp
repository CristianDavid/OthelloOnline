#include "vistajuego.h"
#include "mainview.h"
#include "boardscene.h"
#include <QApplication>
#include <QGraphicsRectItem>

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   VistaJuego view;
   BoardScene scene;

   view.setScene(&scene);
   view.show();

   MainView mainView;
   mainView.show();

   return app.exec();
}
