/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls main file
*/

#include "Core/options.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char *options_string = get_options(ac, av);

    if (options_string == NULL)
        return 84;
    free(options_string);
    return 0;
}
