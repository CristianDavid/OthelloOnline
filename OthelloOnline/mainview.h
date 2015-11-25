#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QMediaPlayer>

class MainView : public QGraphicsView {
 public:
   MainView();
   ~MainView();
 private:
   QMediaPlayer *player;
};

#endif // MAINVIEW_H
