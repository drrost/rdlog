//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#ifndef TESTTHREADS_RD_MODEL_H
#define TESTTHREADS_RD_MODEL_H

#include <rdlib.h>

// Messages
//

typedef enum message_type {
    E_MESSAGE_TYPE_NONE = 0,
    E_MESSAGE_TYPE_MESSAGE,
    E_MESSAGE_TYPE_SERVICE
} e_message_type;

typedef struct s_message {
    char *sender;
    char *message;
    enum e_log_level log_level;
    e_message_type type;
    int version;
} t_message;

t_message *rd_message_new();
void rd_message_delete(t_message **message);
t_message *rd_message_with(char *s);

#endif //TESTTHREADS_RD_MODEL_H
