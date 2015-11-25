#include "unirseapatridadialog.h"
#include "ui_unirseapatridadialog.h"
#include <cstring>
#include <sys/types.h>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QDebug>

class HostWidgetItem : public QListWidgetItem {
 public:
   HostWidgetItem(const char *hostName, const char *nombrePartida) {
      strncpy(this->hostName, (hostName != NULL)? hostName : "", 255);
      strncpy(this->nombrePartida, (nombrePartida != NULL)? nombrePartida : "", 255);
      setText(QString(getNombrePartida()) + " - " + getHostName());
   }
   const char *getHostName() {
      return hostName;
   }
   const char *getNombrePartida() {
      return nombrePartida;
   }
 private:
   char hostName[256];
   char nombrePartida[256];
};

UnirseAPatridaDialog::UnirseAPatridaDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::UnirseAPatridaDialog) {
   ui->setupUi(this);
   QListWidget *partidas = findChild<QListWidget*>("listWidget");
   HostWidgetItem *partidaLocal = new HostWidgetItem("localhost", "cristian");
   partidas->addItem(partidaLocal);
}

UnirseAPatridaDialog::~UnirseAPatridaDialog() {
   delete ui;
}

void UnirseAPatridaDialog::on_UnirseAPatridaDialog_accepted() {
   QLineEdit *selectedHost = findChild<QLineEdit*>("selectedHost");
   qDebug() << selectedHost->text();
}
