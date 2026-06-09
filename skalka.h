#ifndef SKALKA_H
#define SKALKA_H
//docelowo skleja dane skałki, guzik na mapie i przechowuje trasy
#include <QWidget>
#include <QTableWidget>
#include "mainWindow.h"
#include "nawigator.h"
#include "trasa.h"



namespace Ui {
class Skalka;
}

class Skalka : public QWidget
{
    Q_OBJECT

public:
    explicit Skalka(QWidget *parent = nullptr);
    ~Skalka();
    QString nazwa = "";
    QString wspolrzedne;
    QString rodzaj_skaly;
    int wysokosc;
    QVector<Trasa*> trasy;
    void ustawDane(Skalka* daneSkalki);
private slots:
    void on_edytuj_clicked();
    void on_tabela_itemChanged(QTableWidgetItem *item);
    void on_cofnij_clicked();

    void on_zapisz_clicked();

    void on_dodajTrase_clicked();

private:
    Ui::Skalka *ui;
};

#endif // SKALKA_H
