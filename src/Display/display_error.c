/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Display error
*/

#include "include/my_strings.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>

void print_invalid_file(char *filepath)
{
    write(2, "my_ls: cannot access '", 22);
    write(2, filepath, my_strlen(filepath));
    write(2, "': ", 3);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, "\n", 1);
}

void print_invalid_option(char option)
{
    write(2, "my_ls: invalid option -- '", 26);
    write(2, &option, 1);
    write(2, "'\n", 2);
}
