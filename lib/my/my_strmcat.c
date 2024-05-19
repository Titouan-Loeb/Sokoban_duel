/*
** EPITECH PROJECT, 2020
** my_strmcat.c
** File description:
** my_strmcat.c
*/

#include "my.h"

char *my_strmcat(char *dest, char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[j + i] = src[j];
        j++;
    }
    str[j + i] = '\0';
    return (str);
}
