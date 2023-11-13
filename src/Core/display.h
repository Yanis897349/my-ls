/*
** EPITECH PROJECT, 2023
** display
** File description:
** Basic display behavior of my_ls
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_
    #include "files.h"
    #include "options.h"

typedef void (*display_func_t)(file_t **files_list);

typedef struct display_methods_s {
    display_func_t function;
    int *option_flag;
} display_methods_t;


void display_methods(file_t **files_list, options_t *options);
void sort_before_display(file_t **files_list, options_t *options);

#endif /* !DISPLAY_H_ */
