//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

void rd_validate(int argc, char *argv[]) {
    if (argc != 2) {
        rd_printerr("usage: rdlog [port]\n");
        exit(EXIT_FAILURE);
    }

    const char *errstr = 0;
    if (__builtin_available(macOS 11.0, *)) {
        strtonum(argv[1], 0, INT_MAX, &errstr);
    } else {
        // Fallback on earlier versions
    }
    if (errstr) {
        rd_printerr("[port] argument is not valid");
        exit(EXIT_FAILURE);
    }
}
