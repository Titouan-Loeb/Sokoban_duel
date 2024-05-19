/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_strmcpy
*/

#include "my.h"

char *my_strmcpy(char const *str)
{
    char *cpy = NULL;
    int i = 0;

    if (str == NULL)
        return (NULL);
    cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (cpy == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        cpy[i] = str[i];
    cpy[i] = '\0';
    return (cpy);
}