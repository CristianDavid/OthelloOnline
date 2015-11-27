#include "dialogocrearpartida.h"
#include "ui_dialogocrearpartida.h"
#include <QMessageBox>
#include <QLineEdit>

DialogoCrearPartida::DialogoCrearPartida(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::DialogoCrearPartida) {
   ui->setupUi(this);
}

DialogoCrearPartida::~DialogoCrearPartida() {
   delete ui;
}

int DialogoCrearPartida::getAccptedClient() {
   QLineEdit *nombrePartida = findChild<QLineEdit*>("nombrePartida");
   QMessageBox mensaje(this);
   if (nombrePartida->text().isEmpty()) {
      mensaje.setText(QString::fromUtf8("La cadena está vacía."));
      mensaje.exec();
   } else if (nombrePartida->text().length() > 255) {
      mensaje.setText("Nombre de partida demasiado largo");
      mensaje.exec();
   } else {
      mensaje.setText("Buscando un jugador");
      mensaje.exec();
   }
   return -1;
}
