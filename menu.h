#ifndef MENU_H
#define MENU_H
#include "mapa.h"
#include "listaskal.h"
#include "profil.h"
#include <QWidget>
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:


    void on_listaButton_clicked();

    void on_mapaButton_clicked();

    void on_profilButton_clicked();

private:
    Ui::Menu *ui;

};

#endif // MENU_H
