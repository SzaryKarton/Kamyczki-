#ifndef TRASA_H
#define TRASA_H
//będzie wyskakiwać jako widget na skalce w ramce :pp
#include <QWidget>

namespace Ui {
class Trasa;
}

class Trasa : public QWidget
{
    Q_OBJECT

public:
    explicit Trasa(QWidget *parent = nullptr);
    ~Trasa();
    QString nazwa;
    QString trudnosc;
    QString asekuracja;
    QString wpinki;

private:
    Ui::Trasa *ui;
private slots:
    // Sloty obsługujące kliknięcia przycisków z UI
    void on_edytujButton_clicked();
    void on_zapiszButton_clicked();
};

#endif // TRASA_H
