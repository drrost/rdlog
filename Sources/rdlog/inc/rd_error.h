//
//  rd_error.h
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#ifndef rd_error_h
#define rd_error_h

#include <stdlib.h>
#include <rdlib.h>
#include <rdlog.h>

typedef struct s_error {
    int code;
    char *domain;
    char *message;
} t_error;

t_error *rd_error_new(int code, const char *message, ...);
void rd_error_del(t_error **error);
void rd_error_print(t_error *error);

#endif /* rd_error_h */
