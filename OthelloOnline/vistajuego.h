#ifndef VISTAJUEGO_H
#define VISTAJUEGO_H

#include <QGraphicsView>

namespace Ui {
   class VistaJuego;
}

class VistaJuego : public QGraphicsView {
   Q_OBJECT

public:
   explicit VistaJuego(QWidget *parent = 0);
   ~VistaJuego();

private:
   Ui::VistaJuego *ui;
};

#endif // VISTAJUEGO_H
