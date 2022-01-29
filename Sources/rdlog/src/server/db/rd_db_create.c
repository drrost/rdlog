//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static const char *TEMP_DIR = "/tmp/rdlog";

t_error *create_db_dir(t_db_settings *settings) {
    int code = rd_dir_create(settings->dir);
    if (code) {
        return rd_error_new(
            code, "Can't create directory at path: \"%s\"", settings->dir);
    }
    return 0;
}

t_error *create_db_file(t_db_settings *settings) {
    // Create a temp dir
    int result = rd_dir_create(TEMP_DIR);
    if (result) {
        return rd_error_new(result,
            "Can't create \"%s\" directory to run init SQL script", TEMP_DIR);
    }

    // Get script path
    char *path = path_for_res(settings->sript_name);
    if (!path) {
        return rd_error_new(-1, "Resource \"%s\" not found", settings->sript_name);
    }
    rd_file_copy(path, TEMP_DIR);

    // Run the script
    char *command = rd_sprintf(
        "cd %s && sqlite3 %s < %s", TEMP_DIR, settings->file, settings->sript_name);
    result = system(command);
    if (result) {
        return rd_error_new(result,
            "Error during SQL script execution, \"%s\"", settings->sript_name);
    }
    rd_strdel(&command);
    return 0;
}

static t_error *move_db_file_to_db_dir(t_db_settings *settings) {
    char *from = rd_sprintf("%s/%s", TEMP_DIR, settings->file);
    const char *to = settings->dir;
    int result = rd_file_copy(from, to);
    if (result) {
        return rd_error_new(result, "Can't copy file: \"%s\" to: \"%s\"", from, to);
    }
    return 0;
}

static void tear_down() {
    rd_dir_delete(TEMP_DIR);
}

static void perform_if_err_and_terminate(t_error *error) {
    if (error) {
        rd_error_print(error);
        rd_error_del(&error);
        exit(EXIT_FAILURE);
    }
}

void rd_db_create(t_db_settings *settings) {
    t_error *error = create_db_dir(settings);
    if (!error) {
        error = create_db_file(settings);
    }

    if (!error) {
        error = move_db_file_to_db_dir(settings);
    }

    perform_if_err_and_terminate(error);
    tear_down();
}
