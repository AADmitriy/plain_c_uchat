int mx_strcmp(const char* s1, const char* s2);

int mx_bubble_sort(char** arr, int size) {
	int counter = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
				counter++;
				char* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return counter;
}
