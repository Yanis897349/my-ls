/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Manage directory
*/

#ifndef DIRECTORY_H_
    #define DIRECTORY_H_
    #include "files.h"

int is_directory_empty(char *dir_name, file_t **dir);
int set_directory_content(file_t **dir, options_t *options);

#endif /* !DIRECTORY_H_ */
