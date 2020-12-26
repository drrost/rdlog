//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

char *rd_strcpy(char *dst, const char *src) {
    char *result = dst;
    while (1) {
        *dst = *src;
        if (*src == 0)
            break;
        src++;
        dst++;
    }
    return result;
}
