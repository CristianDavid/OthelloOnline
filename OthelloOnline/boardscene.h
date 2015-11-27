#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include "squareitem.h"

class BoardScene : public QGraphicsScene {
   Q_OBJECT
public:
   explicit BoardScene(QObject *parent = 0);

private:
   SquareItem casillas[8][8];

signals:
   void casillaClick(int i, int j);
public slots:
   void ponerFicha(int i, int j, QColor colorJugador);
private slots:
   void emitirCasillaClick(int i, int j);
};

#endif // BOARDSCENE_H
