/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls main file
*/

#include "Core/options.h"
#include "Core/files.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char *options_string = get_options(ac, av);
    char **files_path = get_files(ac, av);

    if (options_string == NULL)
        return 84;
    if (files_path == NULL)
        return 84;
    if (is_options_string_valid(options_string) == 84)
        return 84;
    free(files_path);
    free(options_string);
    return 0;
}
