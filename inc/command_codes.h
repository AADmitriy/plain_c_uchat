#pragma once

#define SEND_TO_CHAT 0
#define SEND_TO_USER 1
#define CREATE_CHAT 2
#define SEE_ALL_CHATS 3
#define SEE_ALL_USERS 4
#define ADD_CONTACT 5
#define SEE_MY_CONTACTS 6
#define JOIN_CHAT 7
#define ADD_CONTACT_TO_CHAT 8
#define EXIT 9
#define GET_MY_CONTACTS 10
#define LOGIN 11
#define GET_ALL_TALKS 12
#define ERROR  13
#define UPDATE_NICKNAME 14
#define CHANGE_PASSWORD 15
#define CREATE_USER 16
#define GET_ALL_CLIENTS_USERSLIST 17
#define MARK_CHAT_MSGS_AS_READED 18
#define GET_MY_CLIENTS_USERSLIST 19
#define DELETE_USER_FROM_GROUP 20
#define ADD_MANY_USERS_TO_GROUP 21
#define DELETE_GROUP 22
#define ADMIN_CHANGE_PASSWORD 23
#define GET_NUM_OF_MSGS_BETWEEN 24
#define DEACTIVATE_USER 25
#define ACTIVATE_USER 26
#define GET_NUM_OF_MSGS_FROM_GROUP 27
#define UPDATE_MESSAGE 28
#define DELETE_MESSAGE 29
#define GET_MY_GROUPS 30
#define MARK_GROUP_MSGS_AS_READED 31
#define GET_CHAT_USERS 32



#define NEW_CONTACT_WAS_ADDED 50
#define INCOMING_MESSAGE 51
#define YOU_WERE_ADDED_TO_CHAT 52
#define USER_RETURNED_ONLINE 53
#define USER_LEFT 54
#define NEW_USER_WAS_CREATED 55
#define YOU_WERE_DELETED_FROM_GROUP 56
#define UPDATED_MESSAGE 57
#define DELETED_MESSAGE 58
#define NICKNAME_CHANGED 59
#define USER_WAS_ACTIVATED 60
#define USER_WAS_DEACTIVATED 61
#define GROUP_WAS_DELETED 62
#define USER_WAS_DELETED_FROM_GROUP 63
#define USER_WAS_ADDED_TO_GROUP 64


enum MESSAGE_TYPE {
    PRIVATE_MESSAGE,
    GROUP_MESSAGE,
    SYSTEM_MESSAGE,
};

