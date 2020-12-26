//
// Created by Rostyslav Druzhchenko on 16.11.2020.
//

#include <rd_db.h>

int rd_db_connection_open(t_db_connection *db_connection, const char *file) {
    return sqlite3_open(file, &(db_connection->db));
}
