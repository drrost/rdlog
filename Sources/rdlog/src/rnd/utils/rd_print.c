//
//  rd_print.c
//  Created by Rostyslav Druzhchenko on 16.02.2022.
//

#include <rdlib.h>
#include <unistd.h>

void rd_print(const char *s) {
    int n = rd_strlen(s);
    write(STDOUT_FILENO, s, n);
}
