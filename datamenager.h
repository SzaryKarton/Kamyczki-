#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <QString>
#include <QStringList>
#include "skalkauniversal.h"
class dataManager
{
public:
    static dataManager& instance()
    {
        static dataManager instance;
        return instance;
    }
    QVector<QString> profil_dane_tekst;

    QVector<SkalkaUniversal*> wszystkie_skalki;
    QString nick = "Twój Nick";
    QString opis = "";




private:
    dataManager() = default; // Ukrywamy konstruktor, żeby nikt nie zrobił "new DataManager"
    dataManager(const dataManager&) = delete;
};

#endif // DATAMENAGER_H
