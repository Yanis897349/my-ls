/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Main function for my_ls
*/

#include "Core/options.h"
#include <stddef.h>

int main(int ac, char **av)
{
    char *options_string = NULL;
    int options_string_index = get_options_string_index(ac, av);

    if (options_string_index != NO_OPTIONS) {
        options_string = av[options_string_index];
        if (is_options_string_valid(options_string) != 1)
            return 84;
    }
    return 0;
}
