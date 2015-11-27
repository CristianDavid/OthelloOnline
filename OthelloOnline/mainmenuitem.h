#ifndef MAINMENUITEM_H
#define MAINMENUITEM_H

#include <QGraphicsTextItem>

class MainMenuItem : public QGraphicsTextItem {
   Q_OBJECT
public:
   explicit MainMenuItem(const QString &text, QGraphicsItem *parent = 0);
   ~MainMenuItem();
protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
   static int fontId;
   static QPointF pressed;
signals:
   void clicked();
public slots:
};

#endif // MAINMENUITEM_H
