//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

int rd_strcmp(const char *s1, const char *s2) {
    int diff;
    while (1) {
        diff = *s1 - *s2;
        if (diff != 0) {
            return diff;
        }
        s1++;
        s2++;
        if (*s1 == 0 && *s2 == 0) {
            return 0;
        }
    }
}
