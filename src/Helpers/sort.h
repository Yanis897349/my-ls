/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Sort entries alphabetically
*/

#ifndef SORT_H_
    #define SORT_H_
    #include "Core/files.h"

typedef void (*sort_func_t)(file_t **files_list);

typedef struct sort_options_s {
    sort_func_t function;
    int *option_flag;
} sort_options_t;

void sort_time(file_t **files_list);
void sort_alphabetically(file_t **files_list);
void sort_reverse(file_t **files_list);

#endif /* !SORT_H_ */
