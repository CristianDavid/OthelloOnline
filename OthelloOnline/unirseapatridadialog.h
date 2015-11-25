#ifndef UNIRSEAPATRIDADIALOG_H
#define UNIRSEAPATRIDADIALOG_H

#include <QDialog>

namespace Ui {
class UnirseAPatridaDialog;
}

class UnirseAPatridaDialog : public QDialog {
   Q_OBJECT

public:
   explicit UnirseAPatridaDialog(QWidget *parent = 0);
   ~UnirseAPatridaDialog();

private slots:
   void on_UnirseAPatridaDialog_accepted();

private:
   Ui::UnirseAPatridaDialog *ui;
};

#endif // UNIRSEAPATRIDADIALOG_H
