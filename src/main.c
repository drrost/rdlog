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
