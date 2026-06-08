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
        "rodzaj_skaly TEXT"
        ");"
        );

    //
    //do tras
    //
    query.exec(
        "CREATE TABLE IF NOT EXISTS trasy ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "id_skalki INTEGER,"
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

void DatabaseManager::saveSkalka(const QVector<Skalka*>& listaSkalek){
    auto& data = dataManager::instance();
    QSqlQuery query;
    query.exec("DELETE FROM skalki");
    for (Skalka* skalka : listaSkalek){
    query.prepare("INSERT INTO skalki(wspolrzedne, nazwa, wysokosc, rodzaj_skaly) VALUES (?, ?, ?,?)");
    query.addBindValue(skalka->wspolrzedne);
    query.addBindValue(skalka->nazwa);
    query.addBindValue(skalka->wysokosc);
    query.addBindValue(skalka->rodzaj_skaly);

    if (!query.exec()) {
        qDebug() << "Błąd zapisu pojedynczej skałki:" << query.lastError().text();
    }
    QSqlDatabase::database().commit();
    qDebug() << "Zapisano pomyślnie wszystkie skałki do bazy!";
}
}

QVector<Skalka*> DatabaseManager::wczytajSkalki()
{
    QVector<Skalka*> listaSkalek;
    QSqlQuery query;

    // Pobieramy dane bezpośrednio z Twojej połączonej tabeli 'skalki'
    if (query.exec("SELECT wspolrzedne, nazwa, wysokosc, rodzaj_skaly FROM skalki")) {
        while (query.next()) {

            // Tworzymy nowy, czysty obiekt skałki w pamięci RAM
            Skalka* nowaSkalka = new Skalka();

            // Odbudowujemy atrybuty z kolejnych kolumn (od 0 do 3)
            nowaSkalka->wspolrzedne = query.value(0).toString();
            nowaSkalka->nazwa       = query.value(1).toString();
            nowaSkalka->wysokosc    = query.value(2).toInt();
            nowaSkalka->rodzaj_skaly = query.value(3).toString();

            // Wrzucamy gotową skałkę do wektora
            listaSkalek.append(nowaSkalka);
        }
        qDebug() << "Wczytano pomyślnie" << listaSkalek.size() << "skałek (bez tras).";
    } else {
        qDebug() << "Błąd podczas wczytywania samych skałek:" << query.lastError().text();
    }

    return listaSkalek; // Zwracamy gotową listę obiektów
}
