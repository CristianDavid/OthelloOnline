#include "vistajuego.h"
#include "ui_vistajuego.h"

VistaJuego::VistaJuego(QWidget *parent) :
   QGraphicsView(parent),
   ui(new Ui::VistaJuego) {
   ui->setupUi(this);
}

VistaJuego::~VistaJuego() {
   delete ui;
}
