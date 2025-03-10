#include "GTK.h"

chat_data_t* create_chat_data(const char *contact_name, int contact_id, scroll_data_t *scroll_data, int owner_id) {
    chat_data_t *chat_data = g_new(chat_data_t, 1);

    chat_data->contact_name = g_strdup(contact_name);
    chat_data->contact_id = contact_id;
    chat_data->last_message_id = 0;
    chat_data->messages_container_wrapper = create_message_container(chat_data);
    chat_data->messages = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);
    chat_data->owner_id = owner_id;
    
    gtk_widget_add_css_class(chat_data->messages_container_wrapper, "messages-container");

    // Important: Ref the widgets to prevent destruction when removed from parent
    g_object_ref(chat_data->messages_container_wrapper);
    if (scroll_data != NULL) {
        scroll_data->chat = chat_data;
        chat_data->adjustment = gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(chat_data->messages_container_wrapper));
        g_signal_connect(chat_data->adjustment, "value-changed", G_CALLBACK(on_scroll_changed), scroll_data);
    }
    return chat_data;
}
