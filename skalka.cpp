#include "skalka.h"
#include "ui_skalka.h"
#include "listaskal.h"

#include "datamanager.h"
#include "databasemanager.h"
#include "trasa.h"

Skalka::Skalka(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Skalka)
{
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
            QPushButton *btn = new QPushButton(trasa->nazwa, this);
            //connect(btn, &QPushButton::clicked, this, &ListaSkal::obslugaKliknieciaSkalki);
            btn->setProperty("indeks_trasy", i);
            ukladPionowy->addWidget(btn);
            btn->show();
            this->update();

        }
    }
}
void Skalka::odpal_trasy(Skalka* skalka)
{
    QVBoxLayout *ukladPionowy = ui->trasyBox;
    ukladPionowy->setAlignment(Qt::AlignTop);
    for (int i = 0; i < skalka->trasy.size(); ++i)
    {
        Trasa* trasa = skalka->trasy[i];

        if (trasa != nullptr)
        {
            //zmienić nazwę
            QPushButton *btn = new QPushButton(trasa->nazwa, skalka);
            connect(btn, &QPushButton::clicked, this, &Skalka::obslugaKliknieciaTrasy);
            btn->setProperty("indeks_trasy", i);
            ukladPionowy->addWidget(btn);
            btn->show();
            skalka->update();

        }
    }
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
        daneWMemore->sciezka_zdjecia = this->sciezka_zdjecia;

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

    this->trasy = daneSkalki->trasy;
    this->sciezka_zdjecia = daneSkalki->sciezka_zdjecia;

    // Jeśli ścieżka nie jest pusta, ładujemy zdjęcie na ekran
    if (!this->sciezka_zdjecia.isEmpty() && ui->zdjecie_label) {
        QPixmap pix(this->sciezka_zdjecia);
        if (!pix.isNull()) {
            ui->zdjecie_label->setPixmap(pix.scaled(ui->zdjecie_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

}
void Skalka::on_dodajTrase_clicked()
{
    qDebug() << "KLIKNIETO PRZYCISK DODAJ TRASE!";
    int index = dataManager::instance().wszystkie_skalki.indexOf(this);
    //QFrame *ramka = qobject_cast<QFrame*>(ui->daneTrasy->layout());
    QFrame *ramka = ui->daneTrasy;
    Trasa *n_trasa = new Trasa(this);
    this->trasy.append(n_trasa);
    Nawigator n;
    //ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n_trasa->setParent(ramka);
    n.openInFrameTrasa(ramka, n_trasa);
    n_trasa->show();
    this->update();

    QVBoxLayout *box = ui->trasyBox;
    QPushButton *btn = new QPushButton("test", this);
    //connect(btn, &QPushButton::clicked, this, &ListaSkal::obslugaKliknieciaSkalki);
    //btn->setProperty("indeks_trasy", i);
    box->addWidget(btn);
    this->update();

    if (index >= 0) {
        // Jeśli skałka już istnieje na liście, bezpiecznie aktualizujemy
        dataManager::instance().wszystkie_skalki[index] = this;
    } else {
        // Jeśli jej nie ma (indeks wynosi -1), nie dotykamy tablicy operatorem [], tylko dopisujemy na koniec!
        dataManager::instance().wszystkie_skalki.append(this);
    }}

void Skalka::obslugaKliknieciaTrasy() {
    qDebug() << "=== KLIKNIETO TRASE ===";
    QPushButton *kliknietyGuzik = qobject_cast<QPushButton*>(sender());

    if (kliknietyGuzik) {
        int indeksWBazie = kliknietyGuzik->property("indeks_trasy").toInt();
        QFrame *ramka = ui->daneTrasy;

        if (ramka) {
            // 1. Zabezpieczenie przed crashem (index out of range)
            if (indeksWBazie < 0 || indeksWBazie >= this->trasy.size()) return;

            Trasa *wybranaTrasa = this->trasy[indeksWBazie];

            if (wybranaTrasa != nullptr) {
                // 2. Jeśli ramka nie ma layoutu, tworzymy go dynamicznie w C++
                if (ramka->layout() == nullptr) {
                    QVBoxLayout *nowyLayout = new QVBoxLayout(ramka);
                    nowyLayout->setContentsMargins(0, 0, 0, 0);
                    ramka->setLayout(nowyLayout);
                }

                // 3. Czyścimy ramkę z poprzednio otwartej trasy, żeby widoki się nie nakładały
                QLayoutItem *item;
                while ((item = ramka->layout()->takeAt(0)) != nullptr) {
                    if (item->widget()) {
                        item->widget()->hide(); // Ukrywamy starą trasę
                    }
                    delete item;
                }

                // 4. Konfiguracja i wstrzyknięcie trasy do ramki
                wybranaTrasa->setWindowFlags(Qt::Widget);
                wybranaTrasa->setParent(ramka);

                wybranaTrasa->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                wybranaTrasa->setMinimumSize(0, 0);

                // Wywołanie Twojego Nawigatora
                Nawigator n;
                n.openInFrameTrasa(ramka, wybranaTrasa);

                // JAWNE DODANIE DO LAYOUTU (To sprawi, że trasa się pokaże)
                ramka->layout()->addWidget(wybranaTrasa);

                wybranaTrasa->show();
                ramka->update();
            }
        }
    }
    this->update();
}


#include <QFileDialog>
#include <QPixmap>

void Skalka::on_dodajZdjecie_clicked()
{
    // 1. Otwieramy systemowe okno wyboru pliku graficznego
    QString plik = QFileDialog::getOpenFileName(this,
                                                tr("Wybierz zdjęcie skałki"), "", tr("Obrazy (*.png *.jpg *.jpeg)"));

    if (!plik.isEmpty()) {
        // 2. Zapisujemy ścieżkę w obiekcie
        this->sciezka_zdjecia = plik;

        // 3. Ładujemy obrazek i skalujemy go, żeby zmieścił się w QLabel w UI
        QPixmap pix(plik);
        if (!pix.isNull()) {
            // Skalowanie z zachowaniem proporcji do wymiarów Twojego Labela
            ui->zdjecie_label->setPixmap(pix.scaled(ui->zdjecie_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        // 4. Trwały zapis do bazy danych
        DatabaseManager::instance().saveSkalka(dataManager::instance().wszystkie_skalki);
    }
}
