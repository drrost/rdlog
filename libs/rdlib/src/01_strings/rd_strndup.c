//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlib.h>

char *rd_strndup(const char *str, size_t n) {
    int src_len = rd_strlen(str);
    if (n > (size_t)src_len) {
        n = src_len;
    }
    char *result = rd_strnew(n);
    if (result == 0) {
        return 0;
    }
    return rd_strncpy(result, str, n);
}
