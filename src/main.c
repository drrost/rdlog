//
// Created by Rostyslav Druzhchenko 24.12.20
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <rdlib.h>

#include <rdlog.h>

int n = 0;

void *handle_message() {
    // Function body
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    n++;
    int i = n;
    pthread_mutex_unlock(&mutex);

    pthread_detach(pthread_self());

    rd_log_d("THREAD", "Entering thread: %d", i);
    rd_log_d("THREAD", "Exiting thread: %d", i);

    printf("Entering thread: %d\n", i);
    printf("Exiting thread: %d\n", i);

    pthread_exit(NULL);
}

void fun() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, &handle_message, NULL);
}

// ----

typedef struct {
    struct sockaddr_in address;
    int fd;
} t_socket_connection;

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
}

static void run_as_regular(int port) {
    t_socket_connection connection = rd_open_socket_to_listen(port);

//    rd_db_init();
    rd_log_i("SRV: Start", "on port %d", port);

    while (1) {
//        rd_reset_leacks();
        rd_accept_from_socket(connection);
//        rd_check_leaks();
    }
}

static void process(const char *port_str) {
    int port = atoi(port_str);
    run_as_regular(port);
}

int main(int argc, char *argv[]) {
    rd_validate(argc, argv);
    process(argv[1]);
    return 0;
}
