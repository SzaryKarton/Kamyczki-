#ifndef NAWIGATOR_H
#define NAWIGATOR_H

#include <QWidget>
#include <QFrame>

class MainWindow;
class Trasa;
class Nawigator
{
public:

    void openWidget(
        MainWindow *okno,
        QWidget *nowyWidget
        );
    void openInFrameTrasa(
        QFrame *targetFrame,
        Trasa *widgetPointer
        );
};

#endif
//#ifndef NAWIGATOR_H //nawigator trzeba dodawać do cpp bo program dostanie pierdolca
//nawigator zajmuje się:
//zmienianiem okna
//autozapisem do dokumentu (docelowo)
/*#define NAWIGATOR_H
#include <qwidget.h>
#include "mainWindow.h"
class Nawigator
{
public:
    Nawigator();
    template <typename T>
    void openWidget(MainWindow *glowneOkno, T *&otworz_ten)
    {
        glowneOkno->takeCentralWidget();
        if(otworz_ten == nullptr)
        {
            T* otworz_ten = new T;
            glowneOkno->setCentralWidget(otworz_ten);
        }
        else
        {
            glowneOkno->setCentralWidget(otworz_ten);
        };
    };
};

#endif // NAWIGATOR_H*/
