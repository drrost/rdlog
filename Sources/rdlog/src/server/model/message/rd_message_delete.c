//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

void rd_message_delete(t_message **message) {
    t_message *instance = *message;
    rd_strdel(&(instance->message));
    rd_strdel(&(instance->sender));
    DELETE_INSTANCE(message);
}
