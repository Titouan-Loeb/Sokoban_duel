/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** my_isneg.c
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    my_putchar('\n');

    return (0);
}
