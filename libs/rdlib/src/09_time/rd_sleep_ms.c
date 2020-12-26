//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlib.h>

void rd_sleep_ms(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}
