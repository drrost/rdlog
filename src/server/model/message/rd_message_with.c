//
// Created by Rostyslav Druzhchenko on 26.12.2020.
//

#include <rd_model.h>
#include <json.h>

static t_message *message_from_json_node(JsonNode *node) {
    t_message *message = rd_message_new();

    message->version = json_find_member(node, "version")->number_;
    message->message = rd_strdup(json_find_member(node, "message")->string_);

    JsonNode *sender = json_find_member(node, "sender");
    if (sender)
        message->sender = rd_strdup(sender->string_);
    else
        message->sender = rd_strdup("Unknown");

    JsonNode *type = json_find_member(node, "type");
    if (type)
        message->type = type->number_;
    else
        message->type = E_MESSAGE_TYPE_MESSAGE;

    JsonNode *level = json_find_member(node, "log_level");
    if (level)
        message->log_level = level->number_;
    else
        message->log_level = LOG_INFO;

    return message;
}

static t_message *message_from_string(char *s) {
    t_message *message = rd_message_new();
    message->sender = rd_strdup("Unknown");
    message->message = rd_strdup(s);
    message->type = E_MESSAGE_TYPE_MESSAGE;
    message->version = 0;
    message->log_level = LOG_INFO;
    return message;
}

static bool is_valid_jsom_message(JsonNode *node) {
    return node &&
           json_find_member(node, "message") &&
           json_find_member(node, "version");
}

t_message *rd_message_with(char *s) {
    t_message *message = 0;
    JsonNode *node_root = json_decode(s);
    if (is_valid_jsom_message(node_root)) {
        message = message_from_json_node(node_root);
    }
    else
        message = message_from_string(s);

    if (node_root)
        json_delete(node_root);

    return message;
}
