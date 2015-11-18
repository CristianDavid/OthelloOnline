#ifndef SQUAREITEM_H
#define SQUAREITEM_H

#include <QGraphicsRectItem>

class SquareItem : public QGraphicsRectItem {
public:
   SquareItem();
protected:
   void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
signals:

public slots:

};

#endif // SQUAREITEM_H
