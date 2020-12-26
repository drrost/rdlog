//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlib.h>

void rd_create_dir(char *dir) {
    char *script = rd_strdup("mkdir -pv ");
    rd_str_append(&script, dir);
    system(script);
    rd_strdel(&script);
}
