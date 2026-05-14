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

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Menu *ui;
signals:
    void requestOpenSecondWidget();
    void requestOpenMapa();
    void requestOpenProfil();
};

#endif // MENU_H
