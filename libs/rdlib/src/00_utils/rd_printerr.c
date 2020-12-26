//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>
#include <rd_log.h>

void rd_printerr(const char *s) {
    int n = rd_strlen(s);
    write(2, s, n);
    rd_log_e(rd_get_app_name(), s);
}
