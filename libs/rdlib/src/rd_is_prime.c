//
// Created by Rostyslav Druzhchenko on 22.12.2020.
//

#include <rdlib.h>

bool rd_is_prime(unsigned long a) {
    for (unsigned long i = 2; i < a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}
