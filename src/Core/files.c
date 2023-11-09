/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage files for my ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/my_strings.h"
#include "display_error.h"
#include "files.h"
#include "directory.h"

static int get_valid_files_count(char **files_path)
{
    struct stat file_stat;
    int valid_files_count = 0;

    for (int i = 0; files_path[i] != NULL; i++) {
        if (stat(files_path[i], &file_stat) != -1) {
            valid_files_count++;
        } else {
            print_invalid_file(files_path[i]);
        }
    }
    return valid_files_count;
}

static int set_file(char *filepath, file_t **file)
{
    *file = malloc(sizeof(file_t));
    if (*file == NULL)
        return 84;
    my_memset(*file, 0, sizeof(file_t));
    (*file)->path = my_strdup(filepath);
    (*file)->stat = malloc(sizeof(struct stat));
    if ((*file)->stat == NULL)
        return 84;
    if (stat(filepath, (*file)->stat) == -1)
        return 84;
    if (S_ISDIR((*file)->stat->st_mode)) {
        (*file)->is_directory = 1;
        if (set_directory_content(file) == 84)
            return 84;
    } else {
        (*file)->is_directory = 0;
    }
    return 0;
}

file_t **get_files_list(char **files_path)
{
    int files_count = get_valid_files_count(files_path);
    int files_index = 0;
    file_t **files_list = malloc(sizeof(file_t *) * (files_count + 1));

    if (files_list == NULL)
        return NULL;
    my_memset(files_list, 0, sizeof(file_t *) * (files_count + 1));
    for (int i = 0; files_path[i] != NULL; i++) {
        if (set_file(files_path[i], &files_list[files_index]) != 84)
            files_index++;
    }
    files_list[files_count] = NULL;
    return files_list;
}
