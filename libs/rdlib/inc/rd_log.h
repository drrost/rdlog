//
// Created by Rostyslav Druzhchenko on 12.10.2020.
//

#ifndef INC_04_USH_RD_LOG_H
#define INC_04_USH_RD_LOG_H

#include <rdlib.h>

enum e_log_level {
    LOG_ALL,
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
    LOG_OFF
};

#define DETAILES_SIZE 1024

void rd_log(const char *subject, const char *details, int level);
void rd_log_t(const char *subject, const char *details);
void rd_log_di(const char *subject, int number);
void rd_log_d(const char *subject, const char *details, ...);
void rd_log_i(const char *subject, const char *details, ...);
void rd_log_e(const char *subject, const char *details, ...);

void rd_set_app_name(char *name);
char *rd_get_app_name();
void rd_set_logfile_name(char *name, enum e_log_level level);
char *rd_get_logfile_name(enum e_log_level level);

#endif //INC_04_USH_RD_LOG_H
