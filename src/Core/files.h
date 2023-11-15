/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Managing files in my ls
*/

#ifndef FILES_H_
    #define FILES_H_
    #define MAX_FILENAME_LENGTH 256
    #include "options.h"
    #include <sys/stat.h>

typedef struct file_s {
    char *path;
    int is_directory;
    struct file_s **content;
    struct stat *stat;
} file_t;

char get_filetype(file_t *file);
file_t **get_files_list(char **files_path, options_t *options);

#endif /* !FILES_H_ */
