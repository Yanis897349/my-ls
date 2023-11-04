/*
** EPITECH PROJECT, 2023
** OPTIONS_H_
** File description:
** Header file for options.c
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
        #define NO_OPTIONS -1

/* FUNCTION PROTOTYPE */
int get_options_string_index(int ac, char *const *const av);
int is_valid_option(char option);
int is_options_string_valid(const char *const options_string);

#endif /* !OPTIONS_H_ */
