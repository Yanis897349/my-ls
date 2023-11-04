/*
** EPITECH PROJECT, 2023
** my_put_hexadecimal.c
** File description:
** Put hexadecimal
*/

#include "strings/my_strings.h"
#include "io/my_io.h"
#include "math/my_math.h"

int my_put_hexadecimal(int nb, int is_upper)
{
    char *hexa_base;
    char *result;

    if (is_upper) {
        hexa_base = "0123456789ABCDEF";
    } else {
        hexa_base = "0123456789abcdef";
    }
    result = my_putnbr_base(nb, hexa_base);
    my_putstr(result);
    return my_strlen(result);
}
