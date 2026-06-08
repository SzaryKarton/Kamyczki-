#include "listaskal.h"
#include "datamanager.h"
#include "ui_listaskal.h"
#include "databasemanager.h"
#include "menu.h"
#include "mainWindow.h"
#include "nawigator.h"

ListaSkal::ListaSkal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListaSkal)
{
    ui->setupUi(this);
    auto& db = dataManager::instance();
    auto& wczytaj_stad = DatabaseManager:: instance();
    QVBoxLayout *ukladPionowy = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ukladPionowy->setAlignment(Qt::AlignTop);
    db.wszystkie_skalki = wczytaj_stad.wczytajSkalki();
    for (int i = 0; i < db.wszystkie_skalki.size(); ++i)
    {
        Skalka* skalka = db.wszystkie_skalki[i];

        if (skalka != nullptr)
        {
            //zmienić nazwę
            QPushButton *btn = new QPushButton(skalka->nazwa, this);
            connect(btn, &QPushButton::clicked, this, &ListaSkal::obslugaKliknieciaSkalki);
            btn->setProperty("indeks_skalki", i);
            ukladPionowy->addWidget(btn);
        }

    }
}
ListaSkal::~ListaSkal()
{
    delete ui;
}
void ListaSkal::obslugaKliknieciaSkalki()
{
    QPushButton *kliknietyGuzik = qobject_cast<QPushButton*>(sender());
    if (kliknietyGuzik)
    {
        int indeksWBazie = kliknietyGuzik->property("indeks_skalki").toInt();
        MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());

        if (glowneOkno)
        {

            ::Skalka *wybranaSkalka = dataManager::instance().wszystkie_skalki[indeksWBazie];

            if (wybranaSkalka != nullptr)
            {
                class Skalka *ekranSkalki = new class Skalka(nullptr);
                ekranSkalki->ustawDane(wybranaSkalka);
                Nawigator n;
                n.openWidget(glowneOkno, ekranSkalki);
            }
        }
    }
}

void ListaSkal::on_dodajSkale_clicked()
{
    Skalka *n_skalka = new Skalka(nullptr);
    dataManager::instance().wszystkie_skalki.append(n_skalka);
    Nawigator n;
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    //ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n.openWidget(glowneOkno, n_skalka);
}
void ListaSkal::on_backButton_clicked() {
    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(
            this->window()
            );

    Nawigator n;

    Menu *do_otwarcia =
        new Menu(glowneOkno);

    n.openWidget(
        glowneOkno,
        do_otwarcia
        );
}
