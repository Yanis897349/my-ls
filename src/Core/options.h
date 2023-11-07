/*
** EPITECH PROJECT, 2023
** OPTIONS_H_
** File description:
** Header file for options.c
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
    #define VALID_OPTIONS "alRdrt"

/* FUNCTION PROTOTYPE */
int is_options_string_valid(const char *const options_string);
char *get_options(int ac, char *const *const av);

#endif /* !OPTIONS_H_ */
