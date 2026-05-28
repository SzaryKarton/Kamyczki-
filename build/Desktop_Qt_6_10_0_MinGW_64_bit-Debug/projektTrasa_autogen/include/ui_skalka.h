/********************************************************************************
** Form generated from reading UI file 'skalka.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKALKA_H
#define UI_SKALKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Skalka
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *edytuj;
    QPushButton *cofnij;
    QPushButton *dodajTrase;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *tabela;
    QLabel *label_2;
    QTreeWidget *trasy;

    void setupUi(QWidget *Skalka)
    {
        if (Skalka->objectName().isEmpty())
            Skalka->setObjectName("Skalka");
        Skalka->resize(800, 800);
        horizontalLayoutWidget = new QWidget(Skalka);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 791, 791));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        edytuj = new QPushButton(horizontalLayoutWidget);
        edytuj->setObjectName("edytuj");

        horizontalLayout_3->addWidget(edytuj);

        cofnij = new QPushButton(horizontalLayoutWidget);
        cofnij->setObjectName("cofnij");

        horizontalLayout_3->addWidget(cofnij);

        dodajTrase = new QPushButton(horizontalLayoutWidget);
        dodajTrase->setObjectName("dodajTrase");

        horizontalLayout_3->addWidget(dodajTrase);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        tabela = new QTableWidget(horizontalLayoutWidget);
        if (tabela->columnCount() < 1)
            tabela->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tabela->rowCount() < 4)
            tabela->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabela->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabela->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabela->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabela->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabela->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabela->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabela->setItem(2, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabela->setItem(3, 0, __qtablewidgetitem8);
        tabela->setObjectName("tabela");

        verticalLayout_2->addWidget(tabela);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        trasy = new QTreeWidget(horizontalLayoutWidget);
        new QTreeWidgetItem(trasy);
        trasy->setObjectName("trasy");

        verticalLayout_2->addWidget(trasy);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 2);

        retranslateUi(Skalka);

        QMetaObject::connectSlotsByName(Skalka);
    } // setupUi

    void retranslateUi(QWidget *Skalka)
    {
        Skalka->setWindowTitle(QCoreApplication::translate("Skalka", "Form", nullptr));
        edytuj->setText(QCoreApplication::translate("Skalka", "Edytuj", nullptr));
        cofnij->setText(QCoreApplication::translate("Skalka", "cofnij", nullptr));
        dodajTrase->setText(QCoreApplication::translate("Skalka", "Dodaj tras\304\231", nullptr));
        label->setText(QCoreApplication::translate("Skalka", "info", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Skalka", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabela->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Skalka", "Nazwa", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabela->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Skalka", "Wysoko\305\233\304\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabela->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Skalka", "Rodzaj ska\305\202y", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabela->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Skalka", "Wsp\303\263\305\202rz\304\231dne", nullptr));

        const bool __sortingEnabled = tabela->isSortingEnabled();
        tabela->setSortingEnabled(false);
        tabela->setSortingEnabled(__sortingEnabled);

        label_2->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = trasy->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Skalka", "Trasy", nullptr));

        const bool __sortingEnabled1 = trasy->isSortingEnabled();
        trasy->setSortingEnabled(false);
        trasy->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class Skalka: public Ui_Skalka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKALKA_H
