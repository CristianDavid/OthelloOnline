#include "mainview.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QFontDatabase>

MainView::MainView() {
   QGraphicsScene *menu = new QGraphicsScene();
   QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem("Jugar");
   int id = QFontDatabase::addApplicationFont("fonts/");
   setFixedSize(800, 600);
   menu->addItem(text);
   menu->setSceneRect(0, 0, 790, 590);
   text->setPos(menu->width() / 2, 0);
   text->setFont(font);
   setScene(menu);
}
