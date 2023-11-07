/*
** EPITECH PROJECT, 2023
** get_files
** File description:
** Get my_ls files
*/

#include "include/my_strings.h"
#include <stdlib.h>
#include <stdio.h>

static int get_files_count(int ac, char *const *const av)
{
    int files_count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            files_count += my_strlen(av[i]);
        }
    }
    return files_count;
}

char **get_files(int ac, char *const *const av)
{
    char **files_path = NULL;
    int files_count = get_files_count(ac, av);
    int files_index = 0;

    files_path = malloc(sizeof(char *) * (files_count + 1));
    if (files_path == NULL)
        return NULL;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            files_path[files_index++] = av[i];
        }
    }
    files_path[files_count] = NULL;
    return files_path;
}
