#include "trasa.h"
#include "ui_trasa.h"
#include "databasemanager.h"
#include "datamanager.h"
#include <QDebug>

Trasa::Trasa(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Trasa)
{
    ui->setupUi(this);

    ui->nazwa->setReadOnly(true);
    ui->trudnosc->setReadOnly(true);
    ui->wpinki->setReadOnly(true);
    ui->asekuracja->setReadOnly(true);

    ui->zapiszButton->setEnabled(false);

    ui->nazwa->setText(this->nazwa);
    ui->trudnosc->setText(this->trudnosc);
    ui->wpinki->setText(this->wpinki);
    ui->asekuracja->setText(this->asekuracja);
}

Trasa::~Trasa()
{
    delete ui;
}

void Trasa::on_edytujButton_clicked()
{
    ui->nazwa->setReadOnly(false);
    ui->trudnosc->setReadOnly(false);
    ui->wpinki->setReadOnly(false);
    ui->asekuracja->setReadOnly(false);

    ui->zapiszButton->setEnabled(true);
}

void Trasa::on_zapiszButton_clicked()
{
    this->nazwa = ui->nazwa->text();
    this->trudnosc = ui->trudnosc->text();
    this->wpinki = ui->wpinki->text();
    this->asekuracja = ui->asekuracja->text();

    ui->nazwa->setReadOnly(true);
    ui->trudnosc->setReadOnly(true);
    ui->wpinki->setReadOnly(true);
    ui->asekuracja->setReadOnly(true);

    ui->zapiszButton->setEnabled(false);

    qDebug() << "Dane trasy zaktualizowane w obiekcie:" << this->nazwa;

    // Automatyczny trwały zapis do pliku bazy danych
    DatabaseManager::instance().saveSkalka(dataManager::instance().wszystkie_skalki);

    // Zamyka pop-up i płynnie wraca do widoku skałki
    this->close();
}
