/*
** EPITECH PROJECT, 2023
** my_put_octal.c
** File description:
** Put octal
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"

int my_put_octal(unsigned int nb)
{
    char *octal_base = "01234567";
    char *result;

    result = my_putnbr_base(nb, octal_base);
    my_putstr(result);
    return my_strlen(result);
}
