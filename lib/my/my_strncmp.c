/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return (0);
    while ((i < n - 1) && (s1[i] == s2[i]) && (s2[i] != '\0')
            && (s1[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}
