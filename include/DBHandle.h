//
// Created by dima on 10/19/21.
//

#ifndef PMP_SERVER_CLI_DBHANDLE_H
#define PMP_SERVER_CLI_DBHANDLE_H

#define SQLITE_FILE "pass.db"

#include <iostream>
#include <fstream>
#include <sqlite3.h>

class DBHandle
{
private:
    static bool init;
    static int rc;
    static sqlite3 *dbHandle;
    static char *errMsg;
    static bool DBFileCheck();
    static bool CreateDBFile();

public:
    DBHandle();
    static bool Initialize();
};

#endif //PMP_SERVER_CLI_DBHANDLE_H
