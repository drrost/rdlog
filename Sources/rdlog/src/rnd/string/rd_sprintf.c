//
//  rd_sprintf.c
//
//
//  Created by Rostyslav Druzhchenko on 23.01.2022.
//

#include "rdlib.h"
#include "rdlog.h"

static int formats_count(const char *s) {
    int count = 0;
    while (*s) {
        if (*s == '%') {
            count++;
            s++;
        }
        s++;
    }
    return count;
}

static void format_data(
    const char *s, int count, char **f_symbols, t_rd_range **ranges) {

    char *in_symbols = rd_strnew(count);
    t_rd_range *in_ranges = malloc(sizeof(t_rd_range) * count);

    int i = 0;
    int j = 0;
    while (*s) {
        if (*s == '%') {
            in_symbols[i] = s[1];
            in_ranges[i].pos = j;
            in_ranges[i].len = 2; // TODO: Implement real calculation.
            i++;
            s++;
            j++;
        }
        s++;
        j++;
    }

    *f_symbols = in_symbols;
    *ranges = in_ranges;
}

static void apply_format(
    const char *f, char *result, char **arr, t_rd_range *ranges, int *lengths) {
    int f_len = rd_strlen(f);
    for (int i = 0, k = 0, n = 0; i < f_len;) {
        if (f[i] == '%') {
            rd_strcpy(result + k, arr[n]);
            i += ranges[n].len;
            k += lengths[n];
            n++;
        } else {
            result[k] = f[i];
            i++;
            k++;
        }
    }
}

// TODO: Move to the knoledgebase.
// http://www.cplusplus.com/reference/cstdarg/va_start/
//
char *rd_vsprintf(const char *f, va_list argp) {
    // Parse format.
    //
    int size = formats_count(f);
    char *symbols;
    t_rd_range *ranges;
    format_data(f, size, &symbols, &ranges);

    // Read arguments.
    //
    char **arr = malloc(sizeof(char *) * size);
    int *lengths = malloc(sizeof(int) * size);

    int final_len = rd_strlen(f);
    for (int i = 0; i < size; i++) {
        if (symbols[i] == 'd' || symbols[i] == 'i') {
            arr[i] = rd_itoa(va_arg(argp, int));
        }
        else if (symbols[i] == 's') {
            arr[i] = rd_strdup(va_arg(argp, char *));
        }
        else if (symbols[i] == 'c') {
            char *s = rd_strnew(1);
            s[0] = va_arg(argp, int);
            arr[i] = s;
        }
        lengths[i] = rd_strlen(arr[i]);
        final_len += lengths[i] - ranges[i].len;
    }

    // Applay format.
    //
    char *result = rd_strnew(final_len);
    apply_format(f, result, arr, ranges, lengths);

    // Clean up.
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
    free(lengths);
    free(ranges);
    rd_strdel(&symbols);

    return result;
}

char *rd_sprintf(const char *f, ...) {
    va_list argp;
    va_start(argp, f);
    char *result = rd_vsprintf(f, argp);
    va_end(argp);
    return result;
}
