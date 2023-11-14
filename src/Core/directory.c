/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage directory
*/

#include "files.h"
#include "include/my_strings.h"
#include "include/my_std.h"
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static char *get_complete_path(char *dir_path, char *filename, int len)
{
    char *path = malloc(len);

    if (path == NULL)
        return NULL;
    my_strcpy(path, dir_path);
    my_strcat(path, "/");
    my_strcat(path, filename);
    return path;
}

static int set_file_properties(file_t **dir, file_t *file, struct dirent *info)
{
    int path_length = my_strlen((*dir)->path) + my_strlen(info->d_name) + 2;
    char *path = get_complete_path((*dir)->path, info->d_name, path_length);

    if (path == NULL)
        return 84;
    my_memset(file, 0, sizeof(file_t));
    file->path = path;
    file->stat = malloc(sizeof(struct stat));
    if (file->stat == NULL)
        return 84;
    if (stat(file->path, file->stat) == -1) {
        return 84;
    }
    if (S_ISDIR(file->stat->st_mode)) {
        file->is_directory = 1;
    } else {
        file->is_directory = 0;
    }
    return 0;
}

static int handle_error(DIR *directory)
{
    if (directory != NULL) {
        closedir(directory);
    }
    return 84;
}

static int update_directory_content(file_t **dir, struct dirent *dirent, int i)
{
    size_t old_size = sizeof(file_t *) * (i + 1);
    size_t new_size = sizeof(file_t *) * (i + 2);
    file_t **temp = my_realloc((*dir)->content, old_size, new_size);

    if (temp == NULL) {
        return handle_error(NULL);
    }
    my_memset(temp + i, 0, sizeof(file_t *) * 2);
    (*dir)->content = temp;
    (*dir)->content[i] = malloc(sizeof(file_t));
    if ((*dir)->content[i] == NULL) {
        return handle_error(NULL);
    }
    if (set_file_properties(dir, (*dir)->content[i], dirent) == 84) {
        return handle_error(NULL);
    }
    return 0;
}

int set_directory_content(file_t **dir)
{
    DIR *directory = opendir((*dir)->path);
    struct dirent *dirent = NULL;
    int i = 0;

    if (directory == NULL)
        return handle_error(directory);
    (*dir)->content = malloc(sizeof(file_t *) * 2);
    if ((*dir)->content == NULL)
        return handle_error(directory);
    my_memset((*dir)->content, 0, sizeof(file_t *) * 2);
    dirent = readdir(directory);
    while (dirent != NULL) {
        if (update_directory_content(dir, dirent, i) == 84)
            return handle_error(directory);
        i++;
        dirent = readdir(directory);
    }
    (*dir)->content[i] = NULL;
    closedir(directory);
    return 0;
}
