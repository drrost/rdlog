//
// Created by Rostyslav Druzhchenko on 12.11.2020.
//

#ifndef RDLOG_DB_H
#define RDLOG_DB_H

#include <sqlite3.h>
#include <rdlog.h>
#include <rd_model.h>

typedef struct s_db_connection {
    sqlite3 *db;

    int (*open)(struct s_db_connection *, const char *);
    void (*close)(struct s_db_connection *);
} t_db_connection;

typedef struct s_db_settings {
    const char *dir;
    const char *file;
    const char *sript_name;
} t_db_settings;

// Core

char *rd_get_db_path();
bool rd_db_exists();
void rd_db_create(t_db_settings *settings);

void rd_db_init();
t_db_connection *rd_db_connection_setget(t_db_connection *db_connection);

t_db_connection *rd_db_connection_new();
void rd_db_connection_del(t_db_connection **db_connection);

int rd_db_connection_open(t_db_connection *db_connection, const char *file);
void rd_db_connection_close(t_db_connection *db_connection);

// Messages

int rd_db_save_message(t_message *message);

#endif //RDLOG_DB_H
