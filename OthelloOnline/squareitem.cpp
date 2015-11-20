#include "squareitem.h"
#include <cmath>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>
#include <QColor>
#include <QPointF>

QPointF SquareItem::pressed(NAN, NAN);

SquareItem::SquareItem() {
   setFlag(QGraphicsItem::ItemIsFocusable);
}

void SquareItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
   pressed = event->lastPos();
}

void SquareItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
   if (pressed == event->lastPos()) {
      QGraphicsEllipseItem *disk = new QGraphicsEllipseItem(x(), y(), 50, 50);
      disk->setBrush(Qt::white);
      scene()->addItem(disk);
   }
}
