#include "skalka.h"
#include "ui_skalka.h"
#include "listaskal.h"
#include "datamanager.h"

Skalka::Skalka(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Skalka)
{
    ui->setupUi(this);
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Skalka::~Skalka()
{
    delete ui;
}



void Skalka::on_edytuj_clicked()
{
    QTableWidgetItem *aktualnyItem = ui->tabela->currentItem();
    if (aktualnyItem != nullptr)
    {
        aktualnyItem->setFlags(aktualnyItem->flags() | Qt::ItemIsEditable);
        ui->tabela->editItem(aktualnyItem);
    }
}

void Skalka::on_tabela_itemChanged(QTableWidgetItem *item)
{
    if (!item) return;
    int index = dataManager::instance().wszystkie_skalki.indexOf(this);
    int wiersz = item->row();
    QString tekst = item->text();
    switch (wiersz) {
    case 0:
        this->nazwa = tekst;
        break;
    case 1:
        this->wspolrzedne = tekst;
        break;
    case 2:
        this->rodzaj_skaly = tekst;
        break;
    case 3:
        this->wysokosc = tekst.toInt(); // Konwersja QString na int
        break;
    default:
        break;
    }
    dataManager::instance().wszystkie_skalki[index] = this;
}

void Skalka::on_cofnij_clicked()
{
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    Nawigator n;
    ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n.openWidget(glowneOkno, do_otwarcia);
}

