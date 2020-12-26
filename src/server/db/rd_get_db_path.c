//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlog.h>

static char *db_path = 0;
char *rd_get_db_path() {
    if (db_path == 0)
        db_path = rd_strdup("/usr/local/var/log/rdlog.sqlite");
    return db_path;
}
