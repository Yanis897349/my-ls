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

void basic_display(directory_t **directories)
{
    struct dirent *dirent = NULL;

    for (int i = 0; directories[i] != NULL; i++) {
        dirent = readdir(directories[i]->stream);
        while (dirent != NULL) {
            if (dirent->d_name[0] != '.') {
                write(1, dirent->d_name, my_strlen(dirent->d_name));
                write(1, "  ", 2);
            }
            dirent = readdir(directories[i]->stream);
        }
    }
    write(1, "\n", 1);
}
