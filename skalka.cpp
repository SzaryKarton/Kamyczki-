#include "skalka.h"
#include "ui_skalka.h"
#include "listaskal.h"
#include "datamanager.h"
#include "databasemanager.h"

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
    if (!glowneOkno) {
        qDebug() << "Błąd: Nie udało się odnaleźć głównego okna!";
        return;
    }

    Nawigator n;
    ListaSkal *do_otwarcia = new ListaSkal(nullptr);
    n.openWidget(glowneOkno, do_otwarcia);
}


void Skalka::on_zapisz_clicked()
{
    int index = dataManager::instance().wszystkie_skalki.indexOf(this);

    QTableWidgetItem* itemNazwa       = ui->tabela->item(0, 1);
    QTableWidgetItem* itemWysokosc    = ui->tabela->item(1, 1);
    QTableWidgetItem* itemRodzajSkaly = ui->tabela->item(2, 1);
    QTableWidgetItem* itemWspolrzedne = ui->tabela->item(3, 1);

    ::Skalka *daneWMemore = dataManager::instance().wszystkie_skalki[index];
    // 3. Przypisujemy wartości do obiektu (z bezpiecznym sprawdzeniem, czy komórki nie są puste)
    if (itemNazwa) {
        this->nazwa = itemNazwa->text();
    }

    if (itemWysokosc) {
        // .toInt() automatycznie zamieni tekst np. "25" na liczbę int
        this->wysokosc = itemWysokosc->text().toInt();
    }

    if (itemRodzajSkaly) {
        this->rodzaj_skaly = itemRodzajSkaly->text();
    }

    if (itemWspolrzedne) {
        this->wspolrzedne = itemWspolrzedne->text();
    }
    if (daneWMemore) {
        // Aktualizujemy dane w pamięci RAM
        daneWMemore->nazwa = this->nazwa;
        daneWMemore->wysokosc = this->wysokosc;
        daneWMemore->rodzaj_skaly =this->rodzaj_skaly;
        daneWMemore->wspolrzedne = this->wspolrzedne;

        // 3. Zapisujemy zaktualizowaną listę do pliku bazy danych
        // Używamy funkcji, którą napisaliśmy wcześniej
        DatabaseManager::instance().saveSkalka(dataManager::instance().wszystkie_skalki);

    }}
void Skalka::ustawDane(::Skalka* daneSkalki)
{
    if (!daneSkalki) return; // Bezpieczeństwo przed pustym wskaźnikiem

    // Wypełniamy poszczególne wiersze w prawej kolumnie (indeks 1)
    // Tworzymy nowe elementy QTableWidgetItem, jeśli komórki były puste

    // 1. Nazwa (Wiersz 0, Kolumna 1)
    ui->tabela->setItem(0, 1, new QTableWidgetItem(daneSkalki->nazwa));

    // 2. Wysokość (Wiersz 1, Kolumna 1) - zamieniamy int na QString
    ui->tabela->setItem(1, 1, new QTableWidgetItem(QString::number(daneSkalki->wysokosc)));

    // 3. Rodzaj skały (Wiersz 2, Kolumna 1)
    ui->tabela->setItem(2, 1, new QTableWidgetItem(daneSkalki->rodzaj_skaly));

    // 4. Współrzędne (Wiersz 3, Kolumna 1)
    ui->tabela->setItem(3, 1, new QTableWidgetItem(daneSkalki->wspolrzedne));
}

