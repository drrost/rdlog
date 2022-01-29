//
//  rd_str_has_suffix.c
//
//
//  Created by Rostyslav Druzhchenko on 15.01.2022.
//

#include <rdlib.h>

bool rd_str_has_suffix(const char *s, const char *suffix) {
    int length_s = rd_strlen(s);
    int length_suffix = rd_strlen(suffix);
    if (length_s < length_suffix) {
        return false;
    }

    for (int i = 0; i < length_suffix; i++) {
        if (s[length_s - i] != suffix[length_suffix - i]) {
            return false;
        }
    }

    return true;
}
