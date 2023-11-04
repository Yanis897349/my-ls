/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_memcpy
*/
#include <stddef.h>

void *my_memcpy(void *dest, void *src, size_t n)
{
    char *dest_bytes = (char *)dest;
    char *src_bytes = (char *)src;
    size_t byte_count = 0;

    while (src_bytes[byte_count] != '\0') {
        dest_bytes[byte_count] = src_bytes[byte_count];
        byte_count++;
    }
    while (byte_count < n) {
        dest_bytes[byte_count] = 0;
        byte_count++;
    }
    return dest_bytes;
}
