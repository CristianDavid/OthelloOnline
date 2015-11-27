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
   QLineEdit *line = findChild<QLineEdit*>("selectedHost");
   QString text = line->text();
   if (text.isNull() || text.isEmpty()) {
      return NULL;
   } else {
      selectedHost = line->text().toStdString();
   }
   return selectedHost.c_str();
}
