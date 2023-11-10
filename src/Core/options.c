/*
** EPITECH PROJECT, 2023
** get_options
** File description:
** Get my_ls options
*/

#include "include/my_strings.h"
#include "options.h"
#include "display_error.h"
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

static int is_option_in_string(char option, char *options_string)
{
    for (int i = 0; options_string[i] != '\0'; i++) {
        if (options_string[i] == option)
            return 1;
    }
    return 0;
}

static int is_options_string_valid(const char *const options_string)
{
    int options_index = 0;

    for (; options_string[options_index] != '\0'; options_index++) {
        if (!is_valid_option(options_string[options_index])) {
            print_invalid_option(options_string[options_index]);
            free((char *)options_string);
            return 84;
        }
    }
    return 1;
}

static char *get_options_string(int ac, char *const *const av)
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

void set_options(options_t *options, char *opt_string)
{
    options_map_t map[] = {
        {'a', &options->is_all},
        {'l', &options->is_long},
        {'R', &options->is_recursive},
        {'d', &options->is_dir_only},
        {'r', &options->is_reverse_sort},
        {'t', &options->is_time_sort},
        {'\0', NULL}
    };

    for (int i = 0; map[i].option != '\0'; i++) {
        *map[i].option_value = is_option_in_string(map[i].option, opt_string);
    }
    if (options->is_dir_only)
        options->is_recursive = 0;
}

options_t *create_options(int ac, char *const *const av)
{
    char *options_string = get_options_string(ac, av);
    options_t *options = NULL;

    if (options_string == NULL)
        return NULL;
    if (is_options_string_valid(options_string) == 84)
        return NULL;
    options = malloc(sizeof(options_t));
    if (options == NULL) {
        free(options_string);
        return NULL;
    }
    set_options(options, options_string);
    free(options_string);
    return options;
}
