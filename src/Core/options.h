/*
** EPITECH PROJECT, 2023
** OPTIONS_H_
** File description:
** Header file for options.c
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
    #define VALID_OPTIONS "alRdrt"

typedef struct options_s {
    int is_all;
    int is_long;
    int is_recursive;
    int is_dir_only;
    int is_reverse_sort;
    int is_time_sort;
} options_t;

typedef struct options_map_s {
    char option;
    int *option_value;
} options_map_t;


options_t *create_options(int ac, char *const *const av);

#endif /* !OPTIONS_H_ */
