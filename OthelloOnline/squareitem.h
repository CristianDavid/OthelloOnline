#ifndef SQUAREITEM_H
#define SQUAREITEM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>

class SquareItem : public QObject, public QGraphicsRectItem {
   Q_OBJECT
public:
   SquareItem();
   ~SquareItem();
   void setCoordinates(int i, int j);
protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
   static QPointF pressed;
   int i, j;
signals:
   void clicked(int i, int j);
public slots:

};

#endif // SQUAREITEM_H
