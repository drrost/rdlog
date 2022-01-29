//
//  rd_error_del.c
//
//
//  Created by Rostyslav Druzhchenko on 29.01.2022.
//

#include "rd_error.h"

void rd_error_del(t_error **error) {
    rd_strdel(&((*error)->message));
    rd_strdel(&((*error)->domain));
    free(*error);
    *error = 0;
}
