//
//  rd_error_print.c
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#include "rd_error.h"

void rd_error_print(t_error *error) {
    char *s = "ERROR code: ";
    char *code_s = rd_itoa(error->code);

    rd_str_append(&s, code_s);
    rd_str_append(&s, ", ");
    rd_str_append(&s, error->message);
    rd_str_append(&s, "\n");

    rd_printerr(s);

    rd_strdel(&code_s);
    rd_strdel(&s);
}
