/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage files for my ls
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Core/options.h"
#include "include/my_strings.h"
#include "Display/display_error.h"
#include "files.h"
#include "directory.h"
#include "errno.h"

static int check_permissions(struct stat *file_stat, char *filepath)
{
    DIR *directory = NULL;

    if (S_ISDIR(file_stat->st_mode)) {
        directory = opendir(filepath);
        if (directory == NULL)
            return -1;
        closedir(directory);
    }
    return 1;
}

static int get_valid_files_count(char **files_path)
{
    struct stat file_stat;
    int valid_files_count = 0;
    int stat_return = 0;

    for (int i = 0; files_path[i] != NULL; i++) {
        stat_return = lstat(files_path[i], &file_stat);
        if (check_permissions(&file_stat, files_path[i]) != -1
            && stat_return != -1) {
            valid_files_count++;
        } else {
            print_invalid_file(files_path[i]);
            return -1;
        }
    }
    return valid_files_count;
}

static int set_file(char *filepath, file_t **file, options_t *options)
{
    *file = malloc(sizeof(file_t));
    if (*file == NULL)
        return 84;
    my_memset(*file, 0, sizeof(file_t));
    (*file)->path = my_strdup(filepath);
    (*file)->stat = malloc(sizeof(struct stat));
    if ((*file)->stat == NULL)
        return 84;
    if (lstat(filepath, (*file)->stat) == -1)
        return 84;
    if (S_ISDIR((*file)->stat->st_mode)) {
        if (options->is_dir_only)
            return 0;
        if (set_directory_content(file, options) == 84)
            return 84;
        (*file)->is_directory = 1;
    } else {
        (*file)->is_directory = 0;
    }
    return 0;
}

char get_filetype(file_t *file)
{
    if (S_ISDIR(file->stat->st_mode))
        return 'd';
    if (S_ISLNK(file->stat->st_mode))
        return 'l';
    if (S_ISCHR(file->stat->st_mode))
        return 'c';
    if (S_ISBLK(file->stat->st_mode))
        return 'b';
    if (S_ISFIFO(file->stat->st_mode))
        return 'p';
    if (S_ISSOCK(file->stat->st_mode))
        return 's';
    return '-';
}

file_t **get_files_list(char **files_path, options_t *options)
{
    int files_count = get_valid_files_count(files_path);
    int files_index = 0;
    file_t **files_list = NULL;

    if (files_count == -1)
        return NULL;
    files_list = malloc(sizeof(file_t *) * (files_count + 1));
    if (files_list == NULL)
        return NULL;
    my_memset(files_list, 0, sizeof(file_t *) * (files_count + 1));
    for (int i = 0; files_path[i] != NULL; i++) {
        if (set_file(files_path[i], &files_list[files_index], options) != 84)
            files_index++;
    }
    files_list[files_count] = NULL;
    return files_list;
}
