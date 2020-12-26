//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rd_model.h>

t_message *rd_message_with(char *s) {
    t_message *message = rd_message_new();
    message->sender = rd_strdup("Unknown");
    message->message = rd_strdup(s);
    message->type = E_MESSAGE_TYPE_MESSAGE;
    message->version = 0;
    message->log_level = LOG_INFO;
    return message;
}
