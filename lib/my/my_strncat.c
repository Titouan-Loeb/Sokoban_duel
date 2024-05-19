/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** my_strncat.c
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;
    int i = 0;

    len = my_strlen(dest);
    while (i != nb) {
        dest[len] = src[i];
        len++;
        i++;
    }
    dest[len] = '\0';
    return (dest);
}
