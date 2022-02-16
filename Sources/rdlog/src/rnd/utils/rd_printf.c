//
//  rd_printf.c
//
//
//  Created by Rostyslav Druzhchenko on 17.02.2022.
//

#include "rdlib.h"
#include "rd_todo.h"

void rd_printf(const char *f, ...) {
    va_list argp;
    va_start(argp, f);
    char *result = rd_vsprintf(f, argp);
    va_end(argp);
    rd_print(result);
    rd_strdel(&result);
}
