/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Path manager
*/

#ifndef PATH_H_
    #define PATH_H_

char *get_complete_path(char *dir_path, char *filename, int len);
char *extract_name_from_path(char *path);

#endif /* !PATH_H_ */
