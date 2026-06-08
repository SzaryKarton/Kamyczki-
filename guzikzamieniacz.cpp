#include "guzikzamieniacz.h"


GuzikZamieniacz::GuzikZamieniacz(QWidget* w) {
    docelowy = w;
}

QWidget* GuzikZamieniacz :: zwroc_widget(){
    return  docelowy;
}
