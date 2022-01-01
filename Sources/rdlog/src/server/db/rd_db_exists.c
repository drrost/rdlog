//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

bool rd_db_exists() {
    char *full_path = rd_get_db_path();
    return rd_file_exists(full_path) && !rd_is_directory(full_path);
}
