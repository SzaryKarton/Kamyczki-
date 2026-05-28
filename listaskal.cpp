#include "listaskal.h"
#include "ui_listaskal.h"


ListaSkal::ListaSkal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListaSkal)
{
    ui->setupUi(this);

    auto& db = dataManager::instance();
    QVBoxLayout *ukladPionowy = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ukladPionowy->setAlignment(Qt::AlignTop); // Przyciski będą się układać od góry

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
            Skalka *wybranaSkalka = dataManager::instance().wszystkie_skalki[indeksWBazie];

            if (wybranaSkalka != nullptr)
            {
                Nawigator n;
                n.openWidget(glowneOkno, wybranaSkalka);
            }
        }
    }
}

void ListaSkal::on_dodajSkale_clicked()
{
    Skalka *n_skalka = new Skalka;
    dataManager::instance().wszystkie_skalki.append(n_skalka);
    Nawigator n;
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    //ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n.openWidget(glowneOkno, n_skalka);
}

