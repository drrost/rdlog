//
//  rd_sprintf.c
//
//
//  Created by Rostyslav Druzhchenko on 23.01.2022.
//

#include "rdlib.h"
#include "rdlog.h"

char *rd_sprintf(const char *f, ...) {
    va_list argp;
    va_start(argp, f);
    char *result = rd_vsprintf(f, argp);
    va_end(argp);
    return result;
}
