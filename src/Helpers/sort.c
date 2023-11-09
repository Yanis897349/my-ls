/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Sort entries
*/

#include "Core/files.h"
#include "include/my_strings.h"
#include <stdio.h>

static void swap_pointer(file_t **a, file_t **b)
{
    file_t *tmp = *a;

    *a = *b;
    *b = tmp;
}

static void is_greater(file_t **files_list, int i, int j)
{
    if (my_strcmp(files_list[i]->path, files_list[j]->path) > 0) {
        swap_pointer(&files_list[i], &files_list[j]);
    }
}

static void sort_files(file_t **files_list)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        for (int j = i + 1; files_list[j] != NULL; j++) {
            is_greater(files_list, i, j);
        }
    }
}

void sort_alphabetically(file_t **files_list)
{
    if (!files_list[0]->is_directory && files_list[1] == NULL)
        return;
    for (int i = 0; files_list[i] != NULL; i++) {
        if (files_list[i]->is_directory)
            sort_files(files_list[i]->content);
    }
    for (int i = 0; files_list[i] != NULL; i++) {
        sort_files(files_list);
    }
}
