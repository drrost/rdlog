//
// Created by Rostyslav Druzhchenko 24.12.20
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <rdlib.h>

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

int main(int argc, char *argv[]) {
    printf("Called \"%s\" with %d arguments\n", argv[0], argc);

    for (int i = 0; i < 10 ;i++)
        fun();
    sleep(1);
    printf("Exiting main thread\n");
    return 0;
}
