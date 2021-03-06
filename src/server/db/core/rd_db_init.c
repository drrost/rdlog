//
// Created by Rostyslav Druzhchenko on 16.11.2020.
//

#include <rd_db.h>

static t_db_connection *open_db_connection(char *db_path) {
    t_db_connection *db_connection = rd_db_connection_new();
    int rc = db_connection->open(db_connection, db_path);

    if (rc) {
        rd_db_connection_del(&db_connection);
        rd_log_e("SRV", "Can't open data base");
    }

    return db_connection;
}

void rd_db_init() {
    if (!rd_db_exists())
        rd_db_create();

    char *db_path = rd_get_db_path();
    t_db_connection *db_connection = open_db_connection(db_path);
    rd_db_connection_setget(db_connection);
    rd_log_i(rd_get_app_name(), "Open connection to the data base successfully");

}
