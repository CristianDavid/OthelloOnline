#include "dialogocrearpartida.h"
#include "ui_dialogocrearpartida.h"

DialogoCrearPartida::DialogoCrearPartida(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::DialogoCrearPartida)
{
   ui->setupUi(this);
}

DialogoCrearPartida::~DialogoCrearPartida()
{
   delete ui;
}
