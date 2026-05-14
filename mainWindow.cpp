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
    QWidget* secondWidget = nullptr;
    Menu* widgetMenu = new Menu(this);
    ListaSkal* listaSkal = new ListaSkal(nullptr);
    Skalka* theSkalka = new Skalka(nullptr);
    Mapa* theMapa = new Mapa(nullptr);
    Profil* theProfil = new Profil(nullptr);
    ui->setupUi(this);
    connect(widgetMenu, &Menu::requestOpenMapa, this, [this, theMapa]() {
        this->openNewWidget(theMapa);
    });

    connect(widgetMenu, &Menu::requestOpenSecondWidget, this, [this, listaSkal]() {
        this->openNewWidget(listaSkal);
    });

    connect(listaSkal, &ListaSkal::requestOpenSkala, this, [this, theSkalka]() {
        this->openNewWidget(theSkalka);
    });
    this->setCentralWidget(widgetMenu);

    connect(widgetMenu, &Menu::requestOpenProfil, this, [this, theProfil]() {
        this->openNewWidget(theProfil);
    });
    this->setCentralWidget(widgetMenu);

}
void MainWindow::openNewWidget(QWidget* otworz_ten) {
    QWidget* secondWidget  = otworz_ten;
    this->setCentralWidget(secondWidget);
}




MainWindow::~MainWindow()
{
    delete ui;
}
