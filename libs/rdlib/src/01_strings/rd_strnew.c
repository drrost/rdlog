//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

char *rd_strnew(const int size) {
    if (size < 0)
        return 0;
    char *result = NULL;
    result = (char *)malloc(sizeof(char) * size + 1);
    if (result != 0) {
        for (int i = 0; i <= size; i++) {
            result[i] = 0;
        }
    }
    return result;
}
