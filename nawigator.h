#ifndef NAWIGATOR_H
#define NAWIGATOR_H
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

#endif // NAWIGATOR_H
