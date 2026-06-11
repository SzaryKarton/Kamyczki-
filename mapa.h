#ifndef MAPA_H
#define MAPA_H

#include <QWidget>

namespace Ui {
class Mapa;
}

class Mapa : public QWidget
{
    Q_OBJECT

public:
    explicit Mapa(QWidget *parent = nullptr);
    ~Mapa();

private:
    Ui::Mapa *ui;

private slots:
    void on_backButton_clicked();
    void on_skalka1_Button_clicked();
    void on_skalka2_Button_clicked();
    void on_skalka3_Button_clicked();
    void on_skalka4_Button_clicked();
};

#endif // MAPA_H
