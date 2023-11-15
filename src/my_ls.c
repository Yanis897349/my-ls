/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls main file
*/

#include "Core/options.h"
#include "Core/files.h"
#include "Core/display.h"
#include "Helpers/memory.h"
#include "Helpers/args.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main(int ac, char **av)
{
    options_t *options = create_options(ac, av);
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = NULL;

    if (options == NULL)
        return 84;
    if (files_path == NULL)
        return 84;
    files_list = get_files_list(files_path);
    if (files_list == NULL)
        return 84;
    sort_before_display(files_list, options);
    free_files_list(files_list);
    free(files_path);
    free(options);
    return 0;
}
