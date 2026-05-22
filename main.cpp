#include "mainWindow.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Menu *m = new Menu(&w);
    w.show();
    w.setCentralWidget(m);
    return a.exec();
}
