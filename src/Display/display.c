/*
** EPITECH PROJECT, 2023
** display
** File description:
** Basic display behavior of my_ls
*/

#include "Core/options.h"
#include "Core/files.h"
#include "display.h"
#include "Helpers/sort.h"
#include "Helpers/path.h"
#include "include/my_strings.h"
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

void display_methods(file_t **files_list, options_t *options)
{
    if (options->is_long)
        return handle_long_listing(files_list, options);
    return handle_normal_listing(files_list, options);
}

void sort_before_display(file_t **files_list, options_t *options)
{
    int is_sorted = 0;
    sort_options_t sort_options[] = {
        {&sort_time, &options->is_time_sort},
        {&sort_reverse, &options->is_reverse_sort}
    };

    if (files_list[0] == NULL)
        return;
    for (int i = 0; i < 2; i++) {
        if (*sort_options[i].option_flag) {
            sort_options[i].function(files_list);
            is_sorted = 1;
        }
    }
    if (!is_sorted)
        sort_alphabetically(files_list);
    display_methods(files_list, options);
}
