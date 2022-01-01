//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

void rd_accept_from_socket(t_socket_connection connection) {
    int socket = 0;
    int addr_size = sizeof(connection.address);

    if ((socket = accept(connection.fd, (struct sockaddr *)&connection.address,
                         (socklen_t *)&addr_size)) < 0) {
        rd_printerr("accept() failed\n");
        exit(EXIT_FAILURE);
    }

    int *socket_p = malloc(sizeof(int));
    *socket_p = socket;
    rd_handle_accepted_socket((void *)(socket_p));
}
