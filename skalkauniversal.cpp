#include "skalkauniversal.h"
#include "ui_skalkauniversal.h"
#include "listaskal.h"

SkalkaUniversal::SkalkaUniversal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SkalkaUniversal)
{
    ui->setupUi(this);
}

SkalkaUniversal::~SkalkaUniversal()
{
    delete ui;
}



void SkalkaUniversal::on_edytuj_clicked()
{
    // 1. Pobieramy wskaźnik na komórkę, którą użytkownik aktualnie zaznaczył myszką
    QTableWidgetItem *aktualnyItem = ui->tabela->currentItem();

    // 2. Sprawdzamy, czy użytkownik w ogóle cokolwiek zaznaczył w tabeli
    if (aktualnyItem != nullptr)
    {
        // 3. Upewniamy się, że komórka ma włączoną flagę edytowalności
        // (na wypadek, gdyby była wcześniej zablokowana)
        aktualnyItem->setFlags(aktualnyItem->flags() | Qt::ItemIsEditable);

        // 4. KLUCZOWA LINIA: Zmuszamy tabelę, aby natychmiast otworzyła tę komórkę w trybie edycji textu
        ui->tabela->editItem(aktualnyItem);
    }
}


void SkalkaUniversal::on_cofnij_clicked()
{
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    Nawigator n;
    //ListaSkal *do_otwarcia = new ListaSkal;
    ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n.openWidget(glowneOkno, do_otwarcia);
}

