//
//  rd_file_copy.c
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#include "rd_file.h"

int rd_file_copy(const char *src, const char *dst) {
    char *s = rd_strdup("cp ");
    rd_str_append(&s, src);
    rd_str_append(&s, " ");
    rd_str_append(&s, dst);

    int result = system(s);

    rd_strdel(&s);
    return result;
}
