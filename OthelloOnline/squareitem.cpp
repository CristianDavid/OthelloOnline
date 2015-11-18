#include "squareitem.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QBrush>
#include <QDebug>
#include <QColor>

SquareItem::SquareItem() {
   setFlag(QGraphicsItem::ItemIsFocusable);
}

void SquareItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
   qDebug() << "demonios";
   QGraphicsEllipseItem *disk = new QGraphicsEllipseItem(x(), y(), 50, 50);
   disk->setBrush(Qt::white);
   scene()->addItem(disk);
}
