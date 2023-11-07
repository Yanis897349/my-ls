/*
** EPITECH PROJECT, 2023
** manage_directories_stream
** File description:
** Manage directories stream
*/

#ifndef DIRECTORIES_H_
    #define DIRECTORIES_H_
    #include <dirent.h>
    #include <sys/stat.h>

/* STRUCTURE DECLARATION */

typedef struct directory_s {
    char *name;
    DIR *stream;
    struct stat *stat;
} directory_t;

/* FUNCTION PROTOTYPE */

void free_directories(directory_t **directories);
directory_t **open_directories(char **files_path);

#endif /* !DIRECTORIES_H_ */
