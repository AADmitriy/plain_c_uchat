#include "create_json.h"
#include "password.h"

static bool is_valid_password(sqlite3 *db, char* login, char *password) {
    unsigned char *db_hash = get_password_hash(db, login);
    unsigned char *input_hash = hash_password(password, login);

    if (memcmp(db_hash, input_hash, 32) != 0) {
        free(db_hash);
        free(input_hash);
        return false;
    }
    free(db_hash);
    free(input_hash);
    return true;
}

cJSON *handle_change_password(call_data_t *call_data, cJSON *json) {
    if (!cJSON_HasObjectItem(json, "old_password")
        || !cJSON_HasObjectItem(json, "new_password")) {
        return create_error_json("Invalid data\n");
    }

    cJSON *old_password_json = cJSON_GetObjectItemCaseSensitive(json, "old_password");
    cJSON *new_password_json = cJSON_GetObjectItemCaseSensitive(json, "new_password");

    if (strcmp(old_password_json->valuestring, new_password_json->valuestring) == 0) {
        return create_error_json("Invalid data\n");
    }

    int user_id = call_data->client_data->user_data->user_id;

    // Critical resource access: USER DATA. Start
    pthread_mutex_lock(&call_data->client_data->user_data->mutex);

    // Critical resource access: DATABASE. Start
    pthread_mutex_lock(call_data->general_data->db_mutex);

    if (!is_valid_password(call_data->general_data->db, 
                           call_data->client_data->user_data->login,
                           old_password_json->valuestring)) {
        pthread_mutex_unlock(call_data->general_data->db_mutex);
        // Critical resource access: DATABASE. Possible end
    
        pthread_mutex_unlock(&call_data->client_data->user_data->mutex);
        // Critical resource access: USER DATA. Possible end

        return create_error_json("Invalid data\n");
    }

    unsigned char *new_hash = hash_password(new_password_json->valuestring,
                                            call_data->client_data->user_data->login);
    pthread_mutex_unlock(&call_data->client_data->user_data->mutex);
    // Critical resource access: USER DATA. End

    int return_code = update_password_hash(call_data->general_data->db, user_id, new_hash);
    pthread_mutex_unlock(call_data->general_data->db_mutex);
    // Critical resource access: DATABASE. End

    free(new_hash);

    bool success = (return_code == SQLITE_DONE);

    if (!success) {
        return create_error_json("Something went wrong\n");
    }

    cJSON *response_json = cJSON_CreateObject();
    cJSON_AddBoolToObject(response_json, "success", true);

    return response_json;
}
