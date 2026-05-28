/********************************************************************************
** Form generated from reading UI file 'profil.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFIL_H
#define UI_PROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profil
{
public:
    QWidget *centralwidget;
    QLabel *Avatar_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *nick_label;
    QLineEdit *nick_lineEdit;
    QLabel *status_label;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QLabel *info3;
    QLabel *info4;
    QListWidget *eq_ListWidget;
    QLineEdit *eq_LineEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *add_eq;
    QPushButton *remove_eq;
    QWidget *layoutWidget2;
    QFormLayout *formLayout;
    QLabel *info1;
    QLabel *info2;
    QListWidget *skills_ListWidget;
    QLineEdit *skill_LineEdit;
    QVBoxLayout *verticalLayout_4;
    QPushButton *add_skill;
    QPushButton *remove_skill;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *info5;
    QTextEdit *profile_info;
    QHBoxLayout *horizontalLayout;
    QPushButton *accedit_button;
    QPushButton *accsave_button;
    QPushButton *cofnijTemp;
    QMenuBar *menubar;

    void setupUi(QWidget *Profil)
    {
        if (Profil->objectName().isEmpty())
            Profil->setObjectName("Profil");
        Profil->resize(660, 882);
        Profil->setMinimumSize(QSize(140, 140));
        centralwidget = new QWidget(Profil);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 670, 866));
        Avatar_label = new QLabel(centralwidget);
        Avatar_label->setObjectName("Avatar_label");
        Avatar_label->setGeometry(QRect(50, 30, 140, 140));
        Avatar_label->setMaximumSize(QSize(140, 140));
        Avatar_label->setFrameShape(QFrame::Shape::Box);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 180, 141, 82));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        nick_label = new QLabel(layoutWidget);
        nick_label->setObjectName("nick_label");

        verticalLayout_2->addWidget(nick_label);

        nick_lineEdit = new QLineEdit(layoutWidget);
        nick_lineEdit->setObjectName("nick_lineEdit");
        nick_lineEdit->setFrame(false);

        verticalLayout_2->addWidget(nick_lineEdit);

        status_label = new QLabel(layoutWidget);
        status_label->setObjectName("status_label");

        verticalLayout_2->addWidget(status_label);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(50, 560, 372, 276));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        info3 = new QLabel(layoutWidget1);
        info3->setObjectName("info3");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, info3);

        info4 = new QLabel(layoutWidget1);
        info4->setObjectName("info4");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, info4);

        eq_ListWidget = new QListWidget(layoutWidget1);
        eq_ListWidget->setObjectName("eq_ListWidget");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, eq_ListWidget);

        eq_LineEdit = new QLineEdit(layoutWidget1);
        eq_LineEdit->setObjectName("eq_LineEdit");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, eq_LineEdit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        add_eq = new QPushButton(layoutWidget1);
        add_eq->setObjectName("add_eq");

        verticalLayout_3->addWidget(add_eq);

        remove_eq = new QPushButton(layoutWidget1);
        remove_eq->setObjectName("remove_eq");

        verticalLayout_3->addWidget(remove_eq);


        formLayout_2->setLayout(2, QFormLayout::ItemRole::FieldRole, verticalLayout_3);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(50, 270, 372, 281));
        formLayout = new QFormLayout(layoutWidget2);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        info1 = new QLabel(layoutWidget2);
        info1->setObjectName("info1");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, info1);

        info2 = new QLabel(layoutWidget2);
        info2->setObjectName("info2");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, info2);

        skills_ListWidget = new QListWidget(layoutWidget2);
        skills_ListWidget->setObjectName("skills_ListWidget");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, skills_ListWidget);

        skill_LineEdit = new QLineEdit(layoutWidget2);
        skill_LineEdit->setObjectName("skill_LineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, skill_LineEdit);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        add_skill = new QPushButton(layoutWidget2);
        add_skill->setObjectName("add_skill");
        add_skill->setEnabled(true);

        verticalLayout_4->addWidget(add_skill);

        remove_skill = new QPushButton(layoutWidget2);
        remove_skill->setObjectName("remove_skill");

        verticalLayout_4->addWidget(remove_skill);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, verticalLayout_4);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(210, 30, 401, 221));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        info5 = new QLabel(layoutWidget3);
        info5->setObjectName("info5");

        verticalLayout->addWidget(info5);

        profile_info = new QTextEdit(layoutWidget3);
        profile_info->setObjectName("profile_info");
        profile_info->setReadOnly(true);

        verticalLayout->addWidget(profile_info);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        accedit_button = new QPushButton(layoutWidget3);
        accedit_button->setObjectName("accedit_button");

        horizontalLayout->addWidget(accedit_button);

        accsave_button = new QPushButton(layoutWidget3);
        accsave_button->setObjectName("accsave_button");
        accsave_button->setEnabled(false);

        horizontalLayout->addWidget(accsave_button);


        verticalLayout->addLayout(horizontalLayout);

        cofnijTemp = new QPushButton(centralwidget);
        cofnijTemp->setObjectName("cofnijTemp");
        cofnijTemp->setGeometry(QRect(530, 340, 90, 29));
        menubar = new QMenuBar(Profil);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 660, 25));

        retranslateUi(Profil);

        QMetaObject::connectSlotsByName(Profil);
    } // setupUi

    void retranslateUi(QWidget *Profil)
    {
        Profil->setWindowTitle(QCoreApplication::translate("Profil", "MainWindow", nullptr));
        Avatar_label->setText(QCoreApplication::translate("Profil", "Avatar", nullptr));
        nick_label->setText(QCoreApplication::translate("Profil", "Nick", nullptr));
        status_label->setText(QCoreApplication::translate("Profil", "Status", nullptr));
        info3->setText(QCoreApplication::translate("Profil", "Sprz\304\231t:", nullptr));
        info4->setText(QCoreApplication::translate("Profil", "Nowy sprz\304\231t:", nullptr));
        add_eq->setText(QCoreApplication::translate("Profil", "Dodaj", nullptr));
        remove_eq->setText(QCoreApplication::translate("Profil", "Usu\305\204", nullptr));
        info1->setText(QCoreApplication::translate("Profil", "Umiej\304\231tno\305\233ci:", nullptr));
        info2->setText(QCoreApplication::translate("Profil", "Nowa umiej\304\231tno\305\233\304\207:", nullptr));
        add_skill->setText(QCoreApplication::translate("Profil", "Dodaj", nullptr));
        remove_skill->setText(QCoreApplication::translate("Profil", "Usu\305\204", nullptr));
        info5->setText(QCoreApplication::translate("Profil", "O mnie:", nullptr));
        accedit_button->setText(QCoreApplication::translate("Profil", "Edytuj profil", nullptr));
        accsave_button->setText(QCoreApplication::translate("Profil", "Zapisz Profil", nullptr));
        cofnijTemp->setText(QCoreApplication::translate("Profil", "cofnij temp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Profil: public Ui_Profil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFIL_H
