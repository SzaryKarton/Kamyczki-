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
};

#endif // MAPA_H
