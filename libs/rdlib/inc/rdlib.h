#ifndef RDLIB_LIBRARY_H
#define RDLIB_LIBRARY_H

#include <stdbool.h>
#include <libc.h>
#include <stdlib.h>
#include <sys/errno.h>

#include <rd_utils.h>
#include <rd_string.h>
#include <rd_path.h>
#include <rd_log.h>
#include <rd_random.h>
#include <rd_network.h>
#include <rd_time.h>
#include <rd_threads.h>
#include <rd_filesystem.h>

#define CREATE_INSTANCE(type) int size = sizeof(type); \
type *instance = (type *)malloc(size);                 \
memset(instance, 0, size);
#define DELETE_INSTANCE(instance) free(*instance); *instance = 0;

bool rd_is_prime(unsigned long a);

#endif // RDLIB_LIBRARY_H
