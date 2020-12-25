//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef TESTTHREADS_RDLOG_H
#define TESTTHREADS_RDLOG_H

#include <rdlib.h>

typedef struct {
    struct sockaddr_in address;
    int fd;
} t_socket_connection;

void rd_validate(int argc, char *argv[]);

t_socket_connection rd_open_socket_to_listen(int port);
void rd_accept_from_socket(t_socket_connection connection);

#endif //TESTTHREADS_RDLOG_H
