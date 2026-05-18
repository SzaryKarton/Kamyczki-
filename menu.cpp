#include "menu.h"
#include "ui_menu.h"
#include "nawigator.h"
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
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    Nawigator n;
    n.openWidget(glowneOkno, glowneOkno->theListaSkal);
}


void Menu::on_mapaButton_clicked()
{



}


void Menu::on_profilButton_clicked()
{
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    Nawigator n;
    n.openWidget(glowneOkno, glowneOkno->theProfil);
}


