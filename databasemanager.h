#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager {
public:
    static DatabaseManager& instance();
    void createTables();
    void saveProfile();
    void loadProfile();
private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
