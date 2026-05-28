#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QVector>

class Skalka;

class dataManager {
public:
    static dataManager& instance();

    QVector<Skalka*> wszystkie_skalki;

    QString nick;
    QString opis;

    QVector<QString> skills;
    QVector<QString> equipment;

private:
    dataManager() = default;
};

#endif // DATAMANAGER_H
