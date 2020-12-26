//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

char *rd_strjoin(const char *s1, const char *s2) {
    if (s1 == 0 && s2 == 0) {
        return 0;
    }
    if (s1 == 0) {
        return rd_strdup(s2);
    }
    if (s2 == 0) {
        return rd_strdup(s1);
    }

    int l1 = rd_strlen(s1);
    int l2 = rd_strlen(s2);
    char *result = rd_strnew(l1 + l2);
    if (result == 0) {
        return 0;
    }
    rd_strcpy(result, s1);
    rd_strcpy(result + l1, s2);
    return result;
}
