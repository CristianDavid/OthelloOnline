#include "unirseapatridadialog.h"
#include "ui_unirseapatridadialog.h"
#include <cstring>
#include <sys/types.h>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>

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
   HostWidgetItem *partidaLocal = new HostWidgetItem("localhost", "local game");
   partidas->addItem(partidaLocal);
}

UnirseAPatridaDialog::~UnirseAPatridaDialog() {
   delete ui;
}

const char *UnirseAPatridaDialog::getSelectedHost() {
   return selectedHost.c_str();
}

const char *UnirseAPatridaDialog::getNombrePartida() {
   return nombrePartida.c_str();
}

void UnirseAPatridaDialog::on_UnirseAPatridaDialog_accepted() {
   QLineEdit *line = findChild<QLineEdit*>("selectedHost");
   QString text = line->text();
   if (text.isNull() || text.isEmpty()) {
      selectedHost = "";
   } else {
      selectedHost = line->text().toStdString();
   }

   line = findChild<QLineEdit*>("nombrePartida");
   text = line->text();
   if (text.isNull() || text.isEmpty()) {
      nombrePartida = "";
   } else if (text.length() > 255) {
      nombrePartida = "";
   } else {
      nombrePartida = text.toStdString();
   }
}
