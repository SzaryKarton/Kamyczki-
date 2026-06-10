#include "skalka.h"
#include "ui_skalka.h"
#include "listaskal.h"

#include "datamanager.h"
#include "databasemanager.h"
#include "trasa.h"
Skalka::Skalka(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Skalka)
{
    ui->setupUi(this);
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Tutaj nie dajemy pętli generującej przyciski, bo baza danych sama uzupełni obiekt później
}

Skalka::Skalka(const QVector<Trasa*>& wczytaneTrasy,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Skalka)
{
    this->trasy = wczytaneTrasy;
    ui->setupUi(this);
    ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QVBoxLayout *ukladPionowy = ui->trasyBox;
    ukladPionowy->setAlignment(Qt::AlignTop);
    for (int i = 0; i < this->trasy.size(); ++i)
    {
        Trasa* trasa = this->trasy[i];

        if (trasa != nullptr)
        {
            //zmienić nazwę
            QPushButton *btn = new QPushButton("nazwa", this);
            connect(btn, &QPushButton::clicked, this, &Skalka::obslugaKliknieciaTrasy);
            btn->setProperty("indeks_trasy", i);
            ukladPionowy->addWidget(btn);
            btn->show();
        }
    }
}

Skalka::~Skalka()
{
    delete ui;
}

void Skalka::obslugaKliknieciaTrasy() {
    qDebug() << "=== KLIKNIETO TRASE ===";
    QPushButton *kliknietyGuzik = qobject_cast<QPushButton*>(sender());

    if (kliknietyGuzik) {
        int indeksWBazie = kliknietyGuzik->property("indeks_trasy").toInt();
        QFrame *ramka = ui->daneTrasy;

        if (ramka) {
            // Wyciągamy dokładnie tę trasę, która została kliknięta
            Trasa *wybranaTrasa = this->trasy[indeksWBazie];

            if (wybranaTrasa != nullptr) {
                // Twój oryginalny, działający schemat nawigacji
                wybranaTrasa->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                wybranaTrasa->setMinimumSize(0, 0);
                Nawigator n;
                wybranaTrasa->setParent(ramka);
                n.openInFrameTrasa(ramka, wybranaTrasa);
                wybranaTrasa->show();
            }
            this->update();}}
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
/*void Skalka::on_dodajTrase_clicked()
{
    qDebug() << "=== KLIKNIETO PRZYCISK DODAJ TRASE! ===";

    QFrame *ramka = ui->daneTrasy;
    if (!ramka) return;

    // 1. Zapewnienie poprawnego układu pionowego w ramce
    if (ramka->layout() == nullptr) {
        QVBoxLayout *nowyLayout = new QVBoxLayout(ramka);
        nowyLayout->setContentsMargins(0, 0, 0, 0);
        nowyLayout->setSpacing(0);
        ramka->setLayout(nowyLayout);
    }

    // 2. Dynamiczne tworzenie nowej trasy i przypisanie do wektora skałki
    Trasa *n_trasa = new Trasa(ramka);
    this->trasy.append(n_trasa);

    // 3. Rozciąganie i dopasowanie widoku do ramki
    ramka->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    n_trasa->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    Nawigator n;
    n.openInFrameTrasa(ramka, n_trasa);
    ramka->layout()->addWidget(n_trasa);

    n_trasa->show();
    ramka->update();
    this->update();

    // 4. BEZPIECZNA AKTUALIZACJA W DATAMANAGER (Zabezpieczenie przed crashem)
    int index = dataManager::instance().wszystkie_skalki.indexOf(this);
    if (index >= 0) {
        dataManager::instance().wszystkie_skalki[index] = this;
    } else {
        dataManager::instance().wszystkie_skalki.append(this);
    }

    // 5. Trwały zapis struktury do bazy danych SQLite
    DatabaseManager::instance().saveSkalka(dataManager::instance().wszystkie_skalki);
}
*/

void Skalka::on_dodajTrase_clicked()
{
    qDebug() << "KLIKNIETO PRZYCISK DODAJ TRASE!";
    int index = dataManager::instance().wszystkie_skalki.indexOf(this);

    QFrame *ramka = ui->daneTrasy;
    Trasa *n_trasa = new Trasa(this);
    this->trasy.append(n_trasa);
    Nawigator n;
    //ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n_trasa->setParent(ramka);
    n_trasa->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    n_trasa->setMinimumSize(0, 0);
    n.openInFrameTrasa(ramka, n_trasa);
    n_trasa->show();
    this->update();

    QVBoxLayout *box = ui->trasyBox;
    QPushButton *btn = new QPushButton("test", this);
    //connect(btn, &QPushButton::clicked, this, &ListaSkal::obslugaKliknieciaSkalki);
    //btn->setProperty("indeks_trasy", i);
    int aktualnyIndeks = this->trasy.size() - 1;
    btn->setProperty("indeks_trasy", aktualnyIndeks);

    // Łączymy kliknięcie w ten nowy przycisk z Twoją metodą otwierania szczegółów trasy
    connect(btn, &QPushButton::clicked, this, &Skalka::obslugaKliknieciaTrasy);
    box->addWidget(btn);
    this->update();
    if (index >= 0) {
        dataManager::instance().wszystkie_skalki[index] = this;
    } else {
        dataManager::instance().wszystkie_skalki.append(this);
    }
    //dataManager::instance().wszystkie_skalki[index] = this;

}

