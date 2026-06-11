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
    ui->skalka1_Button->setIcon(
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
        );
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
}
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
}
