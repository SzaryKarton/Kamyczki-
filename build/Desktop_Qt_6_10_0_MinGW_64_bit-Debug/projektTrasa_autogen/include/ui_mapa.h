/********************************************************************************
** Form generated from reading UI file 'mapa.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPA_H
#define UI_MAPA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mapa
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Mapa)
    {
        if (Mapa->objectName().isEmpty())
            Mapa->setObjectName("Mapa");
        Mapa->resize(707, 641);
        Mapa->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(88, 127, 70);"));
        pushButton = new QPushButton(Mapa);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 130, 111, 101));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/zdjecia skal/42462mountain_99130.png);"));
        pushButton_2 = new QPushButton(Mapa);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 390, 111, 101));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/zdjecia skal/42462mountain_99130.png);"));
        pushButton_3 = new QPushButton(Mapa);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(460, 400, 111, 91));
        pushButton_3->setStyleSheet(QString::fromUtf8("image: url(:/zdjecia skal/42462mountain_99130.png);"));
        pushButton_4 = new QPushButton(Mapa);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(450, 80, 101, 91));
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/zdjecia skal/42462mountain_99130.png);"));

        retranslateUi(Mapa);

        QMetaObject::connectSlotsByName(Mapa);
    } // setupUi

    void retranslateUi(QWidget *Mapa)
    {
        Mapa->setWindowTitle(QCoreApplication::translate("Mapa", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mapa: public Ui_Mapa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPA_H
