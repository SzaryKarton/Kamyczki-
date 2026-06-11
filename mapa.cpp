#include "mapa.h"
#include "ui_mapa.h"
#include "menu.h"
#include "mainWindow.h"
#include "nawigator.h"
#include "listaskal.h"

#include <QIcon>
#include <QSize>

Mapa::Mapa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mapa)
{
    ui->setupUi(this);
    /*ui->skalka1_Button->setIcon(
        QIcon(":/zdjecia/skalka1.jpg")
        );

    ui->skalka1_Button->setIconSize(
        QSize(120,120)
        );
    //
    ui->skalka2_Button->setIcon(
        QIcon(":/zdjecia/skalka2.jpg")
        );

    ui->skalka2_Button->setIconSize(
        QSize(120,120)
        );
    //
    ui->skalka3_Button->setIcon(
        QIcon(":/zdjecia/skalka3.jpg")
        );

    ui->skalka3_Button->setIconSize(
        QSize(120,120)
        );
    //
    ui->skalka4_Button->setIcon(
        QIcon(":/zdjecia/skalka4.jpg")
        );

    ui->skalka4_Button->setIconSize(
        QSize(120,120)
        );*/
}

Mapa::~Mapa()
{
    delete ui;
}
void Mapa::on_backButton_clicked() {
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
}/*
void Mapa::on_skalka1_Button_clicked() {
    qDebug() << "KLIK 1";
    auto& db = dataManager::instance();

    if(db.wszystkie_skalki.isEmpty())
        return;

    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(this->window());

    if(!glowneOkno)
        return;

    Skalka *ekranSkalki = new Skalka(nullptr);

    ekranSkalki->ustawDane(
        db.wszystkie_skalki[0]
        );

    Nawigator n;

    n.openWidget(
        glowneOkno,
        ekranSkalki
        );
}
void Mapa::on_skalka2_Button_clicked() {
    auto& db = dataManager::instance();

    if(db.wszystkie_skalki.isEmpty())
        return;

    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(this->window());

    if(!glowneOkno)
        return;

    Skalka *ekranSkalki = new Skalka(nullptr);

    ekranSkalki->ustawDane(
        db.wszystkie_skalki[1]
        );

    Nawigator n;

    n.openWidget(
        glowneOkno,
        ekranSkalki
        );
}
void Mapa::on_skalka3_Button_clicked() {
    auto& db = dataManager::instance();

    if(db.wszystkie_skalki.isEmpty())
        return;

    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(this->window());

    if(!glowneOkno)
        return;

    Skalka *ekranSkalki = new Skalka(nullptr);

    ekranSkalki->ustawDane(
        db.wszystkie_skalki[2]
        );

    Nawigator n;

    n.openWidget(
        glowneOkno,
        ekranSkalki
        );
}
void Mapa::on_skalka4_Button_clicked() {
    auto& db = dataManager::instance();

    if(db.wszystkie_skalki.isEmpty())
        return;

    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(this->window());

    if(!glowneOkno)
        return;

    Skalka *ekranSkalki = new Skalka(nullptr);

    ekranSkalki->ustawDane(
        db.wszystkie_skalki[3]
        );

    Nawigator n;

    n.openWidget(
        glowneOkno,
        ekranSkalki
        );
}*/
void Mapa::showEvent(QShowEvent *event)
{   qDebug()<< "event mapa otwarte";
    QWidget::showEvent(event);

    // 1. Czyszczenie starych guzików z mapy przy ponownym otwarciu (żeby się nie dublowały)
    QList<QPushButton*> obecneGuziki = this->findChildren<QPushButton*>();
    for (QPushButton* g : obecneGuziki) {
        if (g->property("is_map_pin").toBool()) {
            delete g;
        }
    }

    const QVector<Skalka*>& lista = dataManager::instance().wszystkie_skalki;


    for (int i = 0; i < lista.size(); ++i) {
        Skalka* skalka = lista[i];
        if (!skalka) continue;
        if (!skalka->wspolrzedne.isEmpty()){


        QStringList czesci = skalka->wspolrzedne.split(",");
        if (czesci.size() < 2) continue;

        int x = czesci[0].trimmed().toInt();
        int y = czesci[1].trimmed().toInt();


        QPushButton *pin = new QPushButton(skalka->nazwa, this);
        pin->setProperty("is_map_pin", true);
        pin->setProperty("indeks_skalki", i);


        pin->resize(90, 30);
        pin->setStyleSheet("background-color: #e74c3c; color: white; font-weight: bold; border-radius: 4px;");

        pin->move(x, y);

        connect(pin, &QPushButton::clicked, this, &Mapa::obslugaKliknieciaPinu);

        pin->show(); }
        else
            continue;
    }

    }


void Mapa::obslugaKliknieciaPinu()
{
    QPushButton *kliknietyPin = qobject_cast<QPushButton*>(sender());
    if (!kliknietyPin) return;

    int index = kliknietyPin->property("indeks_skalki").toInt();
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());


    if (glowneOkno && index >= 0 && index < dataManager::instance().wszystkie_skalki.size()) {
        Skalka *wybranaSkalka = dataManager::instance().wszystkie_skalki[index];
        if (wybranaSkalka) {
            Skalka *ekranSkalki = new Skalka(nullptr);
            ekranSkalki->ustawDane(wybranaSkalka);

            Nawigator n;
            n.openWidget(glowneOkno, ekranSkalki);
        }
    }
}
