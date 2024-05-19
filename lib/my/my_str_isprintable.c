/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** my_str_isprintable.c
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 122)
            return (0);
        i++;
    }
    return (1);
}
