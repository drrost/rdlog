//
// Created by Rostyslav Druzhchenko on 27.09.2020.
//

#include <rdlib.h>

void rd_str_append(char **s, const char *to_add) {
    char *result = rd_strjoin(*s, to_add);
    rd_strdel(s);
    *s = result;
}
