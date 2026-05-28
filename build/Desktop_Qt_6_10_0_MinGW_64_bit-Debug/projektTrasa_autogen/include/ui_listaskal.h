/********************************************************************************
** Form generated from reading UI file 'listaskal.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTASKAL_H
#define UI_LISTASKAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListaSkal
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *line;
    QPushButton *dodajSkale;

    void setupUi(QWidget *ListaSkal)
    {
        if (ListaSkal->objectName().isEmpty())
            ListaSkal->setObjectName("ListaSkal");
        ListaSkal->resize(420, 405);
        verticalLayout = new QVBoxLayout(ListaSkal);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(ListaSkal);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 396, 381));
        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName("line");
        line->setGeometry(QRect(11, 117, 374, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        dodajSkale = new QPushButton(scrollAreaWidgetContents);
        dodajSkale->setObjectName("dodajSkale");
        dodajSkale->setGeometry(QRect(11, 233, 96, 29));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ListaSkal);

        QMetaObject::connectSlotsByName(ListaSkal);
    } // setupUi

    void retranslateUi(QWidget *ListaSkal)
    {
        ListaSkal->setWindowTitle(QCoreApplication::translate("ListaSkal", "Form", nullptr));
        dodajSkale->setText(QCoreApplication::translate("ListaSkal", "Dodaj Ska\305\202\304\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListaSkal: public Ui_ListaSkal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTASKAL_H
