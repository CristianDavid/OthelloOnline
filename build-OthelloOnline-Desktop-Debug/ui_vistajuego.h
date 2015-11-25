/********************************************************************************
** Form generated from reading UI file 'vistajuego.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISTAJUEGO_H
#define UI_VISTAJUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VistaJuego
{
public:
    QWidget *centralWidget;

    void setupUi(QGraphicsView *VistaJuego)
    {
        if (VistaJuego->objectName().isEmpty())
            VistaJuego->setObjectName(QStringLiteral("VistaJuego"));
        VistaJuego->resize(800, 600);
        centralWidget = new QWidget(VistaJuego);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 100, 30));

        retranslateUi(VistaJuego);

        QMetaObject::connectSlotsByName(VistaJuego);
    } // setupUi

    void retranslateUi(QGraphicsView *VistaJuego)
    {
        VistaJuego->setWindowTitle(QApplication::translate("VistaJuego", "Othello Online", 0));
    } // retranslateUi

};

namespace Ui {
    class VistaJuego: public Ui_VistaJuego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISTAJUEGO_H
