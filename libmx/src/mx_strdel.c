#include <stdlib.h>

void mx_strdel(char** str) {
	if (str != NULL && *str != NULL) {
		free(*str);
		*str = NULL;
	}
}
