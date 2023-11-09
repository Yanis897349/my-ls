/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Path manager
*/

#include "include/my_strings.h"

char *extract_name_from_path(char *path)
{
    int i = my_strlen(path) - 1;

    for (; i >= 0 && path[i] != '/'; i--);
    return path + i + 1;
}
