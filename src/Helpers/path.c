/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Path manager
*/

#include "include/my_strings.h"
#include <stdlib.h>

char *get_complete_path(char *dir_path, char *filename, int len)
{
    char *path = malloc(len);

    if (path == NULL)
        return NULL;
    my_strcpy(path, dir_path);
    if (path[my_strlen(path) - 1] != '/')
        my_strcat(path, "/");
    my_strcat(path, filename);
    return path;
}

char *extract_name_from_path(char *path)
{
    int i = my_strlen(path) - 1;

    for (; i >= 0 && path[i] != '/'; i--);
    return path + i + 1;
}
