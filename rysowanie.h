#ifndef RYSOWANIE_H
#define RYSOWANIE_H
//dodawanie zdjęcia
//rysowanie kropek
//łączenie kropek
#include <QWidget>

namespace Ui {
class Rysowanie;
}

class Rysowanie : public QWidget
{
    Q_OBJECT

public:
    explicit Rysowanie(QWidget *parent = nullptr);
    ~Rysowanie();

private:
    Ui::Rysowanie *ui;
};

#endif // RYSOWANIE_H
