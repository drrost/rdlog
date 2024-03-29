//
// Created by Rostyslav Druzhchenko on 16.11.2020.
//

#include <rd_db.h>

static const char *SETTINGS_DIR = "/usr/local/var/log";
static const char *SETTINGS_FILE = "rdlog.sqlite";
static const char *SETTINGS_SCRIPT = "message.sql";

static t_db_settings *get_settings() {
    static t_db_settings *settings = 0;
    if (!settings) {
        CREATE_INSTANCE(t_db_settings);
        instance->dir = SETTINGS_DIR;
        instance->file = SETTINGS_FILE;
        instance->sript_name = SETTINGS_SCRIPT;
        settings = instance;
    }
    return settings;
}

static t_db_connection *open_db_connection(char *db_path) {
    t_db_connection *db_connection = rd_db_connection_new();
    int rc = db_connection->open(db_connection, db_path);

    if (rc) {
        rd_db_connection_del(&db_connection);
        rd_log_e("SRV", "Can't open data base");
    }

    return db_connection;
}

static void print_db_open(const char *path) {
    char *s = rd_sprintf("Open DB at path: \"%s\"\n", path);
    rd_print(s);
    rd_strdel(&s);
}

void rd_db_init() {
    if (!rd_db_exists()) {
        rd_db_create(get_settings());
    }

    char *db_path = rd_get_db_path();
    t_db_connection *db_connection = open_db_connection(db_path);
    rd_db_connection_setget(db_connection);
    rd_log_i(rd_get_app_name(), "Open connection to the data base successfully");
    print_db_open(db_path);
    rd_strdel(&db_path);
}
