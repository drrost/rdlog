//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlog.h>

static int run_sql(sqlite3 *db, t_message *message) {
    char *sql = "INSERT INTO message (sender, text, type, level) "
                "VALUES ('%s', '%s', %d, %d);";
    int size = rd_strlen(sql);
    char *resolved = rd_strnew(size * 2);
    sprintf(resolved, sql,
            message->sender, message->message,
            message->type, message->log_level);
    char *error_message = 0;
    int rc = sqlite3_exec(db, resolved, 0, 0, &error_message);
    rd_strdel(&resolved);

    if (rc != SQLITE_OK) {
        rd_log_e(rd_get_app_name(), "Can't run SQL \"%s\"", sql);
        sqlite3_free(error_message);
    }
    else
        rd_log_d(rd_get_app_name(), "Saved message to data base \"%s\"", message->message);

    return rc;
}

int rd_db_save_message(t_message *message) {
    if (message == 0) {
        rd_log_e(rd_get_app_name(), "Can't store a message, message is NULL");
        return 1;
    }

    t_db_connection *db_connection =
        rd_db_connection_setget((t_db_connection *)-1);

    int rc = run_sql(db_connection->db, message);
    if (rc != 0) {
        rd_log_e(rd_get_app_name(), "Error while saving a message to"
                                    " the database, error code: %d", rc);
    }

    return rc;
}
