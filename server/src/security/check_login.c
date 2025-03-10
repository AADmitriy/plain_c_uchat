#include <password.h>

bool check_login(char *login) { //Валидация логина
    if (login == NULL) { //Проверка на пустую строку
        return false;
    }

    int login_length = mx_strlen(login);
    if (login_length < 3 || login_length > 20) {
        return false;
    }

    for (int i = 0; i < login_length; i++) {
        if (mx_check_space(login[i]) 
            || !((login[i] >= '0' && login[i] <= '9')
                  || (login[i] >= 'A' && login[i] <= 'Z') 
                  || (login[i] >= 'a' && login[i] <= 'z')
                  || login[i] == '_')) { 
            return false;
        }
    }
    return true;
}

