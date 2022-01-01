//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

t_socket_connection rd_open_socket_to_listen(int port) {
    t_socket_connection connection;
    struct sockaddr_in address;

    connection.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connection.fd < 0) {
        rd_printerr("socket() failed\n");
        rd_printerr(strerror(errno));
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int res = bind(connection.fd, (struct sockaddr *)&address,
                   sizeof(address));
    if (res < 0) {
        rd_printerr("bind() failed\n");
        rd_printerr(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (listen(connection.fd, 3) < 0) {
        rd_printerr("listen() failed\n");
        exit(EXIT_FAILURE);
    }

    return connection;
}
