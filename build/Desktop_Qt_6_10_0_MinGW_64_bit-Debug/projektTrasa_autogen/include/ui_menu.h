/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *mapaButton;
    QPushButton *listaButton;
    QPushButton *profilButton;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(400, 300);
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setObjectName("verticalLayout");
        mapaButton = new QPushButton(Menu);
        mapaButton->setObjectName("mapaButton");

        verticalLayout->addWidget(mapaButton);

        listaButton = new QPushButton(Menu);
        listaButton->setObjectName("listaButton");

        verticalLayout->addWidget(listaButton);

        profilButton = new QPushButton(Menu);
        profilButton->setObjectName("profilButton");

        verticalLayout->addWidget(profilButton);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        mapaButton->setText(QCoreApplication::translate("Menu", "Mapa", nullptr));
        listaButton->setText(QCoreApplication::translate("Menu", "Lista ska\305\202", nullptr));
        profilButton->setText(QCoreApplication::translate("Menu", "Profil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
