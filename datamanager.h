/* przechowuje wpisane przez użytkownika informacje, dodane skałki etc */
#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QStringList>
//#include "skalka.h"
class Skalka;
class dataManager
{
public:
    static dataManager& instance()
    {
        static dataManager instance;
        return instance;
    }
    QVector<QString> profil_dane_tekst;

    QVector<Skalka*> wszystkie_skalki;
    QString nick = "Twój Nick";
    QString opis = "";
    QVector<QString> skills;
    QVector<QString> equipment;




private:
    dataManager() = default; // Ukrywamy konstruktor, żeby nikt nie zrobił "new DataManager"
    dataManager(const dataManager&) = delete;
};

#endif // DATAMANAGER_H
