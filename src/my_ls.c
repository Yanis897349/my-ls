/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls main file
*/

#include "Core/options.h"
#include "Core/files.h"
#include "Core/display.h"
#include "Helpers/args.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int ac, char **av)
{
    char *options_string = get_options(ac, av);
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = NULL;

    if (options_string == NULL)
        return 84;
    if (files_path == NULL)
        return 84;
    if (is_options_string_valid(options_string) == 84)
        return 84;
    files_list = get_files_list(files_path);
    if (files_list == NULL)
        return 84;
    basic_display(files_list);
    free_files_list(files_list);
    free(files_path);
    free(options_string);
    return 0;
}
