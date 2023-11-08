/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Managing files in my ls
*/

#ifndef FILES_H_
    #define FILES_H_
    #include <sys/stat.h>

typedef struct file_s {
    char *path;
    int is_directory;
    struct stat *stat;
} file_t;

void free_files_list(file_t **files_list);
file_t **get_files_list(char **files_path);

#endif /* !FILES_H_ */
