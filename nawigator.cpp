#include "nawigator.h"

#include "mainWindow.h"

void Nawigator::openWidget(
    MainWindow *okno,
    QWidget *nowyWidget
    )
{
    okno->setCentralWidget(nowyWidget);
}
Nawigator::Nawigator() {}
