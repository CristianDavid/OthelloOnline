#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>

class MainView : public QGraphicsView {
 Q_OBJECT
 public:
   MainView();
   ~MainView();
 private:
   void setUpMenu();
   QGraphicsScene *menu, *juego;
   QMediaPlayer *player;
 public slots:
   void crearPartida();
   void unirseAPartida();
};

#endif // MAINVIEW_H
