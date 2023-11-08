/*
** EPITECH PROJECT, 2023
** display
** File description:
** Basic display behavior of my_ls
*/

#include "files.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>

static void display_directory(struct dirent *dirent, int *is_first_entry)
{
    if (dirent->d_name[0] != '.') {
        if (*is_first_entry == 0) {
            write(1, "  ", 2);
        } else {
            *is_first_entry = 0;
        }
        write(1, dirent->d_name, my_strlen(dirent->d_name));
    }
}

static void read_directory(file_t *file)
{
    struct dirent *dirent = NULL;
    DIR *directory = opendir(file->path);
    int is_first_entry = 1;

    dirent = readdir(directory);
    while (dirent != NULL) {
        display_directory(dirent, &is_first_entry);
        dirent = readdir(directory);
    }
    closedir(directory);
}

static void process_file(file_t *file)
{
    if (file->is_directory) {
        read_directory(file);
    } else {
        write(1, file->path, my_strlen(file->path));
        write(1, "  ", 2);
    }
}

void basic_display(file_t **files_list)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        process_file(files_list[i]);
    }
    write(1, "\n", 1);
}
