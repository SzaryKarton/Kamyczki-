#ifndef NAWIGATOR_H
#define NAWIGATOR_H

#include <QWidget>

class MainWindow;

class Nawigator
{
public:

    void openWidget(
        MainWindow *okno,
        QWidget *nowyWidget
        );
};

#endif
