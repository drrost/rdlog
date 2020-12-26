//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlib.h>

bool rd_file_exists(char *path) {
    struct stat s;
    int ret = lstat(path, &s);
    return ret == 0;
}

// Alternative implementation
//    struct stat s;
//    int err = stat(p, &s);
//    if (-1 == err)
//        return ENOENT != errno;
//    return true;
