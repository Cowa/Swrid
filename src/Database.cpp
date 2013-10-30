#include "../include/Database.h"

Database::Database()
{
    // On se connecte à la base de données
    if(sqlite3_open("data.db", &db_))
    {
        cout << "Database error" << endl;
    }

    string sql = "CREATE TABLE IF NOT EXISTS Player("
          "ID INT PRIMARY KEY     NOT NULL,"
          "NAME           TEXT    NOT NULL,"
          "MONEY          INT     NOT NULL);";
    // TODO HIGHSCORE

    if(sqlite3_exec(db_, sql.c_str(), NULL, 0, NULL) != SQLITE_OK)
        cout << "Error in the Player table creation" << endl;
    else
        cout << "Player table created !" << endl;
}

Database::~Database()
{
    // On termine la connexion
    sqlite3_close(db_);
}

sqlite3* Database::getDb()
{
    return db_;
}
