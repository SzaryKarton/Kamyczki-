#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
class Skalka;
class DatabaseManager {
public:
    static DatabaseManager& instance();
    void createTables();
    void saveProfile();
    void loadProfile();

    void saveSkalka(const QVector<Skalka*>& listaSkalek);
    QVector<Skalka*> wczytajSkalki();
private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
