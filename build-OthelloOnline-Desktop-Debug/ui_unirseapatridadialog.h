/********************************************************************************
** Form generated from reading UI file 'unirseapatridadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIRSEAPATRIDADIALOG_H
#define UI_UNIRSEAPATRIDADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_UnirseAPatridaDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *selectedHost;
    QListWidget *listWidget;

    void setupUi(QDialog *UnirseAPatridaDialog)
    {
        if (UnirseAPatridaDialog->objectName().isEmpty())
            UnirseAPatridaDialog->setObjectName(QStringLiteral("UnirseAPatridaDialog"));
        UnirseAPatridaDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(UnirseAPatridaDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        selectedHost = new QLineEdit(UnirseAPatridaDialog);
        selectedHost->setObjectName(QStringLiteral("selectedHost"));
        selectedHost->setGeometry(QRect(40, 20, 311, 25));
        listWidget = new QListWidget(UnirseAPatridaDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(45, 60, 301, 161));

        retranslateUi(UnirseAPatridaDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), UnirseAPatridaDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UnirseAPatridaDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(UnirseAPatridaDialog);
    } // setupUi

    void retranslateUi(QDialog *UnirseAPatridaDialog)
    {
        UnirseAPatridaDialog->setWindowTitle(QApplication::translate("UnirseAPatridaDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class UnirseAPatridaDialog: public Ui_UnirseAPatridaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIRSEAPATRIDADIALOG_H
