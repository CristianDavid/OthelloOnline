#ifndef UNIRSEAPATRIDADIALOG_H
#define UNIRSEAPATRIDADIALOG_H

#include <string>
#include <QDialog>

namespace Ui {
class UnirseAPatridaDialog;
}

class UnirseAPatridaDialog : public QDialog {
   Q_OBJECT
public:
   explicit UnirseAPatridaDialog(QWidget *parent = 0);
   ~UnirseAPatridaDialog();
   const char *getSelectedHost();
   const char *getNombrePartida();
private slots:
   void on_UnirseAPatridaDialog_accepted();
private:
   Ui::UnirseAPatridaDialog *ui;
   std::string selectedHost;
   std::string nombrePartida;
};

#endif // UNIRSEAPATRIDADIALOG_H
