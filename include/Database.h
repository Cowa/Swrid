#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <iostream>

using namespace std;

class Database
{
    public:
        Database();
        virtual ~Database();

        sqlite3* getDb();
    private:
        sqlite3 *db_;
};

#endif // DATABASE_H
