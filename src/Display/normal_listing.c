/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Long listing format
*/

#include "Core/files.h"
#include "Core/options.h"
#include "Helpers/path.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include <unistd.h>

static void print_normal_file(file_t *file, int is_in_directory)
{
    char *filename = (is_in_directory == 1) ?
        extract_name_from_path(file->path) : file->path;

    my_putstr(filename);
}

static void print_normal_directory(file_t *file)
{
    my_putstr(file->path);
    my_putstr(":\n");
    for (int i = 0; file->content[i] != NULL; i++) {
        print_normal_file(file->content[i], 1);
        write(1, "  ", 2);
    }
}

static int handle_normal_listing_special(file_t **files_list,
    options_t *options)
{
    int is_special = 0;

    if (options->is_recursive)
        return is_special;
    if (files_list[0]->is_directory && files_list[1] == NULL) {
        is_special = 1;
        for (int i = 0; files_list[0]->content[i] != NULL; i++) {
            print_normal_file(files_list[0]->content[i], 1);
            write(1, "  ", 2);
        }
    }
    return is_special;
}

void normal_listing_file(file_t **files_list, int *have_directory)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        if (files_list[i]->is_directory) {
            (*have_directory) = 1;
            continue;
        }
        print_normal_file(files_list[i], 0);
        write(1, "  ", 2);
    }
}

void normal_listing_directories(file_t **files_list, options_t *options)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        if (!files_list[i]->is_directory) {
            continue;
        }
        print_normal_directory(files_list[i]);
        my_putchar('\n');
        my_putchar('\n');
        if (options->is_recursive)
            normal_listing_directories(files_list[i]->content, options);
    }
}

void handle_normal_listing(file_t **files_list, options_t *options)
{
    int have_directory = 0;

    if (handle_normal_listing_special(files_list, options))
        return;
    normal_listing_file(files_list, &have_directory);
    if (!have_directory)
        return;
    my_putchar('\n');
    my_putchar('\n');
    normal_listing_directories(files_list, options);
}
