#include "squareitem.h"
#include <cmath>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QBrush>
#include <QColor>
#include <QPointF>

QPointF SquareItem::pressed(NAN, NAN);

SquareItem::SquareItem() {
   setFlag(QGraphicsItem::ItemIsFocusable);
}

SquareItem::~SquareItem() {
}

void SquareItem::setCoordinates(int i, int j) {
   this-> i = i;
   this-> j = j;
}

void SquareItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
   pressed = event->lastPos();
}

void SquareItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
   if (pressed == event->lastPos()) {
      emit clicked(i, j);
   }
}
