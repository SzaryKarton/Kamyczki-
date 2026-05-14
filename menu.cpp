#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}
Menu::~Menu()
{
    delete ui;
}



void Menu::on_listaButton_clicked()
{
    ;
    emit requestOpenSecondWidget();
}


void Menu::on_pushButton_clicked()
{

    emit requestOpenMapa();

}


void Menu::on_pushButton_3_clicked()
{
    emit requestOpenProfil();
}

