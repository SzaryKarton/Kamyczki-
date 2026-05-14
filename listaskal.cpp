#include "listaskal.h"
#include "ui_listaskal.h"

ListaSkal::ListaSkal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListaSkal)
{
    ui->setupUi(this);
}

ListaSkal::~ListaSkal()
{
    delete ui;
}
void ListaSkal:: on_skala1Button_clicked(){
    emit requestOpenSkala();
}
