//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static char *error_message(char *path) {
    char *message = rd_strdup("Can't create data base at path \"");
    rd_str_append(&message, path);
    rd_str_append(&message, "\". Check if path exists and the "
                            "application has rights for writing.");
    return message;
}

static void move_db_file(char *path) {
    char *script = rd_strdup("cd ../resources && mv rdlog.sqlite ");
    rd_str_append(&script, path);
    system(script);
    rd_strdel(&script);
}

void rd_db_create(void) {
    char *path = rd_get_db_path();
    char *dir = rd_path_by_remove_last_component(path);

    rd_create_dir(dir);
    rd_strdel(&dir);
    system("cd ../resources && ./recreate_db.sh");
    move_db_file(path);

    if (!rd_db_exists()) {
        char *message = error_message(path);
        rd_log_e(rd_get_app_name(), message);
        rd_strdel(&message);
        exit(EXIT_FAILURE);
    }
}
