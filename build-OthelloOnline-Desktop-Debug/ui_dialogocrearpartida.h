/********************************************************************************
** Form generated from reading UI file 'dialogocrearpartida.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOCREARPARTIDA_H
#define UI_DIALOGOCREARPARTIDA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoCrearPartida
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *nombrePartida;

    void setupUi(QDialog *DialogoCrearPartida)
    {
        if (DialogoCrearPartida->objectName().isEmpty())
            DialogoCrearPartida->setObjectName(QStringLiteral("DialogoCrearPartida"));
        DialogoCrearPartida->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoCrearPartida);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(DialogoCrearPartida);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 381, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        nombrePartida = new QLineEdit(formLayoutWidget);
        nombrePartida->setObjectName(QStringLiteral("nombrePartida"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nombrePartida);


        retranslateUi(DialogoCrearPartida);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoCrearPartida, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoCrearPartida, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoCrearPartida);
    } // setupUi

    void retranslateUi(QDialog *DialogoCrearPartida)
    {
        DialogoCrearPartida->setWindowTitle(QApplication::translate("DialogoCrearPartida", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DialogoCrearPartida", "Jugar con negras", 0)
         << QApplication::translate("DialogoCrearPartida", "Jugar con blancas", 0)
        );
        label_2->setText(QApplication::translate("DialogoCrearPartida", "Nombre de la partida", 0));
        label->setText(QApplication::translate("DialogoCrearPartida", "Quiero", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogoCrearPartida: public Ui_DialogoCrearPartida {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCREARPARTIDA_H
