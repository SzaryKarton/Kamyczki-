#include "databasemanager.h"
#include "datamanager.h"
#include "skalka.h"
#include <QSqlError>
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
    db.setDatabaseName("data.db");

    if (db.open()) {
        qDebug() << "Open :)";
        createTables();

    } else {
        qDebug() << "Not open :(";
    }
}

void DatabaseManager::createTables() {
    QSqlQuery query;
    //
    //do profilu
    //
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

    //
    //do skalek
    //
    query.exec(
        "CREATE TABLE IF NOT EXISTS skalki ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "wspolrzedne TEXT,"
        "nazwa TEXT,"
        "wysokosc INTEGER,"
        "rodzaj_skaly TEXT,"
        "sciezka_zdjecia TEXT"
        ");"
        );

    //
    //do tras
    //
    query.exec(
        "CREATE TABLE IF NOT EXISTS trasy ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "skalka_nazwa TEXT,"
        "nazwa TEXT,"
        "trudnosc TEXT,"
        "asekuracja TEXT,"
        "wpinki TEXT"
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

void DatabaseManager::saveSkalka(const QVector<Skalka*>& listaSkalek) {
    QSqlQuery query;

    query.exec("DELETE FROM skalki");
    query.exec("DELETE FROM trasy");

    for (Skalka* skalka : listaSkalek) {
        if (!skalka) continue;

        query.prepare(
            "INSERT INTO skalki (nazwa, wspolrzedne, wysokosc, rodzaj_skaly, sciezka_zdjecia) VALUES (?, ?, ?, ?, ?)"
            );
        query.addBindValue(skalka->nazwa);
        query.addBindValue(skalka->wspolrzedne);
        query.addBindValue(skalka->wysokosc);
        query.addBindValue(skalka->rodzaj_skaly);
        query.addBindValue(skalka->sciezka_zdjecia);

        if (!query.exec()) {
            qDebug() << "Błąd zapisu skałki:" << query.lastError().text();
            continue;
        }

        // Zapis tras
        for (Trasa* trasa : skalka->trasy) {
            if (!trasa) continue;

            query.prepare(
                "INSERT INTO trasy (skalka_nazwa, nazwa, trudnosc, asekuracja, wpinki) VALUES (?, ?, ?, ?, ?)"
                );
            query.addBindValue(skalka->nazwa);
            query.addBindValue(trasa->nazwa);
            query.addBindValue(trasa->trudnosc);
            query.addBindValue(trasa->asekuracja);
            query.addBindValue(trasa->wpinki);

            if (!query.exec()) {
                qDebug() << "Błąd zapisu trasy:" << query.lastError().text();
            }
        }
    }

    qDebug() << "Zapisano skałki i trasy.";
    query.clear();
}


QVector<Skalka*> DatabaseManager::wczytajSkalki() {
    QVector<Skalka*> listaSkalek;
    QSqlQuery query;

    if (query.exec("SELECT nazwa, wspolrzedne, wysokosc, rodzaj_skaly, sciezka_zdjecia FROM skalki")) {
        while (query.next()) {
            Skalka* nowaSkalka = new Skalka();

            nowaSkalka->nazwa        = query.value(0).toString();
            nowaSkalka->wspolrzedne  = query.value(1).toString();
            nowaSkalka->wysokosc     = query.value(2).toInt();
            nowaSkalka->rodzaj_skaly = query.value(3).toString();
            nowaSkalka->sciezka_zdjecia = query.value(4).toString();

            // Wczytywanie tras
            QSqlQuery trasaQuery;
            trasaQuery.prepare(
                "SELECT nazwa, trudnosc, asekuracja, wpinki "
                "FROM trasy WHERE skalka_nazwa = ?"
                );
            trasaQuery.addBindValue(nowaSkalka->nazwa);

            if (trasaQuery.exec()) {
                while (trasaQuery.next()) {
                    Trasa* nowaTrasa = new Trasa();

                    nowaTrasa->nazwa      = trasaQuery.value(0).toString();
                    nowaTrasa->trudnosc   = trasaQuery.value(1).toString();
                    nowaTrasa->asekuracja = trasaQuery.value(2).toString();
                    nowaTrasa->wpinki     = trasaQuery.value(3).toString();

                    nowaSkalka->trasy.append(nowaTrasa);
                }
            }

            listaSkalek.append(nowaSkalka);
        }
    }

    return listaSkalek;
}

