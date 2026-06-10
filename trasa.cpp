#include "trasa.h"
#include "ui_trasa.h"
#include <QDebug>

Trasa::Trasa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Trasa)
{
    ui->setupUi(this);

    // Domyslnie blokujemy pola do edycji przy otwarciu widoku
    ui->nazwa->setReadOnly(true);
    ui->trudnosc->setReadOnly(true);
    ui->wpinki->setReadOnly(true);
    ui->asekuracja->setReadOnly(true);

    // Przycisk Zapisz jest domyslnie wylaczony, dopoki nie klikniemy Edytuj
    ui->zapiszButton->setEnabled(false);

    // Synchronizacja z wewnetrznymi danymi obiektu (jeśli wczytano z bazy)
    ui->nazwa->setText(this->nazwa);
    ui->trudnosc->setText(this->trudnosc);
    ui->wpinki->setText(this->wpinki); // Używa zmiennej wspinki z trasa.h
    ui->asekuracja->setText(this->asekuracja);
}

Trasa::~Trasa()
{
    delete ui;
}

void Trasa::on_edytujButton_clicked()
{
    // Odblokowanie pol tekstowych do edycji
    ui->nazwa->setReadOnly(false);
    ui->trudnosc->setReadOnly(false);
    ui->wpinki->setReadOnly(false);
    ui->asekuracja->setReadOnly(false);

    // Aktywacja przycisku Zapisz
    ui->zapiszButton->setEnabled(true);
}

void Trasa::on_zapiszButton_clicked()
{
    // Zapisujemy wpisane teksty z UI z powrotem do zmiennych obiektu
    this->nazwa = ui->nazwa->text();
    this->trudnosc = ui->trudnosc->text();
    this->wpinki = ui->wpinki->text(); // Zapis do zmiennej strukturalnej wspinki
    this->asekuracja = ui->asekuracja->text();

    // Ponowne zablokowanie pol tekstowych
    ui->nazwa->setReadOnly(true);
    ui->trudnosc->setReadOnly(true);
    ui->wpinki->setReadOnly(true);
    ui->asekuracja->setReadOnly(true);

    // Wylaczenie przycisku zapisu
    ui->zapiszButton->setEnabled(false);

    qDebug() << "Dane trasy zaktualizowane w obiekcie:" << this->nazwa;
}
