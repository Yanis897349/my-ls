/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage directory
*/

#include "files.h"
#include "directory.h"
#include "include/my_strings.h"
#include "include/my_std.h"
#include "Helpers/path.h"
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int is_directory_empty(char *dir_name, file_t **dir)
{
    (*dir)->is_directory = 1;
    if (my_strcmp(dir_name, ".") == 0 || my_strcmp(dir_name, "..") == 0) {
        (*dir)->is_directory = 0;
        return 0;
    }
    return 1;
}

static int set_file_properties(file_t **dir, file_t *file, struct dirent *info,
    options_t *options)
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
    if (lstat(file->path, file->stat) == -1)
        return 84;
    if (S_ISDIR(file->stat->st_mode)) {
        if (is_directory_empty(info->d_name, &file) == 0)
            return 0;
        if (set_directory_content(&file, options) == 84)
            return 84;
    } else
        file->is_directory = 0;
    return 0;
}

static int handle_error(DIR *directory)
{
    if (directory != NULL) {
        closedir(directory);
    }
    return 84;
}

static int update_directory_content(file_t **dir, struct dirent *dirent, int i,
    options_t *options)
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
    if (set_file_properties(dir, (*dir)->content[i], dirent, options) == 84) {
        return handle_error(NULL);
    }
    return 0;
}

static int fill_directory(file_t **dir, DIR *stream, options_t *options,
    int *dir_index)
{
    struct dirent *dirent = NULL;

    dirent = readdir(stream);
    while (dirent != NULL) {
        if (!options->is_all && dirent->d_name[0] == '.') {
            dirent = readdir(stream);
            continue;
        }
        if (update_directory_content(dir, dirent, (*dir_index), options) == 84)
            return handle_error(stream);
        (*dir_index)++;
        dirent = readdir(stream);
    }
    return 0;
}

int set_directory_content(file_t **dir, options_t *options)
{
    DIR *directory = opendir((*dir)->path);
    int i = 0;

    if (directory == NULL)
        return handle_error(directory);
    (*dir)->content = malloc(sizeof(file_t *) * 2);
    if ((*dir)->content == NULL)
        return handle_error(directory);
    my_memset((*dir)->content, 0, sizeof(file_t *) * 2);
    if (fill_directory(dir, directory, options, &i) == 84)
        return 84;
    (*dir)->content[i] = NULL;
    closedir(directory);
    return 0;
}
