#pragma once 
#include "server.h"
#include "cJSON.h"

void handle_user_msg(int bytes_received, int *leave_flag, 
                     char *client_msg, call_data_t *call_data);
cJSON *handle_add_contact_to_chat(call_data_t *call_data, cJSON *json);
cJSON *handle_join_chat(call_data_t *call_data, cJSON *json);
cJSON *handle_create_chat(call_data_t *call_data, cJSON *json);
cJSON *handle_send_to_user(call_data_t *call_data, cJSON *json);
cJSON *handle_send_to_chat(call_data_t *call_data, cJSON *json);
cJSON *handle_see_all_chats(call_data_t *call_data);
cJSON *handle_see_my_contacts(call_data_t *call_data);
cJSON *handle_get_my_contacts(call_data_t *call_data);
cJSON* handle_get_all_talks(call_data_t *call_data);
cJSON *handle_update_nickname(call_data_t *call_data, cJSON *json);
cJSON *handle_change_password(call_data_t *call_data, cJSON *json);
cJSON *handle_create_user(call_data_t *call_data, cJSON *json);
cJSON* handle_get_all_clients_userslist(call_data_t *call_data);
cJSON *handle_mark_chat_msgs_as_readed(call_data_t *call_data, cJSON *json);
cJSON* handle_get_my_clients_userslist(call_data_t *call_data);
cJSON *handle_delete_user_from_group(call_data_t *call_data, cJSON *json);
cJSON *handle_add_many_users_to_group(call_data_t *call_data, cJSON *json);
cJSON *handle_delete_group(call_data_t *call_data, cJSON *json);
cJSON *handle_admin_change_password(call_data_t *call_data, cJSON *json);
cJSON* handle_get_last_msgs_between(call_data_t *call_data, cJSON *json);
cJSON *handle_deactivate_user(call_data_t *call_data, cJSON *json);
cJSON *handle_activate_user(call_data_t *call_data, cJSON *json);
cJSON* handle_get_num_of_msgs_from_group(call_data_t *call_data, cJSON *json);
cJSON *handle_update_message(call_data_t *call_data, cJSON *json);
cJSON *handle_delete_message(call_data_t *call_data, cJSON *json);
cJSON *handle_get_my_groups(call_data_t *call_data);
cJSON *handle_mark_group_msgs_as_readed(call_data_t *call_data, cJSON *json);
cJSON *handle_get_chat_users(call_data_t *call_data, cJSON *json);

