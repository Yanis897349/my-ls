/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Handling symbolic link printing for long listing
*/

#include "Core/files.h"
#include "Helpers/path.h"
#include "lib/my/io/my_io.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void handle_symbolic(file_t *file, char filetype)
{
    char *filename = extract_name_from_path(file->path);
    char *buffer = NULL;
    int size = 0;

    if (filetype != 'l') {
        my_putstr(filename);
        return;
    }
    buffer = malloc(MAX_FILENAME_LENGTH);
    if (buffer == NULL)
        return;
    size = readlink(file->path, buffer, MAX_FILENAME_LENGTH);
    if (size == -1)
        return;
    buffer[size] = '\0';
    my_putstr(filename);
    my_putstr(" -> ");
    my_putstr(buffer);
    free(buffer);
}
