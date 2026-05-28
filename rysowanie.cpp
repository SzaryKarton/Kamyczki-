#include "rysowanie.h"
#include "ui_rysowanie.h"

Rysowanie::Rysowanie(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Rysowanie)
{
    ui->setupUi(this);
}

Rysowanie::~Rysowanie()
{
    delete ui;
}
