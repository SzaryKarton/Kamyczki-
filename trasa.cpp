#include "trasa.h"
#include "ui_trasa.h"

Trasa::Trasa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Trasa)
{
    ui->setupUi(this);
}

Trasa::~Trasa()
{
    delete ui;
}
