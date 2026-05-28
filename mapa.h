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
};

#endif // MAPA_H
