//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlib.h>

bool rd_is_directory(char *path) {
    struct stat s;
    lstat(path, &s);
    return S_ISDIR(s.st_mode);

    // An altrenative way:
//    DIR *d;
//    d = opendir(file_name.c_str());
//    bool result = d != 0;
//    if (d)
//        closedir(d);
//    return result;
}
