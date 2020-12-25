//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

static int active_threads = 0;

void *handle_socket(void *arg) {

    pthread_mutex_t mutex_increment = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex_increment);
    active_threads++;
    pthread_mutex_unlock(&mutex_increment);

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

    pthread_mutex_t mutex_decrement = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex_decrement);
    active_threads--;
    rd_log_d("LOGSRV", "Active threads number: %d", active_threads);
    pthread_mutex_unlock(&mutex_decrement);

    pthread_exit(pthread_self());
}

void rd_handle_accepted_socket(int *socket) {
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);

    pthread_t ptid;
    int thread_error = pthread_create(&ptid, NULL, &handle_socket, socket);
    if (thread_error != 0)
        rd_log_e("LOGSRV", "Can't create a thread, err: %d", thread_error);
    pthread_mutex_unlock(&mutex);
}
