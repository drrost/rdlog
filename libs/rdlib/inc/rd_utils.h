//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef RDLOG_RD_UTILS_H
#define RDLOG_RD_UTILS_H

char *rd_itoa(int number);
void rd_printerr(const char *s);

void rd_check_leaks(void);
void rd_reset_leacks(void);

#endif //RDLOG_RD_UTILS_H
