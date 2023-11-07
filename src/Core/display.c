/*
** EPITECH PROJECT, 2023
** display
** File description:
** Basic display behavior of my_ls
*/

#include "directories.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>

static void read_and_display_directory(directory_t *directory)
{
    struct dirent *dirent = NULL;

    dirent = readdir(directory->stream);
    while (dirent != NULL) {
        if (dirent->d_name[0] != '.') {
            write(1, dirent->d_name, my_strlen(dirent->d_name));
            write(1, "  ", 2);
        }
        dirent = readdir(directory->stream);
    }
}

void basic_display(directory_t **directories)
{
    for (int i = 0; directories[i] != NULL; i++) {
        read_and_display_directory(directories[i]);
    }
    write(1, "\n", 1);
}
