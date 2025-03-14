#pragma once
#include <stdlib.h>
#include <limits.h>

#include <wchar.h>
#include <stdbool.h>
#include "tlist.h"

// Used by daheionok
void append_to_intarr(int** arr, int* arr_size, int num);
bool num_inarray(int* arr, int arr_size, int num);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_realloc(void *ptr, size_t size);
void remove_from_intarr(int** arr, int* arr_size, int num);
//

// Used by snazarenko
char *mx_strnew(const int size);
int mx_strlen(const char *s);
int mx_check_space (const char c);
char *mx_strjoin(const char *s1, const char *s2);
//

// General
void mx_printchar(char c);
void mx_printint(int c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);

int mx_strcmp(const char *s1, const char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char *mx_strdup(const char *str);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, size_t n);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *file);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
int mx_count_words(const char *str, char c);


double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size) ;
int mx_quicksort(char **arr, int left, int right);
void mx_swap_char(char *s1, char *s2);
int mx_get_char_index(const char *str, char c);
void *mx_memset(void *b, int c, size_t len);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void* s1, const void* s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem( void *big, size_t big_len, void *little, size_t little_len);
void *mx_memmove(void *dst, void *src, size_t len);

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list* mx_sort_list(t_list* lst, bool (*cmp)(void*, void*));

/*
 * Used by klazebnyi
 */
int mx_get_arr_len(char** arr);
long mx_atoi(const char *str);
int mx_t_list_contains(t_list* list, char** str);
void mx_free_node_list(t_list** head);
int mx_get_arr_el_index(char** arr, const char* val);
char** mx_create_str_arr(const int len);
void mx_t_list_deep_free(t_list* list);
//








