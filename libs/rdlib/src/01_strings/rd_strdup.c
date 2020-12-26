//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rd_string.h>

char *rd_strdup(const char *str) {
    if (str == 0)
        return 0;

    int n = rd_strlen(str);
    char *result = rd_strnew(n);
    if (result == 0)
        return 0;
    return rd_strcpy(result, str);
}
