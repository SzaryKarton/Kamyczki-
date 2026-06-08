#ifndef GUZIKZAMIENIACZ_H
#define GUZIKZAMIENIACZ_H
#include <QWidget>
class GuzikZamieniacz
{
public:
    GuzikZamieniacz(QWidget* docelowy);
    QWidget* zwroc_widget();
private:
    QWidget* docelowy;
};

#endif // GUZIKZAMIENIACZ_H
