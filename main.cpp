#include "mainWindow.h"
#include "menu.h"

#include "databasemanager.h"
#include "datamanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager::instance().loadProfile();
    MainWindow w;
    Menu *m = new Menu(&w);
    w.show();
    w.setCentralWidget(m);
    return a.exec();
}
