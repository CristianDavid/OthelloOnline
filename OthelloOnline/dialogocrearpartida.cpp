#include "dialogocrearpartida.h"
#include "ui_dialogocrearpartida.h"
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include "conexionred.h"

DialogoCrearPartida::DialogoCrearPartida(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::DialogoCrearPartida),
   conexion(NULL) {
   ui->setupUi(this);
}

DialogoCrearPartida::~DialogoCrearPartida() {
   delete ui;
}

const char *DialogoCrearPartida::getNombrePartida() {
   return nombrePartida.c_str();
}

ConexionRed *DialogoCrearPartida::getConexion() {
   return conexion;
}

void DialogoCrearPartida::on_DialogoCrearPartida_accepted() {
   QLineEdit *nombrePartida = findChild<QLineEdit*>("nombrePartida");
   QMessageBox mensaje(this);
   if (nombrePartida->text().isEmpty()) {
      mensaje.setText(QString::fromUtf8("La cadena está vacía."));
      mensaje.exec();
      conexion = NULL;
   } else if (nombrePartida->text().length() > 255) {
      mensaje.setText("Nombre de partida demasiado largo");
      mensaje.exec();
      conexion = NULL;
   } else {
      conexion = new ConexionRed;
      this->nombrePartida = nombrePartida->text().toStdString();
   }
}
