//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef RDLOG_RDLOG_H
#define RDLOG_RDLOG_H

#include <pthread.h>
#include <rdlib.h>
#include <rd_db.h>
#include <rd_model.h>
#include <resources.h>
#include <rnd.h>

typedef struct {
    struct sockaddr_in address;
    int fd;
} t_socket_connection;

void rd_validate(int argc, char *argv[]);
void rd_run(char *port_str);

t_socket_connection rd_open_socket_to_listen(int port);
void rd_accept_from_socket(t_socket_connection connection);

void rd_handle_accepted_socket(int *socket);

#endif //RDLOG_RDLOG_H
