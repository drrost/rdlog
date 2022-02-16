//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static void run_as_regular(int port) {
    rd_db_init();
    t_socket_connection connection = rd_open_socket_to_listen(port);
    rd_log_i(rd_get_app_name(), "Start on port %d", port);

    rd_printf("\nStarted on port %d\n", port);

    while (1) {
        rd_accept_from_socket(connection);
    }
}

void rd_run(char *port_str) {
    int port = atoi(port_str);
    run_as_regular(port);
}
