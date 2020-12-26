//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rdlib.h>

char *rd_path_by_remove_last_component(char *path) {
    if (path == 0)
        return 0;

    int idx = -1;
    int len = rd_strlen(path);
    for (int i = len - 1; i >= 0; i--) {
        if (path[i] == '/') {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return 0;
    return rd_strndup(path, idx);
}
