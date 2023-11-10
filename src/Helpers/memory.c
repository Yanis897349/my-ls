/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage memory for my_ls
*/

#include "Core/files.h"
#include <stdlib.h>

void free_files_list(file_t **files_list)
{
    if (files_list == NULL)
        return;
    for (int i = 0; files_list[i] != NULL; i++) {
        if (files_list[i]->stat != NULL) {
            free(files_list[i]->stat);
            files_list[i]->stat = NULL;
        }
        if (files_list[i]->is_directory && files_list[i]->content != NULL) {
            free_files_list(files_list[i]->content);
            files_list[i]->content = NULL;
        }
        free(files_list[i]->path);
        free(files_list[i]);
        files_list[i] = NULL;
    }
    free(files_list);
    files_list = NULL;
}
