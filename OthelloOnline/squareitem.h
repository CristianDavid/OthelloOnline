#ifndef SQUAREITEM_H
#define SQUAREITEM_H

#include <QGraphicsRectItem>
#include <QPointF>

class SquareItem : public QGraphicsRectItem {
public:
   SquareItem();
protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
   static QPointF pressed;
signals:

public slots:

};

#endif // SQUAREITEM_H
