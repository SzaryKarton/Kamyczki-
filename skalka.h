#ifndef SKALKA_H
#define SKALKA_H

#include <QWidget>

namespace Ui {
class Skalka;
}

class Skalka : public QWidget
{
    Q_OBJECT

public:
    explicit Skalka(QWidget *parent = nullptr);
    ~Skalka();

private:
    Ui::Skalka *ui;
};

#endif // SKALKA_H
