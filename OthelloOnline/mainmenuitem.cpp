#include "mainmenuitem.h"
#include <cmath>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QColor>
#include <QString>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

#define DEFAULT_FONT_FILE ":/fonts/main_menu_font.ttf"
int MainMenuItem::fontId = -2;
QPointF MainMenuItem::pressed(NAN, NAN);

MainMenuItem::MainMenuItem(const QString &text, QGraphicsItem *parent) :
   QGraphicsTextItem(text, parent) {
   if (fontId == -2)
      fontId = QFontDatabase::addApplicationFont(DEFAULT_FONT_FILE);
   if (fontId != -1) {
      QString family = QFontDatabase::applicationFontFamilies(fontId).at(0);
      QFont font(family, 40, 40, true);
      setFont(font);
   }
   setDefaultTextColor(QColor(89,133,0));
   setFlag(QGraphicsItem::ItemIsFocusable);
}

MainMenuItem::~MainMenuItem() {
}

void MainMenuItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
   pressed = event->lastPos();
}

void MainMenuItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
   if (pressed == event->lastPos())
      emit clicked();
}
