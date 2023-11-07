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

void close_directories(DIR **directories)
{
    for (int i = 0; directories[i] != NULL; i++) {
        closedir(directories[i]);
    }
    free(directories);
}

DIR **open_directories(char **files_path)
{
    DIR **directories = NULL;
    int directories_index = 0;
    int directories_count = get_directories_count(files_path);

    directories = malloc(sizeof(DIR *) * (directories_count + 1));
    if (directories == NULL)
        return NULL;
    my_memset(directories, 0, sizeof(DIR *) * (directories_count + 1));
    for (int i = 0; files_path[i] != NULL; i++) {
        if (opendir(files_path[i]) != NULL) {
            directories[directories_index++] = opendir(files_path[i]);
        }
    }
    directories[directories_count] = NULL;
    return directories;
}
