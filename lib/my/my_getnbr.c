/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long n = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + (str[i] - 48);
        i++;
    }
    if (((n * neg) > 2147483647) || ((n * neg) < -2147483648))
        return (0);
    else
        return (n * neg);
}
