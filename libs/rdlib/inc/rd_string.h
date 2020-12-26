//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef RDLOG_RD_STRING_H
#define RDLOG_RD_STRING_H

#include <stdlib.h>

int rd_strlen(const char *s);
char *rd_strnew(const int size);
void rd_strdel(char **str);
int rd_strcmp(const char *s1, const char *s2);
char *rd_strcpy(char *dst, const char *src);
char *rd_strdup(const char *str);
void rd_str_append(char **s, const char *to_add);
char *rd_strjoin(const char *s1, const char *s2);

int rd_strncmp(const char *s1, const char *s2, size_t n);
char *rd_strncpy(char *dst, const char *src, int len);
char *rd_strndup(const char *str, size_t n);

#endif //RDLOG_RD_STRING_H
