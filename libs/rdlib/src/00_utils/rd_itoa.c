//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

static void put_char(const char ch, char *string) {
    int l = rd_strlen(string);
    string[l] = ch;
}

static void do_print(long int n, char *string) {
    if (n > 9)
        do_print(n / 10, string);
    put_char('0' + n % 10, string);
}

char *rd_itoa(int number) {
    char *result = rd_strnew(10);
    long int value = number;

    if (value < 0) {
        put_char('-', result);
        value = -value;
    }
    do_print(value, result);

    return result;
}
