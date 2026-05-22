#ifndef SKALKAUNIVERSAL_H
#define SKALKAUNIVERSAL_H

#include <QWidget>
#include "mainWindow.h"
#include "nawigator.h"


namespace Ui {
class SkalkaUniversal;
}

class SkalkaUniversal : public QWidget
{
    Q_OBJECT

public:
    explicit SkalkaUniversal(QWidget *parent = nullptr);
    ~SkalkaUniversal();
    QString nazwa;
    QString wspolrzedne;
    QString rodzaj_skaly;
    int wysokosc;
    QVector<QString> trasy;

private slots:
    //void on_pushButton_2_clicked();

    void on_edytuj_clicked();

    void on_cofnij_clicked();

private:
    Ui::SkalkaUniversal *ui;
};

#endif // SKALKAUNIVERSAL_H
