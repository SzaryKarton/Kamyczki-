/********************************************************************************
** Form generated from reading UI file 'rysowanie.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RYSOWANIE_H
#define UI_RYSOWANIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rysowanie
{
public:

    void setupUi(QWidget *Rysowanie)
    {
        if (Rysowanie->objectName().isEmpty())
            Rysowanie->setObjectName("Rysowanie");
        Rysowanie->resize(400, 300);

        retranslateUi(Rysowanie);

        QMetaObject::connectSlotsByName(Rysowanie);
    } // setupUi

    void retranslateUi(QWidget *Rysowanie)
    {
        Rysowanie->setWindowTitle(QCoreApplication::translate("Rysowanie", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rysowanie: public Ui_Rysowanie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RYSOWANIE_H
