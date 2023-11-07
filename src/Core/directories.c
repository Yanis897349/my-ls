/*
** EPITECH PROJECT, 2023
** manage_directories_stream
** File description:
** Manage directories stream
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "include/my_strings.h"
#include "directories.h"

static void print_invalid_directory(char *directory)
{
    write(2, "my_ls: cannot access '", 22);
    write(2, directory, my_strlen(directory));
    write(2, "': ", 3);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, "\n", 1);
}

static int get_directories_count(char **files_path)
{
    int directories_count = 0;

    for (int i = 0; files_path[i] != NULL; i++) {
        if (opendir(files_path[i]) != NULL) {
            directories_count++;
        } else {
            print_invalid_directory(files_path[i]);
        }
    }
    return directories_count;
}

static int set_directory(char *name, directory_t **directory)
{
    *directory = malloc(sizeof(directory_t));
    if (*directory == NULL)
        return 84;
    (*directory)->name = name;
    (*directory)->stream = opendir(name);
    (*directory)->stat = malloc(sizeof(struct stat));
    if ((*directory)->stat == NULL)
        return 84;
    if (stat(name, (*directory)->stat) == -1)
        return 84;
    return 0;
}

void free_directories(directory_t **directories)
{
    for (int i = 0; directories[i] != NULL; i++) {
        free(directories[i]->stat);
        closedir(directories[i]->stream);
        free(directories[i]);
    }
    free(directories);
}

directory_t **open_directories(char **files_path)
{
    directory_t **directories = NULL;
    int directories_index = 0;
    int directories_count = get_directories_count(files_path);

    directories = malloc(sizeof(directory_t *) * (directories_count + 1));
    if (directories == NULL)
        return NULL;
    my_memset(directories, 0, sizeof(directory_t *) * (directories_count + 1));
    for (int i = 0; files_path[i] != NULL; i++) {
        if (set_directory(files_path[i],
            &directories[directories_index++]) == 84)
            return NULL;
    }
    directories[directories_count] = NULL;
    return directories;
}
