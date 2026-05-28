#include "mapa.h"
#include "ui_mapa.h"

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
