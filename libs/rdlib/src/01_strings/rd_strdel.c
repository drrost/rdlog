//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rd_string.h>

void rd_strdel(char **str) {
    if (*str == 0)
        return;

    free(*str);
    *str = 0;
}
