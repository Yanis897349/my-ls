/*
** EPITECH PROJECT, 2023
** display
** File description:
** Basic display behavior of my_ls
*/

#include "files.h"
#include "display.h"
#include "Helpers/sort.h"
#include "Helpers/path.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

static void display_directory(file_t *file)
{
    char *filename = NULL;

    write(1, file->path, my_strlen(file->path));
    write(1, ":\n", 2);
    for (int i = 0; file->content[i] != NULL; i++) {
        filename = extract_name_from_path(file->content[i]->path);
        if (filename[0] == '.')
            continue;
        write(1, filename, my_strlen(filename));
        if (file->content[i + 1] != NULL)
            write(1, "  ", 2);
    }
    write(1, "\n\n", 2);
}

static void display_one_directory(file_t *file)
{
    char *filename = NULL;

    for (int i = 0; file->content[i] != NULL; i++) {
        filename = extract_name_from_path(file->content[i]->path);
        if (filename[0] == '.')
            continue;
        write(1, filename, my_strlen(filename));
        if (file->content[i + 1] != NULL)
            write(1, "  ", 2);
    }
    write(1, "\n", 1);
}

static void process_file(file_t *file, int is_last_file)
{
    if (file->is_directory) {
        display_directory(file);
    } else {
        write(1, file->path, my_strlen(file->path));
        if (!is_last_file)
            write(1, "  ", 2);
    }
}

static int get_last_file_index(file_t **files_list)
{
    int last_file_index = -1;

    for (int i = 0; files_list[i] != NULL; i++) {
        if (!files_list[i]->is_directory) {
            last_file_index = i;
        }
    }
    return last_file_index;
}

void basic_display(file_t **files_list)
{
    int last_file_index = get_last_file_index(files_list);
    int directory_exists = 0;

    sort_alphabetically(files_list);
    if (files_list[0] != NULL && files_list[0]->is_directory
        && files_list[1] == NULL) {
            return display_one_directory(files_list[0]);
    }
    for (int i = 0; files_list[i] != NULL; i++) {
        if (files_list[i]->is_directory) {
            directory_exists = 1;
            continue;
        }
        process_file(files_list[i], i == last_file_index);
    }
    if (directory_exists)
        write(1, "\n\n", 2);
    for (int i = 0; files_list[i] != NULL; i++)
        if (files_list[i]->is_directory)
            process_file(files_list[i], 0);
}
