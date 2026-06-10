#include "mapa.h"
#include "ui_mapa.h"
#include "menu.h"
#include "mainWindow.h"
#include "nawigator.h"

Mapa::Mapa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mapa)
{
    ui->setupUi(this);
}

Mapa::~Mapa()
{
    delete ui;
}
void Mapa::on_backButton_clicked() {
    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(
            this->window()
            );

    Nawigator n;

    Menu *do_otwarcia =
        new Menu(glowneOkno);

    n.openWidget(
        glowneOkno,
        do_otwarcia
        );
}
