#include "unirseapatridadialog.h"
#include "ui_unirseapatridadialog.h"
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QDebug>

UnirseAPatridaDialog::UnirseAPatridaDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::UnirseAPatridaDialog) {
   ui->setupUi(this);
   const QString childName("listWidget");
   QListWidget *partidas = findChild<QListWidget*>(childName);
   for (int i = 0; i < 20; i++) {
      partidas->addItem("cosa");
   }
}

UnirseAPatridaDialog::~UnirseAPatridaDialog() {
   delete ui;
}
