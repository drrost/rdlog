//
//  rd_error_print.c
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#include "rd_error.h"

void rd_error_print(t_error *error) {
    char *s = rd_sprintf("ERROR code: \"%d\", message: \"%s\"\n",
        error->code, error->message);
    rd_printerr(s);
    rd_strdel(&s);
}
