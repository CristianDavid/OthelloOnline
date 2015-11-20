#include "mainview.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QFontDatabase>
#include <QFont>
#include <QDebug>
#include <cstdio>
#include <cstdlib>

#define DEFAULT_FONT "fonts/d-puntillas-D-to-tiptoe.ttf"

MainView::MainView() {
   QGraphicsScene *menu = new QGraphicsScene();
   QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem("Jugar");
   int fontId = QFontDatabase::addApplicationFont(DEFAULT_FONT);
   if (fontId != -1) {
      QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
      QFont font(family, 40, 40, true);
      text->setFont(font);
   }
   setFixedSize(800, 600);
   menu->addItem(text);
   menu->setSceneRect(0, 0, 790, 590);
   text->setPos(menu->width() / 2, 0);
   setScene(menu);
}
