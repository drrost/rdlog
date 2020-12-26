//
// Created by Rostyslav Druzhchenko on 27.09.2020.
//

#include <rdlib.h>

void rd_log_t(const char *subject, const char *details) {
    rd_log(subject, details, LOG_TRACE);
}

void rd_log_di(const char *subject, int number) {
    char *s = rd_itoa(number);
    rd_log_d(subject, s);
    rd_strdel(&s);
}

void rd_log_d(const char *subject, const char *details, ...) {
    char *in_details = rd_strnew(DETAILES_SIZE);

    va_list argp;
    va_start(argp, details);
    vsprintf(in_details, details, argp);
    va_end(argp);

    rd_log(subject, in_details, LOG_DEBUG);
    rd_strdel(&in_details);

}

void rd_log_i(const char *subject, const char *details, ...) {
    char *in_details = rd_strnew(DETAILES_SIZE);

    va_list argp;
    va_start(argp, details);
    vsprintf(in_details, details, argp);
    va_end(argp);

    rd_log(subject, in_details, LOG_INFO);
    rd_strdel(&in_details);
}

void rd_log_e(const char *subject, const char *details, ...) {
    char *in_details = rd_strnew(DETAILES_SIZE);

    va_list argp;
    va_start(argp, details);
    vsprintf(in_details, details, argp);
    va_end(argp);

    rd_log(subject, in_details, LOG_ERROR);
    rd_strdel(&in_details);
}
