/*
** EPITECH PROJECT, 2023
** manage_directories_stream
** File description:
** Manage directories stream
*/

#ifndef DIRECTORIES_H_
    #define DIRECTORIES_H_
    #include <dirent.h>

/* FUNCTION PROTOTYPE */

void close_directories(DIR **directories);
DIR **open_directories(char **files_path);

#endif /* !DIRECTORIES_H_ */
