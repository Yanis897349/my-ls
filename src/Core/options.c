/*
** EPITECH PROJECT, 2023
** get_options
** File description:
** Get my_ls options
*/

#include "include/my_strings.h"
#include "options.h"
#include <stdlib.h>
#include <unistd.h>

static int is_valid_option(char option)
{
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

static void print_invalid_option(char option)
{
    write(2, "my_ls: invalid option -- '", 27);
    write(2, &option, 1);
    write(2, "'\n", 2);
}

int is_options_string_valid(const char *const options_string)
{
    int options_index = 0;

    for (; options_string[options_index] != '\0'; options_index++) {
        if (!is_valid_option(options_string[options_index])) {
            print_invalid_option(options_string[options_index]);
            return 84;
        }
    }
    return 1;
}

char *get_options(int ac, char *const *const av)
{
    char *options_string = NULL;
    int options_count = get_options_count(ac, av);

    options_string = malloc(options_count + 1);
    if (options_string == NULL)
        return NULL;
    my_memset(options_string, 0, options_count + 1);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            my_strcat(options_string, av[i] + 1);
        }
    }
    return options_string;
}
