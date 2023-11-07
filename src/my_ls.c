/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls main file
*/

#include "Core/options.h"
#include "Core/files.h"
#include "Core/directories.h"
#include "Core/display.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int ac, char **av)
{
    char *options_string = get_options(ac, av);
    char **files_path = get_files(ac, av);
    directory_t **directories = NULL;

    if (options_string == NULL)
        return 84;
    if (files_path == NULL)
        return 84;
    if (is_options_string_valid(options_string) == 84)
        return 84;
    directories = open_directories(files_path);
    if (directories == NULL)
        return 84;
    basic_display(directories);
    free_directories(directories);
    free(files_path);
    free(options_string);
    return 0;
}
