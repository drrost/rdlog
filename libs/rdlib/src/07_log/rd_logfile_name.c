//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

static char *app_name = 0;

void rd_set_app_name(char *name) {
    rd_strdel(&app_name);
    app_name = rd_strdup(name);
}

char *rd_get_app_name() {
    static bool is_first = true;
    LOCK(mutex, {
        if (is_first) {
            is_first = false;
            app_name = rd_strdup("UNKNOWN");
        }
    });
    return app_name;
}

#define MAX_PATH 2048

static char logfile_name[MAX_PATH];
static char logfile_name_error[MAX_PATH];

void rd_set_logfile_name(char *name, enum e_log_level level) {
    if (level == LOG_ERROR)
        rd_strcpy(logfile_name_error, name);
    else
        rd_strcpy(logfile_name, name);
}

char *rd_get_logfile_name(enum e_log_level level) {
    if (level == LOG_ERROR && rd_strlen(logfile_name_error))
        return logfile_name_error;

    static bool is_first = true;
    LOCK(mutex, {
        if (is_first == true) {
            rd_strcpy(logfile_name, "/tmp/rdlib.log");
            rd_strcpy(logfile_name_error, "");
            is_first = false;
        }
    });

    return logfile_name;
}
