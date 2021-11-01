//
// Created by dima on 10/19/21.
//

#include "DBHandle.h"

bool DBHandle::init = false;
int DBHandle::rc = 0;
sqlite3 *DBHandle::dbHandle = nullptr;
char *DBHandle::errMsg = 0;

DBHandle::DBHandle()
{
}

bool DBHandle::Initialize()
{
    return DBFileCheck();
}

bool DBHandle::DBFileCheck()
{
    std::ifstream f(SQLITE_FILE);
    if(!f.good())
    {
        std::cout << "Unable to find SQLite DB. Attempting to create it..." << std::endl;
        return CreateDBFile();
    }

    return true;
}

bool DBHandle::CreateDBFile()
{
    std::string sql;

    rc = sqlite3_open(SQLITE_FILE, &dbHandle);
    if(rc)
    {
        std::cout << "Cannot initialize database file: " << sqlite3_errmsg(dbHandle) << std::endl;
        sqlite3_close(dbHandle);
        return false;
    }

    sql = "CREATE TABLE PASSWORDS( "
          "USER TEXT NOT NULL UNIQUE, "
          "PASS TEXT NOT NULL, "
          "DT_CREATED TEXT, "
          "DT_UPDATED TEXT, "
          "PRIMARY KEY(USER));";

    DBHandle::rc = sqlite3_exec(dbHandle, sql.c_str(), nullptr, nullptr, &errMsg);
    if(rc)
    {
        std::cout << "Cannot create table structure: " << sqlite3_errmsg(dbHandle) << std::endl;
        sqlite3_close(dbHandle);
        return false;
    }

    return true;
}