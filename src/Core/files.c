/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage files for my ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "include/my_strings.h"
#include "files.h"

static void print_invalid_file(char *filepath)
{
    write(2, "my_ls: cannot access '", 22);
    write(2, filepath, my_strlen(filepath));
    write(2, "': ", 3);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, "\n", 1);
}

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
    (*file)->path = filepath;
    (*file)->stat = malloc(sizeof(struct stat));
    if ((*file)->stat == NULL)
        return 84;
    if (stat(filepath, (*file)->stat) == -1)
        return 84;
    if (S_ISDIR((*file)->stat->st_mode))
        (*file)->is_directory = 1;
    else
        (*file)->is_directory = 0;
    return 0;
}

void free_files_list(file_t **files_list)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        free(files_list[i]->stat);
        free(files_list[i]);
    }
    free(files_list);
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
        if (set_file(files_path[i], &files_list[files_index++]) == 84)
            files_index--;
    }
    files_list[files_count] = NULL;
    return files_list;
}
