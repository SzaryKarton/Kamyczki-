#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "listaskal.h"
#include"skalka.h"
#include "menu.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Menu* theMenu = nullptr;
    ListaSkal* theListaSkal = nullptr;
    Skalka* theSkalka = nullptr;
    Mapa* theMapa = nullptr;
    Profil* theProfil = nullptr;
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Menu* mainWidget_{nullptr};
};
#endif // MAINWINDOW_H
