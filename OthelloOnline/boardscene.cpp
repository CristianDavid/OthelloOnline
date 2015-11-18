#include "boardscene.h"
#include <QRadialGradient>
#include <QBrush>
#include <QColor>

BoardScene::BoardScene(QObject *parent) :
   QGraphicsScene(parent) {
   QRadialGradient gradient(0, 0, 350);
   gradient.setColorAt(0, QColor::fromRgbF(0.9, 0.9, 0.9));
   gradient.setColorAt(1,QColor::fromRgbF(0, 0, 0));
   QBrush bgBrush(gradient);
   setBackgroundBrush(bgBrush);


   for (int i = 0, posX = -200; i < 8; i++, posX += 50) {
      for (int j = 0, posY = -200; j < 8; j++, posY += 50) {
         SquareItem &casilla = casillas[i][j];
         casilla.setBrush(((i + j) % 2 == 0)? QColor(0,86,86) : QColor(89,133,0));
         casilla.setRect(posX, posY, 50, 50);
         addItem(&casilla);
      }
   }

}
