//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static void init_db() {
    if (!rd_db_exists())
        rd_db_create();
}

static void run_as_regular(int port) {
    init_db();
    rd_log_i(rd_get_app_name(), "DB initialized");

    t_socket_connection connection = rd_open_socket_to_listen(port);
    rd_log_i(rd_get_app_name(), "Start on port %d", port);

    while (1) {
//        rd_reset_leacks();
        rd_accept_from_socket(connection);
//        rd_check_leaks();
    }
}

void rd_run(char *port_str) {
    int port = atoi(port_str);
    run_as_regular(port);
}

