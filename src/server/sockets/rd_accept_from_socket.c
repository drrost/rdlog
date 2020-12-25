//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

void rd_accept_from_socket(t_socket_connection connection) {
    int socket = 0;
    const int buff_size = 1024;
    char *buffer = rd_strnew(buff_size);
    int addr_size = sizeof(connection.address);

    if ((socket = accept(connection.fd, (struct sockaddr *)&connection.address,
                         (socklen_t *)&addr_size)) < 0) {
        rd_printerr("accept() failed\n");
        exit(EXIT_FAILURE);
    }

    read(socket, buffer, buff_size);
    rd_log_d("LOGSRV", "Received log message: \"%s\"", buffer);

    close(socket);
    rd_strdel(&buffer);
}
