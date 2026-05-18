#include "mainWindow.h"
#include "./ui_mainWindow.h"
#include"menu.h"
#include"skalka.h"
#include"listaskal.h"
#include"mapa.h"
#include "profil.h"

MainWindow::MainWindow(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    theMenu = new Menu(this); // BEZ słowa "Menu*" na początku!
    theListaSkal = nullptr;   // BEZ "ListaSkal*"
    theMapa = nullptr;        // BEZ "Mapa*"
    theProfil = nullptr;      // BEZ "Profil*"
    ui->setupUi(this);
    setCentralWidget(theMenu);

}




MainWindow::~MainWindow()
{
    delete ui;
}
