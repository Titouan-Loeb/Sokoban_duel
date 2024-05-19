/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** my_is_prime.c
*/

#include "my.h"

int my_is_prime(int nb)
{
    int   a = 2;

    if (nb <= 0 || nb == 1)
        return (0);
    while (a < nb) {
        if (nb % a == 0)
            return (0);
        a++;
    }
    return (1);
}
