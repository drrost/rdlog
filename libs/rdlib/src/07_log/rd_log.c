//
// Created by Rostyslav Druzhchenko on 27.09.2020.
//

#include <rd_log.h>

static void print_debug(const char *line, enum e_log_level level) {
    char *file_name = rd_get_logfile_name(level);
    FILE *file = fopen(file_name, "a+");
    fprintf(file, "%s\n", line);
    fclose(file);
}

char *current_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    static char time_str[128];
    sprintf(time_str, "%04d-%02d-%02dT%02d:%02d:%02d",
            time_info->tm_year + 1900, time_info->tm_mon + 1,
            time_info->tm_mday, time_info->tm_hour,
            time_info->tm_min, time_info->tm_sec);

    return rd_strdup(time_str);
}

static void append_level(char **where, int level) {
    switch (level) {
        case LOG_TRACE:
            rd_str_append(where, " TRACE ");
            break;
        case LOG_DEBUG:
            rd_str_append(where, " DEBUG ");
            break;
        case LOG_INFO:
            rd_str_append(where, " INFO ");
            break;
        case LOG_ERROR:
            rd_str_append(where, " ERROR ");
            break;
        default:
            rd_str_append(where, " UNKNOWN ");
    }
}

void rd_log(const char *subject, const char *details, int level) {
    char *to_print = current_time();
    char *in_details = 0;
    if (details == 0)
        in_details = rd_strdup("<NULL>");
    else
        in_details = rd_strdup(details);

    append_level(&to_print, level);
    rd_str_append(&to_print, subject);

    if (rd_strlen(in_details)) {
        rd_str_append(&to_print, " - ");
        rd_str_append(&to_print, in_details);
    }

    print_debug(to_print, level);
    rd_strdel(&to_print);
    rd_strdel(&in_details);
}
