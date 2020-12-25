//
// Created by Rostyslav Druzhchenko on 25.12.2020.
//

#include <rdlog.h>

t_message *rd_message_new() {
    CREATE_INSTANCE(t_message);
    return instance;
}
