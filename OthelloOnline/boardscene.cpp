#include "boardscene.h"
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QRadialGradient>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QList>
#include "squareitem.h"

BoardScene::BoardScene(QObject *parent) :
   QGraphicsScene(parent) {
   QRadialGradient gradient(0, 0, 350);
   gradient.setColorAt(0, QColor::fromRgbF(0.9, 0.9, 0.9));
   gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0));
   QBrush bgBrush(gradient);
   setBackgroundBrush(bgBrush);


   for (int i = 0, posX = -200; i < 8; i++, posX += 50) {
      for (int j = 0, posY = -200; j < 8; j++, posY += 50) {
         SquareItem &casilla = casillas[i][j];
         casilla.setCoordinates(i, j);
         casilla.setBrush(((i + j) % 2 == 0)? QColor(0,86,86) : QColor(89,133,0));
         casilla.setRect(0, 0, 50, 50);
         casilla.setX(posX);
         casilla.setY(posY);
         connect(&casilla, SIGNAL(clicked(int,int)), this, SLOT(emitirCasillaClick(int,int)));
         addItem(&casilla);
      }
   }

   addItem(&nombreJugadorLocal);
   nombreJugadorLocal.setText("local");
   nombreJugadorLocal.setX(-250);
   nombreJugadorLocal.setY(-250);
   nombreJugadorLocal.setFont(QFont("Times", 20, QFont::Bold));
   nombreJugadorLocal.setBrush(QColor(89,133,0));

   addItem(&nombreJugadorRemoto);
   nombreJugadorRemoto.setText("remoto");
   nombreJugadorRemoto.setX(230);
   nombreJugadorRemoto.setY(-250);
   nombreJugadorRemoto.setFont(QFont("Times", 20, QFont::Bold));
   nombreJugadorRemoto.setBrush(QColor(89,133,0));
}

void BoardScene::setNombreJugadorLocal(const char *nombre) {
   nombreJugadorLocal.setText(nombre);
}

void BoardScene::setNombreJugadorRemoto(const char *nombre) {
   nombreJugadorRemoto.setText(nombre);
}

void BoardScene::ponerFicha(int i, int j, QColor colorJugador) {
   SquareItem &casilla = casillas[i][j];
   QList<QGraphicsItem*> children = casilla.childItems();
   QList<QGraphicsItem*>::iterator it = children.begin();
   while (it != children.end()) {
      delete *it;
      it++;
   }
   QGraphicsEllipseItem *disk = new QGraphicsEllipseItem(
                                    0, 0, 50, 50, &casilla);
   disk->setBrush(colorJugador);
}

void BoardScene::emitirCasillaClick(int i, int j) {
   emit casillaClick(i, j);
}
