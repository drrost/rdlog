//
// Created by Rostyslav Druzhchenko on 16.11.2020.
//

#include <rd_db.h>

t_db_connection *rd_db_connection_new() {
    CREATE_INSTANCE(t_db_connection);
    instance->open = rd_db_connection_open;
    instance->close = rd_db_connection_close;
    return instance;
}
