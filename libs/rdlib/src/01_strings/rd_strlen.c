//
// Created by Rostyslav Druzhchenko on 24.12.2020.
//

int rd_strlen(const char *s) {
    int result = 0;
    while (*s++) {
        result++;
    }
    return result;
}
