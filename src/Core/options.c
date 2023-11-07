/*
** EPITECH PROJECT, 2023
** get_options
** File description:
** Get my_ls options
*/

#include "options.h"
#include "include/my_strings.h"
#include <stdlib.h>

static int is_valid_option(char option)
{
    const char *const VALID_OPTIONS = "alRdrt";

    for (int i = 0; VALID_OPTIONS[i]; i++)
        if (option == VALID_OPTIONS[i])
            return 1;
    return 0;
}

static int get_options_count(int ac, char *const *const av)
{
    int options_count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            options_count += my_strlen(av[i] - 1);
        }
    }
    return options_count;
}

int is_options_string_valid(const char *const options_string)
{
    for (int options_index = 1; options_string[options_index]; options_index++)
        if (!is_valid_option(options_string[options_index]))
            return options_index;
    return 1;
}

char *get_options(int ac, char *const *const av)
{
    char *options_string = NULL;
    int options_count = get_options_count(ac, av);

    options_string = malloc(options_count + 1);
    if (options_string == NULL)
        return NULL;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            my_strcat(options_string, av[i] + 1);
        }
    }
    return options_string;
}
