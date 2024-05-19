/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;

    len = my_strlen(dest);
    while (src[i] != '\0') {
        dest[len] = src[i];
        len++;
        i++;
    }
    dest[len] = '\0';
    return (dest);
}
