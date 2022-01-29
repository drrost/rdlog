//
//  rd_error.c
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#include "rd_error.h"

t_error *rd_error_new(int code, const char *message, ...) {

    va_list argp;
    va_start(argp, message);
    char *formatted = rd_vsprintf(message, argp);
    va_end(argp);

    t_error *error = malloc(sizeof(t_error));
    error->code = code;
    error->message = formatted;
    error->domain = 0;
    return error;
}
