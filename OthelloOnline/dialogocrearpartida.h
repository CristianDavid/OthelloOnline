#ifndef DIALOGOCREARPARTIDA_H
#define DIALOGOCREARPARTIDA_H

#include <string>
#include <QDialog>
#include "conexionred.h"

namespace Ui {
class DialogoCrearPartida;
}

class DialogoCrearPartida : public QDialog {
   Q_OBJECT
public:
   explicit DialogoCrearPartida(QWidget *parent = 0);
   ~DialogoCrearPartida();
   ConexionRed *getConexion();
   const char *getNombrePartida();
private slots:
   void on_DialogoCrearPartida_accepted();
private:
   Ui::DialogoCrearPartida *ui;
   ConexionRed *conexion;
   std::string nombrePartida;
};

#endif // DIALOGOCREARPARTIDA_H
