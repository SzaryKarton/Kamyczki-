#include "databasemanager.h"
#include "datamanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager baza;

    return baza;
}

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("profil.db");

    if (db.open()) {
        qDebug() << "Open :)";
        createTables();

    } else {
        qDebug() << "Not open :(";
    }
}

void DatabaseManager::createTables() {
    QSqlQuery query;

    query.exec(
        "CREATE TABLE IF NOT EXISTS profile ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nickname TEXT,"
        "bio TEXT"
        ");"
    );

    query.exec(
        "CREATE TABLE IF NOT EXISTS skills ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "skill TEXT"
        ");"
    );

    query.exec(
        "CREATE TABLE IF NOT EXISTS equipment ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "equipment TEXT"
        ");"
    );
}
void DatabaseManager::saveProfile()
{
    auto& data = dataManager::instance();

    QSqlQuery query;

    query.exec(
        "DELETE FROM profile"
        );

    query.exec(
        "DELETE FROM skills"
        );

    query.exec(
        "DELETE FROM equipment"
        );

    query.prepare(
        "INSERT INTO profile "
        "(nickname, bio)"
        "VALUES (?, ?)"
        );

    query.addBindValue(
        data.nick
        );

    query.addBindValue(
        data.opis
        );

    if(!query.exec())
    {
        qDebug()
        << "Save error";
    }
    else
    {
        qDebug()
        << "Saved";
    }
    for(const QString& skill : data.skills)
    {
        query.prepare(
            "INSERT INTO skills "
            "(skill) "
            "VALUES (?)"
            );

        query.addBindValue(skill);

        if(!query.exec())
        {
            qDebug()
            << "Skill save error";
        }
    }
    for(const QString& eq : data.equipment)
    {
        query.prepare(
            "INSERT INTO equipment "
            "(equipment) "
            "VALUES (?)"
            );

        query.addBindValue(eq);

        if(!query.exec())
        {
            qDebug()
            << "Equipment save error";
        }
    }
}

void DatabaseManager::loadProfile()
{
    auto& data = dataManager::instance();

    QSqlQuery query;

    query.prepare(
        "SELECT nickname, bio "
        "FROM profile "
        "LIMIT 1"
        );

    if(query.exec())
    {
        if(query.next())
        {
            data.nick =
                query.value(0)
                    .toString();

            data.opis =
                query.value(1)
                    .toString();

            qDebug()
                << "Loaded";
        }
    }
    data.skills.clear();

    query.exec(
        "SELECT skill FROM skills"
        );

    while(query.next())
    {
        data.skills.append(
            query.value(0)
                .toString()
            );
    }

    data.equipment.clear();

    query.exec(
        "SELECT equipment FROM equipment"
        );

    while(query.next())
    {
        data.equipment.append(
            query.value(0)
                .toString()
            );
    }
}
