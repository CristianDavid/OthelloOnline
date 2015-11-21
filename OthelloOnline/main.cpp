#include <QApplication>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "mainview.h"

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   MainView mainView;
   mainView.show();

   QMediaPlayer *player = new QMediaPlayer;
   player->setMedia(QUrl::fromLocalFile("/home/cristian/Source/PrograInternet/ProyectoFinal/OthelloOnline/build-debug/audio/OthelloOnline.wav"));
   player->setVolume(50);
   player->play();

   return app.exec();
}
