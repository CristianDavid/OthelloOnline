#ifndef DIALOGOCREARPARTIDA_H
#define DIALOGOCREARPARTIDA_H

#include <QDialog>

namespace Ui {
class DialogoCrearPartida;
}

class DialogoCrearPartida : public QDialog
{
   Q_OBJECT

public:
   explicit DialogoCrearPartida(QWidget *parent = 0);
   ~DialogoCrearPartida();

private slots:
   void on_DialogoCrearPartida_accepted();

private:
   Ui::DialogoCrearPartida *ui;
};

#endif // DIALOGOCREARPARTIDA_H
