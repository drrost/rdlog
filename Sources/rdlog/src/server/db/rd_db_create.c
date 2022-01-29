//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static const char *TEMP_DIR = "/tmp/rdlog";

int rd_file_copy(const char *src, const char *dst) {
    char *s = rd_strdup("cp ");
    rd_str_append(&s, src);
    rd_str_append(&s, " ");
    rd_str_append(&s, dst);

    int result = system(s);

    rd_strdel(&s);
    return result;
}

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

int create_db_dir(t_db_settings *settings) {
    return rd_dir_create(settings->dir);
}

t_error *create_db_file(t_db_settings *settings) {
    // Create a temp dir
    int result = rd_dir_create(TEMP_DIR);
    if (result) {
        char *message = rd_sprintf(
            "Can't create \"%s\" directory to run init SQL script", TEMP_DIR);
        t_error *error = rd_error_new(result, message);
        rd_strdel(&message);
        return error;
    }

    // Get script path
    char *path = path_for_res(settings->sript_name);
    if (!path) {
        return rd_error_new(-1, "Resource \"%s\" not found", settings->sript_name);
    }
    rd_file_copy(path, TEMP_DIR);

    // Run the script
    //
    char *command = rd_sprintf(
        "cd %s && sqlite3 rdlog.sqlite < %s", TEMP_DIR, settings->sript_name);
    result = system(command);
    if (result) {
        char *message = rd_sprintf(
            "Error during SQL script execution, \"%s\"", settings->sript_name);
        t_error *error = rd_error_new(result, message);
        rd_strdel(&message);
        return error;
    }

    rd_strdel(&command);

    return 0;
}

static int move_db_file_to_db_dir(const char *file_path, const char *dst_dir_path) {
    file_path++;
    dst_dir_path++;
    return 0;
}

static void tear_down() {
    // Delete temp artifacts produced by the script.
}

static void print_err_and_terminate(const char *message) {
    message++;
}

void rd_db_create(void) {
    // Create the directory for server's DB.
    //
    char *db_path = rd_get_db_path();
    char *dir = rd_path_by_remove_last_component(db_path);
    rd_create_dir(dir);
    rd_strdel(&dir);

    // Create DB using a script.
    //
//    char *script_path = path_for_res("recreate_db.sh");

    // Move the DB file, created on the previous step to the DB folder.
    //
    dir = rd_path_by_remove_last_component(db_path);
    system("pwd");
    system("cd");
    system("pwd");
    system("pwd && cd ../resources && ./recreate_db.sh");
    move_db_file(db_path);
    rd_strdel(&dir);

    move_db_file_to_db_dir(0, 0);
    tear_down();
    print_err_and_terminate(0);

    if (!rd_db_exists()) {
        char *message = error_message(db_path);
        rd_log_e(rd_get_app_name(), message);
        rd_strdel(&message);
        exit(EXIT_FAILURE);
    }
}
