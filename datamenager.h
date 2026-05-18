#ifndef DATAMENAGER_H
#define DATAMENAGER_H
#include <QString>
#include <QStringList>
class dataManager
{
public:
    static dataManager& instance()
    {
        static dataManager instance;
        return instance;
    }
    QString nick = "Twój Nick";
    QString opis = "";

private:
    dataManager() = default; // Ukrywamy konstruktor, żeby nikt nie zrobił "new DataManager"
    dataManager(const dataManager&) = delete;
};

#endif // DATAMENAGER_H
