//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#ifndef TESTTHREADS_RDLOG_H
#define TESTTHREADS_RDLOG_H

#include <pthread.h>
#include <rdlib.h>

typedef struct {
    struct sockaddr_in address;
    int fd;
} t_socket_connection;

void rd_validate(int argc, char *argv[]);
void rd_run(char *port_str);

t_socket_connection rd_open_socket_to_listen(int port);
void rd_accept_from_socket(t_socket_connection connection);

void rd_handle_accepted_socket(int *socket);

// Database
//
char *rd_get_db_path();
bool rd_db_exists();
void rd_db_create(void);

// Messages
//

typedef enum message_type {
    E_MESSAGE_TYPE_NONE = 0,
    E_MESSAGE_TYPE_MESSAGE,
    E_MESSAGE_TYPE_SERVICE
} e_message_type;

typedef struct {
    char *sender;
    char *message;
    int log_level;
    e_message_type type;
    int version;
} t_message;

t_message *rd_message_new();
void rd_message_delete(t_message **message);

#endif //TESTTHREADS_RDLOG_H
