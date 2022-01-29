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

    CREATE_INSTANCE(t_error);
    instance->code = code;
    instance->message = formatted;
    instance->domain = 0;
    return instance;
}
