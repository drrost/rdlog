//
// Created by Rostyslav Druzhchenko on 16.11.2020.
//

#include <rd_db.h>

void rd_db_connection_del(t_db_connection **db_connection) {
    free(*db_connection);
}
