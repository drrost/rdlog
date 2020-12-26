//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static char *db_path = 0;
static char *get_db_path() {
    if (db_path == 0)
        db_path = rd_strdup("/var/log/rdlog.sqlite");
    return db_path;
}

bool rd_db_exists() {
    char *full_path = get_db_path();
    return rd_file_exists(full_path) && !rd_is_directory(full_path);
}
