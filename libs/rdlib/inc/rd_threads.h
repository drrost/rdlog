//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef RDLOG_RD_THREADS_H
#define RDLOG_RD_THREADS_H

#include <pthread.h>

#define LOCK(mtx, code) pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;\
pthread_mutex_lock(&mutex);\
code \
pthread_mutex_unlock(&mutex);

#endif //RDLOG_RD_THREADS_H
