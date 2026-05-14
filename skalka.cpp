#include "skalka.h"
#include "ui_skalka.h"

Skalka::Skalka(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Skalka)
{
    ui->setupUi(this);
}

Skalka::~Skalka()
{
    delete ui;
}
