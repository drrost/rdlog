//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

void *handle_socket(void *arg) {
    int socket = *(int *)(arg);
    pthread_detach(pthread_self());

    const int buff_size = 1024;
    char *buffer = rd_strnew(buff_size);

    read(socket, buffer, buff_size);
    close(socket);

    pthread_mutex_t mutex_log = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex_log);
    rd_log_d("LOGSRV", "Received log message: \"%s\" from socket: %d", buffer, socket);
    pthread_mutex_unlock(&mutex_log);

    rd_strdel(&buffer);
    free(arg);

    return NULL;
}

void rd_handle_accepted_socket(int *socket) {
    pthread_t ptid;
    pthread_create(&ptid, NULL, &handle_socket, socket);
}
