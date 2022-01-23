//
//  rd_dir_delete.c
//
//
//  Created by Rostyslav Druzhchenko on 23.01.2022.
//

#include <ftw.h>
#include <stdio.h>

int rd_dir_create(const char *path) {
    struct stat st = {0};

    int result = 0;
    if (stat(path, &st) == -1) {
        result = mkdir(path, 0777);
    }
    return result;
}
