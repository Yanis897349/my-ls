/*
** EPITECH PROJECT, 2023
** get_options
** File description:
** Get my_ls options
*/

#include "options.h"

int get_options_string_index(int ac, char *const *const av)
{
    int options_string_index = 1;

    for (; options_string_index < ac; options_string_index++) {
        if (av[options_string_index][0] == '-')
            return options_string_index;
    }
    return NO_OPTIONS;
}

int is_valid_option(char option)
{
    const char *const VALID_OPTIONS = "alRdrt";

    for (int i = 0; VALID_OPTIONS[i]; i++)
        if (option == VALID_OPTIONS[i])
            return 1;
    return 0;
}

int is_options_string_valid(const char *const options_string)
{
    for (int i = 1; options_string[i]; i++)
        if (!is_valid_option(options_string[i]))
            return i;
    return 1;
}
